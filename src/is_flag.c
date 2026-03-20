#include "../inc/ft_ls.h"

int	is_flag(char *str) {
	int i;

	i = 0;
	if (str[i] == '-') {
		i++;
		if(!str[i])
			return(0);
	} else {
		return(0);
	}

	while(str[i]) {
		if (str[i] == 'a')
			i++;
		else if (str[i] == 't')
			i++;
		else if (str[i] == 'l')
			i++;
		else if (str[i] == 'r')
			i++;
		else if (str[i] == 'R')
			i++;
		else
			return(0);
	}
	return (1);
}
