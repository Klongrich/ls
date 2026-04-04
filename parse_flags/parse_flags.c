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
