#include "../inc/ft_ls.h"

void print_flags(t_flags *flags){
	printf("l: %d\n", flags->l);
	printf("a: %d\n", flags->a);
	printf("r: %d\n", flags->r);
	printf("R: %d\n", flags->recur);
	printf("t: %d\n", flags->t);

}
