#include "ft_ls.h"

void	print_color(char **paths, int is_from_args, int l_flag) {
	int i;

	i = 0;
	while(paths[i]) {
		print_color_single(paths[i], is_from_args, l_flag);	
		i++;
	}
}
