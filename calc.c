#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result;
	double (*funcp)(int, int);
	double (*funcp2)(double, double);
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = add(operand1, operand2);
				funcp = add;
				funcp(operand1, operand2);
				break;
				case '-':
				result = minus(operand1, operand2);
				funcp = minus;
				funcp(operand1, operand2);
				break;
				case '*':
				result = mul(operand1, operand2);
				funcp = mul;
				funcp(operand1, operand2);
				break;
				case '/':
				result = div((double)operand1, (double)operand2);
				funcp2 = div;
				funcp2(operand1, operand2);
				break;
			}	
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

