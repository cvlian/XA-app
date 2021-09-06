###############################################################
#                                                             #
#           Configuration File for Banking System             #
#         =========================================           #
#                                                             #
###############################################################


*DOMAIN
banker          SHMKEY = 79990, MINCLH = 1, MAXCLH = 3,
                TPORTNO = 8888, BLOCKTIME = 30,
		        MAXCPC = 150


*NODE
localhost       TMAXDIR = "/home/jiwon/tmax",
                APPDIR  = "/home/jiwon/tmax/appbin",
                PATHDIR = "/home/jiwon/tmax/path",
                TLOGDIR = "/home/jiwon/tmax/log/tlog",
                ULOGDIR = "/home/jiwon/tmax/log/ulog",
                SLOGDIR = "/home/jiwon/tmax/log/slog"
#               SQKEY = 78550, SQSIZE = 8192, SQMAX = 1024, SQKEYMAX = 64, SQTIMEOUT = 30


*SVRGROUP
svg_bank1       NODENAME = "localhost", DBNAME = TIBERO,
                OPENINFO = "TIBERO_XA:user=sys, pwd=aaaa, sestm=60, db=bankA",
                TMSNAME =tms_tbr,
                SVGTYPE = STMAX

svg_bank2       NODENAME = "localhost", DBNAME = TIBERO,
                OPENINFO = "TIBERO_XA:user=sys, pwd=bbbb, sestm=60, db=bankB",
                TMSNAME =tms_tbr,
                SVGTYPE = STMAX

svgm		    NODENAME = "localhost",
		        SVGLIST = "svg_bank1,svg_bank2",
		        SVGTYPE = MTMAX

*SERVER
svr_bank        SVGNAME = svgm, MIN = 10

*SERVICE
DEPOSIT         SVRNAME = svr_bank
WITHDRAW        SVRNAME = svr_bank
TRANSFER        SVRNAME = svr_bank
BALANCE         SVRNAME = svr_bank