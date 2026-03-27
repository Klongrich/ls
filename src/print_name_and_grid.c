#include "../inc/ft_ls.h"

void	print_name_and_grid(t_lengths formatting_info, struct stat statbuff) {
	struct passwd	*pwd;
	//struct group	*grp;

	ft_printf("%*d ", formatting_info.links, statbuff.st_nlink); 
	if ((pwd = getpwuid(statbuff.st_uid)) != NULL)
		ft_printf("%*s", formatting_info.name + 2, pwd->pw_name);
	else
		ft_printf("%*d", formatting_info.name + 2, statbuff.st_uid);
}
