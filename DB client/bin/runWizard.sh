#!/bin/sh
#
#   Run wizard
#   Usage: runWizard.sh [-m] [cmd/gui]
#
# SVR_HOME must be set
. base_env.sh
if [ -z "$svr_home" ]
then
    echo "Environment variable $svr_home_name must be set." >&2
    exit 1
fi

clientlib=$svr_home/client/lib/jar
jdbc=$clientlib/tibero6-jdbc.jar
logger=$clientlib/msllogger-14.jar
swt=$clientlib/swt_linux32.jar
wizard_gui=$clientlib/wizard_gui.jar
wizard_cmd=$clientlib/wizard_cmd.jar

mainclass_gui=com.m.wizard.gui.main.WizardGuiMain
mainclass_cmd=com.m.wizard.cmd.main.WizardCmdMain

print_usage() {
    usage="Usage: runWizard.sh [-m] [cmd/gui]"
    echo $usage
}

choose_mode() {
    if [ "$1" = "cmd" ]; then
        shift
        java -classpath $jdbc:$logger:$wizard_cmd: $mainclass_cmd $*
    elif [ "$1" = "gui" ]; then
        shift
        java -classpath $jdbc:$logger:$wizard_gui:$swt: $mainclass_gui $*
    else
        print_usage
    fi
}


#Check Operation System's bit information
if [ "$(getconf LONG_BIT | grep '64')" != "" ]; then
    swt=$clientlib/swt_linux64.jar
fi

while [ -n "$1" ]; do
    if [ "$1" = "-m" ]; then
        shift
        choose_mode $*
        exit
    else
        print_usage
        exit
    fi
done
