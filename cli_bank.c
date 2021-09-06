/* cli_bank.c
 *
 * 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <usrinc/atmi.h>
#include <usrinc/fbuf.h>
#include "../fdl/bank_fdl.h"

struct option options[] =
{
	{"user ID",  required_argument, 0, 'u'},
	{"bank name",  required_argument, 0, 'b'},
	{0, 0, 0, 0}
};

void print_usage()
{
	printf("\nUsage: cli -u [user ID] -b [bank name]\n"
	       "--------------------------------------\n\n");
	exit(0);
}

void send_call(char* func, FBUF* sndbuf)
{
	FBUF *rcvbuf;
	long rcvlen;
	char ret[1024];

	if ((rcvbuf = (FBUF *)tpalloc("FIELD", NULL, 0)) == NULL){
		printf("recvbuf alloc failed !\n");
		tpfree((char *)sndbuf);
		tpend();
		exit(1);
	}

	if (tpcall(func, (char *)sndbuf, 0, (char **)&rcvbuf, &rcvlen, 0) == -1){
		printf("Can't send request to service %s \n[tperrno(%d) : %s]\n", func, tperrno, tpstrerror(tperrno));
	}

	fbget(rcvbuf, MESSAGE, ret, 0);
	printf("%s\n", ret);

	tpfree((char *)rcvbuf);
}

main(int argc, char *argv[])
{
	FBUF *sndbuf;
	int	ret;

	char user_id[16] = "";
	char bank_name[16] = "";

	int optionIndex = 0;
	char opt = 0;

	while((opt = getopt_long (argc, argv, "u:b:h", options, &optionIndex)) != -1)
	{
		switch (opt)
		{
			case 0:
				break;
			case 'u':
				strncpy(user_id, optarg, sizeof(user_id));
				user_id[sizeof(user_id) - 1] = '\0';
				break;
			case 'b':
				strncpy(bank_name, optarg, sizeof(bank_name));
				bank_name[sizeof(bank_name) - 1] = '\0';
				break;
			case 'h':
				print_usage();
				break;
			default:
				print_usage();
		}
	}

	if (strlen(user_id) == 0 || strlen(bank_name) == 0)
	{
		printf( "Provide your ID and bank name\n" );
		print_usage();
	}

	if ( (ret = tmaxreadenv( "tmax.env","TMAX" )) == -1 ){
		printf( "tmax read env failed\n" );
		exit(1);
	}

	if (tpstart((TPSTART_T *)NULL) == -1){
		printf("tpstart failed\n");
		exit(1);
	}

	if ((sndbuf = (FBUF *)tpalloc("FIELD", NULL, 0)) == NULL){
		printf("sendbuf alloc failed !\n");
		tpend();
		exit(1);
	}

	int req_type;
	int amount;
	char rec_id[16];
	char rec_bank[16];
	char date[64];

	while (1)
	{
		printf("\nChoose request type from the following list\n"
		         "-------------------------------------------\n\n"
		         "1: Deposit     2: Withdraw      3: Transfer\n"
				 "4: Check balance       5. Check history    \n"
		         "-------------------------------------------\n\n"
		         "Enter (1 ~ 5): ");

		scanf("%d", &req_type);

		fbput(sndbuf, MY_ID, user_id, 0);
		fbput(sndbuf, MY_BANK, bank_name, 0);

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		sprintf(date, "%04d%02d%02d%02d%02d%02d", 
				tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
       			tm.tm_hour, tm.tm_min, tm.tm_sec);

		fbput(sndbuf, DATE, date, 0);		   

		switch(req_type)
		{
			case 1:
				printf("Enter the amount to be deposited: "); scanf("%d", &amount);
				fbput(sndbuf, AMOUNT, (char *)&amount, 0);

				send_call("DEPOSIT", sndbuf);
				break;
			case 2:

				printf("Enter the amount to be withdrawn: "); scanf("%d", &amount);
				fbput(sndbuf, AMOUNT, (char *)&amount, 0);

				send_call("WITHDRAW", sndbuf);
				break;
			case 3:
				printf("Enter recipient ID: "); scanf("%s", rec_id);
				printf("Enter recipient's bank name: "); scanf("%s", rec_bank);
				printf("Enter the amount to be transferred: "); scanf("%d", &amount);
				fbput(sndbuf, REC_ID, rec_id, 0);
				fbput(sndbuf, AMOUNT, (char *)&amount, 0);
				fbput(sndbuf, REC_BANK, rec_bank, 0);

				send_call("TRANSFER", sndbuf);
				break;
			case 4:
				send_call("BALANCE", sndbuf);
				break;
			case 5:
				send_call("HISTORY", sndbuf);
				break;
			default:
				printf("You chose invalid number!\n");
				continue;
		}

		fbinit(sndbuf,0);
	}

	tpfree((char *)sndbuf);
	tpend();
}
