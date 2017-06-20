#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	while(*format) {
		if(*format == '%'){
			format++;
			switch(*format){
			case 'd':{
				int c = getc(fp);
				double *Double=va_arg(list, double*);
				while(isspace(c)){
					c=getc(fp);
				}
				unsigned int num= 0;
				while(isdight(c)){
					num = num * 10 + c -'0';
					c=getc(fp);
				}
				*Double = num;
				break;
			}
			case 'c':{
				char *ch = va_arg(list,char*);
				char c=getc(fp);
				*ch = c;
				break;
			}
			case ' ':
				break;
			}
		}
		else
			format++;
	}
	va_end(list);
}
