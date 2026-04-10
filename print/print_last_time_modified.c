#include "../inc/ft_ls.h"

void		print_last_time_modified(struct stat statbuff)
{
	time_t	now;
	char	*times;

	now = time(NULL);
	times = ctime(&statbuff.st_mtime);
	if ((now - statbuff.st_mtime) > (182 * 24 * 60 * 80)) {
		print_date_year(times);
	} else {
		times += 3;
		ft_printf("%.*s ", 13, times);
	}
}
