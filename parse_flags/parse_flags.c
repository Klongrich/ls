#include "../inc/ft_ls.h"

int 	parse_flags(char *str, t_flags *flags){
	int i;

	i = 1;
	while(str[i]) {
		if (!set_flag_value(str[i], flags))
			return(0);
		i++;
	}
	return (1);
}
