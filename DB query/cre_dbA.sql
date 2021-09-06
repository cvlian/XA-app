create database "bankA"
user sys identified by aaaa
maxinstances 8 
maxdatafiles 512 
character set MSWIN949
national character set UTF16 
logfile 
	group 0 'bk-log001.log' size 100M, 
	group 1 'bk-log002.log' size 100M, 
	group 2 'bk-log003.log' size 100M 
maxloggroups 255 
maxlogmembers 8 
noarchivelog 
	datafile 'system001.dtf' size 100M autoextend on next 100M maxsize unlimited 
	default temporary tablespace TEMP 
		tempfile 'temp001.dtf' size 100M autoextend on next 100M maxsize unlimited 
		extent management local autoallocate 
	undo tablespace UNDO 
		datafile 'undo001.dtf' size 100M autoextend on next 100M maxsize unlimited 
	extent management local autoallocate; 
