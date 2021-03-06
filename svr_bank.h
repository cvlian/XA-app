/* svr_bank.h
 *
 * 
 */

#include <stdio.h>
#include <sqlca.h>
#include <stdlib.h>
#include <string.h>
#include <lib/atmi.h>
#include <lib/fbuf.h>
#include "fdl/bank_fdl.h"

#define SQLOK       0
#define SQLDUP      1
#define SQLNOTFOUND 1403

#define MAXLEN 		2048

#define COMMIT          1
#define ROLLBACK        2
#define BANKA_DBA_NAME "sys"
#define BANKB_DBA_NAME "sys"
#define BANKA_DBA_PWD  "aaaa"
#define BANKB_DBA_PWD  "bbbb"

#define OPENINFO1 "TIBERO_XA:user=sys, pwd=aaaa, sestm=60, db=bankA"
#define OPENINFO2 "TIBERO_XA:user=sys, pwd=bbbb, sestm=60, db=bankB"

extern struct xa_switch_t tbxasw;
