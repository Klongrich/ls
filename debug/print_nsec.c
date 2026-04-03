#include "../inc/ft_ls.h"

void	print_nsec(char *file_path) {
	struct stat time;

	lstat(file_path, &time);
	printf("%ld\n", time.st_mtimespec.tv_nsec);
}
