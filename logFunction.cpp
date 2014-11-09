#define _CRT_SECURE_NO_WARNINGS
#include <cstdio> 
#include <time.h>
void add_log (char * format, ...) 
{
HANDLE file handle; 
DWORD dwReadBytes; 
char buffer [2048]; 
write char buffer [2048]; 
va_list args; va_start (args, format); 
vsprintf (buffer, format, args); 
file handle = CreateFile (L "Log.txt" GENERIC_WRITE, 0, 0, OPEN_ALWAYS, 0, 0); 
SetFilePointer (file handle, 0, 0, FILE_END); 
char date [18]; 
_strdate (date); date [8] = ''; 
_strtime (date + 9); sprintf_s (write buffer, in 2048, "Log Added (% s):% s \ r \ n", date, buffer);
WriteFile (file handle, write buffer, strlen (buffer write), & dwReadBytes, 0); 
CloseHandle (file handle); 
}

