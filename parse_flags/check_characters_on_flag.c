#include "../inc/ft_ls.h"

int	check_characters_on_flag(char c) {
	if (c == 'a')
		return (1);
	else if (c == 't')
		return (1);
	else if (c == 'l')
		return (1);
	else if (c == 'r')
		return (1);
	else if (c == 'R')
		return (1);
	else if (c == 'G')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'f')
		return (1);
	else
		return(0);
}
