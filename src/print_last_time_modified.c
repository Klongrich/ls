#include "../inc/ft_ls.h"

void		print_last_time_modified(struct stat statbuff)
{
	char		*times;

	times = ctime(&statbuff.st_mtime);
	times += 3;
	ft_printf("%.*s ", 13, times);
}
