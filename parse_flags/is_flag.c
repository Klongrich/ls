#include "../inc/ft_ls.h"

int	is_flag(char *str) {
	int i;

	i = 0;
	if (!check_start_of_flag(str)) {
		return (0);
	} else {
		i++;
		while(str[i]) {
			if (check_characters_on_flag(str[i]))
				i++;
			else
				return(0);
		}
	}
	return (1);
}
