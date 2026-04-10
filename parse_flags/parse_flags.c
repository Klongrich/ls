#include "../inc/ft_ls.h"

int	print_invalid_flag_error() {
	printf("error, invalid flags usage: [-lratR]\n");
	return(0);
}

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
		else if (str[i] == 'G')
			flags->color = 1;
		else if (str[i] == 'u')
			flags->u = 1;
		else if (str[i] == 'f')
			flags->f = 1;
		else
			return(print_invalid_flag_error());
		i++;
	}
	return (1);
}
