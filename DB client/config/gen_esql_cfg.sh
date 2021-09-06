#!/bin/sh
#
#   ESQL
#   generator for configuration file
#

# SVR_HOME must be set
. base_env.sh
if [ -z "$svr_home" ]
then
    echo "Environment variable $svr_home_name must be set." >&2
    exit 1
fi

if [ ! -d $svr_home/client/config ]; then
    echo "Cannot find directory $svr_home/client/config." >&2
    exit 1
fi

if [ -z "$1" ]; then 
    prefix=$default_prefix
else
    prefix=$1
fi

ESQL_c_seq_file=$svr_home/client/config/."$prefix"c_file_id
ESQL_cbl_seq_file=$svr_home/client/config/."$prefix"co_file_id

if [ ! -f "$ESQL_c_seq_file" ]; then

    cat >> $ESQL_c_seq_file <<EOF
EOF

fi

# rw-rw-rw-
chmod 666 $ESQL_c_seq_file


if [ ! -f "$ESQL_cbl_seq_file" ]; then

    cat >> $ESQL_cbl_seq_file <<EOF
EOF

fi

# rw-rw-rw-
chmod 666 $ESQL_cbl_seq_file

echo "Done." >&2

