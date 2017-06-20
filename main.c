#include <stdio.h>
#include <string.h>
#include "my_fscanf.h"

int main(){
	fp = fopen("points.txt","r");
	char type[10];
	double x,y;
	int line;

	if(fp!=NULL){
		my_fscanf(fp, "%d", &line);
		for(int i =0; i < line; i++){
			my_fscanf(fp, "%s (%f,%f)",type, &x, &y);
			if(strcmp(type, "point") == 0) {
				printf("X: %f:, Y: %f\n", x, y);
			}
		}
	}
	return 0;
}
