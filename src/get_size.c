#include "../inc/ft_ls.h"

int	get_size(char **str) {
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
