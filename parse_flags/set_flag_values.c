#include "ft_ls.h"

int	print_invalid_flag_error() {
	printf("error, invalid flags usage: [-lratR]\n");
	return(0);
}

int	set_flag_value(char c, t_flags *flags) {

	if (c == 'l')
		flags->l = 1;
	else if (c == 'r')
		flags->r = 1;
	else if (c == 'R')
		flags->recur = 1;
	else if (c == 't')
		flags->t = 1;
	else if (c == 'a')
		flags->a = 1;
	else if (c == 'G')
		flags->color = 1;
	else if (c == 'u')
		flags->u = 1;
	else if (c  == 'f')
		flags->f = 1;
	else if (c == 'd')
		flags->d = 1;
	else
		return(print_invalid_flag_error());
	return (1);

}
