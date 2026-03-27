#include "../inc/ft_ls.h"

void		print_last_time_modified(char *str)
{
	//time_t		now;
	char		*times;
	struct stat	statbuf;

	//struct tm	*tm;

	/*
	now = time(0);
	tm = localtime(&now);
	printf("Current time %02d:\n", tm->tm_mon + 1);
	*/

	lstat(str, &statbuf);
	times = ctime(&statbuf.st_mtime);
	times += 3;

	/*
	printf("Time: %ld\n", statbuf.st_mtime);
	if (S_ISLNK(statbuf.st_mode))
	{
		times += 17;
		ft_printf("%.*s %s\n", 7, times, name);
	}
	*/
	ft_printf("%.*s ", 13, times);
}
