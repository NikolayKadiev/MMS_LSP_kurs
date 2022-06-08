#include "calc_sum.h"

void *sum_calc(struct arg_struct *arguments){
	arguments->c = arguments->a + arguments->b;
}
