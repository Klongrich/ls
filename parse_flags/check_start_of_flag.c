#include "../inc/ft_ls.h"

int	check_start_of_flag(char *str) {
	if (str[0] == '-') {
		if(!str[1])
			return(0);
		else
			return(1);
	} else {
		return(0);
	}
}
