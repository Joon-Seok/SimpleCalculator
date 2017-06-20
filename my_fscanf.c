#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void my_fscanf(FILE *fp, const char *format, ...) {
	va_list list;
	va_start(list, format);
	while(*format) {
		if(*format == '%'){
			format++;
			switch(*format){
			case 'd':{
				int c = getc(fp);
				int *s=va_arg(list, int*);
				
				while(isspace(c)){
				
				}
				unsigned int num= 0;
				while(isdight(c)){
					*s = num * 10 + c -'0';
					c=getc(fp);
				}
				while (isspace(c)){}
				format++;
				ungetc(c,fp);
				break;
			}
			case 'c':{
				char *ch = va_arg(list,char*);
				char c=getc(fp);
				while (isspace(c)){}
				*ch = c;
				format++;
				break;
			}
			case 's':{
				char *sp = va_arg(list, char*);
				int s = 1;
				while(isspace(c=getc(fp))){}
				
				while (!isspace(c=getc(fp))){
					sp[s]=c;
					s++;
				}
				sp[s]=0;
				format++;
				ungetc(c,fp);
				break;
			}
			case 'f':{
				double *f_p=va_arg(list, double*);
				double di = 0.1;
				double c=getc(fp);
				while(isspace(c)){}
				*f_p = 0;
				while (isdigit(c)){
					*f_p= *f_p * 10 + c - '0';
					c= getc(fp);
				}
				if (c == '.'){
					c = getc(fp);
					while(isdigit(c)){
						*f_p=*f_p + (c - '0') * di;
						di = di* 0.1;
						c=getc(fp);
					}
				}
				format++;
				ungetc(c,fp);
				break;
		}
		else{
			int c = getc(fp);
			if(*format==c)
				format++;
		}
	}
	va_end(list);
}
