#include "../inc/ft_ls.h"

void	print_name_and_grid(t_lengths formatting_info, struct stat statbuff) {
	//struct passwd	*pwd;
	//struct group	*grp;

	ft_printf("%*d ", formatting_info.links, statbuff.st_nlink); 
}
