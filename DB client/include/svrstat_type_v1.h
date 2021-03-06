#ifndef _TBSTAT_TYPE_V1_H
#define _TBSTAT_TYPE_V1_H

typedef enum sess_status_e {
    SESS_IDLE,
    SESS_ASSIGNED_FOR_RECOVERY,
    SESS_ASSIGNED,
    SESS_ACTIVE,
    SESS_RUNNING,
    SESS_ROLLING_BACK,
    SESS_RECOVERING,
    SESS_CLOSING
} sess_status_t;

typedef enum thr_type_e {
    THR_TYPE_MTHR,
    THR_TYPE_CTHR,
    THR_TYPE_WTHR,

    THR_TYPE_LGWR,
    THR_TYPE_LARC,
    THR_TYPE_CKPT,
#ifdef _NANOBASE
    THR_TYPE_NBGC,
#endif
    THR_TYPE_BLKW,
    THR_TYPE_BLKWS,
#ifdef _TAC
    THR_TYPE_ACSD_CTHR,
    THR_TYPE_ACSD_NMGR,
    THR_TYPE_ACSD_DIAG,
    THR_TYPE_ACSD_RCOW,
    THR_TYPE_ACSD_WLGC,
    THR_TYPE_ACSD_WATH,
    THR_TYPE_ACSD_RCOC,
    THR_TYPE_ACSD_CLGC,
    THR_TYPE_ACSD_CATH,
    THR_TYPE_ACSD_DSPC,
    THR_TYPE_ACSD_SNDR,
    THR_TYPE_ACSD_WTHR,
#endif
    THR_TYPE_LNW,
    THR_TYPE_NTFC,
    THR_TYPE_NTFS,
    THR_TYPE_QMON,
    THR_TYPE_DBWR_CTHR,
    THR_TYPE_DBWR_LGWR,
    THR_TYPE_DBWR_LARC,
    THR_TYPE_DBWR_CKPT,
    THR_TYPE_DBWR_DBWR,
    THR_TYPE_RECO_CTHR,
    THR_TYPE_RECO_WTHR,
    THR_TYPE_ASBC,
    THR_TYPE_ASBW,
    THR_TYPE_ASDM,
    THR_TYPE_SSHB,
    THR_TYPE_AGNT_CTHR,
    THR_TYPE_AGNT_WTHR,
    THR_TYPE_SSVR_MTHR,
    THR_TYPE_SSVR_ITHR,
    THR_TYPE_SSVR_WTHR,
    THR_TYPE_SSVR_FTHR,
    THR_TYPE_SSVR_DTHR,
    THR_TYPE_SSVR_JTHR
} thr_type_t;

typedef enum thr_stat_e {
    THR_STAT_INVALID,
    THR_STAT_NEW,
    THR_STAT_IDLE,
    THR_STAT_RUNNING,
    THR_STAT_WAITING,
    THR_STAT_RECV_WAITING,
    THR_STAT_STOP_BY_MTHR,
    THR_STAT_DEAD,
} thr_stat_t;

typedef struct list_link_s list_link_t;
typedef struct list_link_s list_t;
struct list_link_s {
    list_link_t *next, *prev;
};


#endif
