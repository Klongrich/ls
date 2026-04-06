#include "../inc/ft_ls.h"

int	check_files_link(char *str)
{
	struct stat stuff;

	lstat(str, &stuff);
	if (S_ISLNK(stuff.st_mode))
		return(1);
	else
		return(0);
}
