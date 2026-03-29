#include "../inc/ft_ls.h"

void	print_mtime(char *file_path) {
	struct stat time;

	lstat(file_path, &time);
	printf("%ld\n", time.st_mtime);
}
