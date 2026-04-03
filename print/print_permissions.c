#include "../inc/ft_ls.h"

void		print_permissions(struct stat statbuff, char *file_path)
{
	if(S_ISDIR(statbuff.st_mode)) {
		ft_putchar('d');
	} else if(S_ISSOCK(statbuff.st_mode)) {
		ft_putchar('s'); 
	} else if (S_ISFIFO(statbuff.st_mode)) {
		ft_putchar('p');
	} else if (S_ISCHR(statbuff.st_mode)) {
		ft_putchar('c');
	} else if (S_ISBLK(statbuff.st_mode)) {
		ft_putchar('b');
	} else if (S_ISREG(statbuff.st_mode)) {
		ft_putchar('-');
	} else if (S_ISLNK(statbuff.st_mode)) {
		ft_putchar('l');
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

	ssize_t ret;
//	acl_t acl;
//	acl_entry_t entry;

	//printf("checking file_path: %s\n", file_path);
	ret = listxattr(file_path, NULL, 0, XATTR_NOFOLLOW);
	if (ret > 0) {
		ft_putchar('@');
		ft_putchar(' ');
	} else {	
		ft_putchar(' ');
		ft_putchar(' ');
	}
}

