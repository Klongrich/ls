#include "../inc/ft_ls.h"

int	is_flag(char *str) {
	int i;

	i = 0;
	if (!check_start_of_flag(str)) {
		return (0);
	} else {
		i++;
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
			else if (str[i] == 'G')
				i++;
			else if (str[i] == 'u')
				i++;
			else if (str[i] == 'f')
				i++;
			else
				return(0);
		}
	}
	return (1);
}
