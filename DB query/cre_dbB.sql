create database "bankB"
user sys identified by bbbb
maxinstances 8 
maxdatafiles 512 
character set MSWIN949
national character set UTF16 
logfile 
	group 0 'bk-log004.log' size 100M, 
	group 1 'bk-log005.log' size 100M, 
	group 2 'bk-log006.log' size 100M 
maxloggroups 255 
maxlogmembers 8 
noarchivelog 
	datafile 'system002.dtf' size 100M autoextend on next 100M maxsize unlimited 
	default temporary tablespace TEMP 
		tempfile 'temp002.dtf' size 100M autoextend on next 100M maxsize unlimited 
		extent management local autoallocate 
	undo tablespace UNDO 
		datafile 'undo002.dtf' size 100M autoextend on next 100M maxsize unlimited 
	extent management local autoallocate; 
