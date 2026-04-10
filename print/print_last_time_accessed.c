#include "../inc/ft_ls.h"

void		print_last_time_accessed(struct stat statbuff)
{
	time_t	now;
	char	*times;

	now = time(NULL);
	times = ctime(&statbuff.st_atime);
	if ((now - statbuff.st_atime) > (182 * 24 * 60 * 80)) {
		print_date_year(times);
	} else {
		times += 3;
		ft_printf("%.*s ", 13, times);
	}
}
