#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result =0;
	
	int (*addP) (int,int);
	int (*minusP) (int,int);
	int (*mulP) (int,int);
	double (*divP) (int, int);

	addP=add;
	minusP=minus;
	mulP=mul;
	divP=div;


	fp = fopen("read.txt","r");
	if(fp!=NULL){
		my_fscanf(fp, "%d", &line);
	
		for(int i=1; i<line; i++) {
			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				result = addP(operand1, operand2);
				break;
				case '-':
				result = minusP(operand1, operand2);
				break;
				case '*':
				result = mulP(operand1, operand2);
				break;
				case '/':
				result = divP(operand1, operand2);
				break;
			}		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

