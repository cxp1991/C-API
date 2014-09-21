/**
* @author: caoxuanphong.khtn@gmail.com
* @date: 21/09/2014
* @file: ins_debug.c
*/

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <stdlib.h>

void ins_assert(int condition, const char *format, ...)
{
	if (!condition) {
		va_list args;
		char tmp[100] = { 0 };

		va_start(args, format);
		sprintf(tmp, "[%s, line %d] Assertion message = \"%s\" !!!\n", __FILE__, __LINE__, format);
		vprintf(tmp, args);
		va_end(args);
		exit(0);
	}
}

void ins_log (const char *format, ...)
{
    va_list args;
    char tmp[100] = { 0 };
    
    va_start(args, format);
    sprintf(tmp, "[%s, line %d] %s \n", __FILE__, __LINE__, format);
    vprintf(tmp, args);
    va_end(args);
}

//int main()
//{
//    ins_log("hello %d", 10);
//    ins_assert(0, "hello %d", 10);
//    return 1;
//}