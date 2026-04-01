#include "../inc/ft_ls.h"

void		print_permissions(struct stat statbuff)
{
	/*
	ft_putchar((S_ISFIFO(statbuff.st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(statbuff.st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(statbuff.st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(statbuff.st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(statbuff.st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(statbuff.st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(statbuff.st_mode)) ? 's' : '\0');
	*/

	if(S_ISDIR(statbuff.st_mode)) {
		ft_putchar('d');
	} else if(S_ISSOCK(statbuff.st_mode)) {
		ft_putchar('s'); 
	} else {
		ft_putchar('-');
	}


	if(statbuff.st_mode & S_IRUSR) {
		ft_putchar('r');
	} else {
		ft_putchar('-');
	}
	if(statbuff.st_mode & S_IWUSR) {
		ft_putchar('w');
	} else {
		ft_putchar('-');
	}
	if (statbuff.st_mode & S_IXUSR) {
		ft_putchar('x');
	} else {
		ft_putchar('-');
	}	
	if (statbuff.st_mode & S_IRGRP) {
		ft_putchar('r');
	} else {
		ft_putchar('-');
	}
	if (statbuff.st_mode & S_IWGRP) {
		ft_putchar('w');
	} else {
		ft_putchar('-');
	}
	if (statbuff.st_mode & S_IXGRP) {
		ft_putchar('x');
	} else {
		ft_putchar('-');
	}
	if (statbuff.st_mode & S_IROTH) {
		ft_putchar('r');
	} else {
		ft_putchar('-');
	}
	if (statbuff.st_mode & S_IWOTH) {
		ft_putchar('w');
	} else {
		ft_putchar('-');
	}
	if (statbuff.st_mode & S_IXOTH) {
		ft_putchar('x');
	} else {
		ft_putchar('-');
	}	
	ft_putchar(' ');
	ft_putchar(' ');
}

