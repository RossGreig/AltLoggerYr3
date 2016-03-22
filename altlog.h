#include <stdio.h>
#include <stdlib.h>

#ifndef __altlog_h__
#define __altlog_h__

typedef enum {
	
	debuginfo = 0, 
	performancedata = 1, 
	error = 2,
	positions = 3

} loglevel;
loglevel priority;


void altlogger(loglevel prioritylevel, const char* message, ...);
void altloggerconsole(char* message);
void openfile();
void closefile();
#endif