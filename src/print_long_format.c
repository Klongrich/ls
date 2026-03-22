#include "../inc/ft_ls.h"

void	print_long_format(char **all_files_or_dirs) {
	int k;

	k = 0;
	while (all_files_or_dirs[k]) {
		printf("%s\n", all_files_or_dirs[k]);
		k++;
	}

}
