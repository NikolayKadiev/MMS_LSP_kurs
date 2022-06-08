#include <stdio.h>
#include <pthread.h>

#include "calc_sum.h"

int main (void){
	struct arg_struct args;
	pthread_t thread;
	printf("insert a= ");
        scanf("%f",&args.a);
        printf("insert b= ");
        scanf("%f",&args.b);
        pthread_create(&thread, NULL, &sum_calc, (void*) &args);
        pthread_join(thread, NULL);
        printf("a + b = %.3f \n", args.c); 
}	
