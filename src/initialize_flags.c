#include "../inc/ft_ls.h"

void	initialize_flags(t_flags *flags){
	flags->l = 0;
	flags->r = 0;
	flags->recur = 0;
	flags->t = 0;
	flags->a = 0;
	flags->color = 0;
	flags->u = 0;
}	
