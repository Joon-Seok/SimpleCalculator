#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result;
	int (*addfp)(int, int);
	int (*minusfp)(int, int);
	int (*mulfp)(int, int);
	double (*divfp)(double, double);
	addfp = add;
	minusfp = minus;
	mulfp = mul;
	divfp = div;
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = addfp(operand1, operand2);
				break;
				case '-':
				result = minusfp(operand1, operand2);
				break;
				case '*':
				result = mulfp(operand1, operand2);
				break;
				case '/':
				result = divfp((double)operand1, (double)operand2);
				break;
			}		
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

