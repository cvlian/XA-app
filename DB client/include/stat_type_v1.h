/**
 * @file    stat_type_v1.h
 * @brief   instance stat API & library : stat type
 *
 * @author  jongtack, chhwang
 * @version $Id: stat_type_v1.h 99489 2015-03-09 03:29:26Z jeongho $
 */

#ifndef _STAT_TYPE_V1_H
#define _STAT_TYPE_V1_H


/*{{{ _vt_sqltext ------------------------------------------------------------*/

#define VTM_SQLTEXT_LEN 64
#define VTM_SQLTEXT_LEN2 30000

typedef enum pp_sqltext_command_type_e {
    PP_SQLTEXT_COMMAND_TYPE_NONE,
    PP_SQLTEXT_COMMAND_TYPE_SELECT,
    PP_SQLTEXT_COMMAND_TYPE_INSERT,
    PP_SQLTEXT_COMMAND_TYPE_UPDATE,
    PP_SQLTEXT_COMMAND_TYPE_DELETE,
    PP_SQLTEXT_COMMAND_TYPE_MERGE,
    PP_SQLTEXT_COMMAND_TYPE_CALL,
    PP_SQLTEXT_COMMAND_TYPE_MAX
} pp_sqltext_command_type_t;

/*------------------------------------------------------------ _vt_sqltext }}}*/

#ifndef _TB_DATE_T
#define _TB_DATE_T
typedef struct tb_date_s tb_date_t;
#endif

/* date type ����ü */
struct tb_date_s {
    unsigned char   century;
    unsigned char   year;
    unsigned char   month;
    unsigned char   day;

    unsigned char   hour;
    unsigned char   minute;
    unsigned char   second;
    unsigned char   dummy;
};

#endif /* no _STAT_TYPE_V1_H */
