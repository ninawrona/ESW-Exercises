#include <stdio.h>
#include "calc.h"
int main(void){
	setbuf(stdout, NULL);
	printf("I love math:  3+4 =  %d ! \n", calc_add(3,4));
	return 0;
}