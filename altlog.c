// How to use
// Before logging any data call openfile and closefile in the main ensuring the file is open when needed
// Record data by calling altlogger then the prioritylevel and finally the data you wish to gather, for instance to gather player positions during a game you might position this code in the appropriate location:
// altlogger(positions, "X = %f, Y = %f, Z = %f \n", from->origin[0], from->origin[1], from->origin[2]);

#include "altlog.h"
#include "stdarg.h"
#include <time.h>
//Setting file
FILE *f = NULL;

void openfile()
{
#ifdef _DEBUG

	//Call this before you start logging
	f = fopen("altlog.txt", "a"); //Opens/creates file named altlog.txt
	//TimeStamp every time the file is opened
	time_t mytime;
	mytime = time(NULL);
	fprintf(f, "Log opened at %s", ctime(&mytime));
	
	//Error handling for file opening
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
#endif
}

void altlogger(loglevel prioritylevel, const char* message, ...)
{	
#ifdef _DEBUG
	va_list args; //stores arguments for a variadic function in a list
	va_start(args, message); //starts variadic arguments

	if (prioritylevel >= priority)
	{
		//Break file writing down into multiple methods based on priority level allowing users to call multiple levels of logging.
		if (prioritylevel == debuginfo)
		{
			/* print some text */
			const char *text = "";
			fprintf(f, "Debug Info: %s\n", text);

			 /*printing single chatacters*/
			char c = 'A';
			vfprintf(f, message, args);
		}
		else 	if (prioritylevel == performancedata)
		{
			/* print some text */
			const char *text = "";
			fprintf(f, "Performance Data: %s\n", text);

			/* printing single chatacters */
			char c = 'A';
			vfprintf(f, message, args);
		}
		else	if (prioritylevel == error)
		{
			/* print some text */
			const char *text = "";
			fprintf(f, "Error: %s\n", text);

			/* printing single chatacters */
			char c = 'A';
			vfprintf(f, message, args);
		}
		else	if (prioritylevel == positions)
		{

			/* printing single chatacters */
			char c = 'A';
			vfprintf(f, message, args);
			vprintf(message, args);
		}
	}

	va_end(args); //ends variadic arguments
#endif
}

void closefile()
{
	//Call this when you finish logging to ensure the files closes correctly!
#ifdef _DEBUG
	fclose(f);
#endif
}

void altloggerconsole(char* message)
{
	//Use this if you wish to print to console
#ifdef _DEBUG
	printf(message);	//Print to console
#endif
}