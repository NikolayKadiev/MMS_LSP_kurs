#include <stdio.h> 
#include "calc_sum.h"

int main (void){
	float a=0.0 , b=0.0;
	printf("insert a= ");
        scanf("%f",&a);
        printf("insert b= ");
        scanf("%f",&b);
	printf("a + b = %f \n",sum_calc(a, b));
}	
