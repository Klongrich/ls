#include "../inc/ft_ls.h"

void	print_list(char **str){
	int i;

	i = 0;
	while (str[i]) {
		ft_printf("%s\n", str[i]);
		i++;
	}
}
