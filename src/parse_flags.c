#include "../inc/ft_ls.h"

int 	parse_flags(char *str, t_flags *flags){
	int i;

	i = 1;
	while(str[i]) {
		if (str[i] == 'l')
			flags->l = 1;
		else if (str[i] == 'r')
			flags->r = 1;
		else if (str[i] == 'R')
			flags->recur = 1;
		else if (str[i] == 't')
			flags->t = 1;
		else if (str[i] == 'a')
			flags->a = 1;
		else
			return(0);
		i++;
	}
	return (1);
}

void	initialize_flags(t_flags *flags){
	flags->l = 0;
	flags->r = 0;
	flags->recur = 0;
	flags->t = 0;
	flags->a = 0;
}	


void print_flags(t_flags *flags){
	printf("l: %d\n", flags->l);
	printf("a: %d\n", flags->a);
	printf("r: %d\n", flags->r);
	printf("R: %d\n", flags->recur);
	printf("t: %d\n", flags->t);

}
