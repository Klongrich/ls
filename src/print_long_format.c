#include "../inc/ft_ls.h"

void	print_long_format(char **all_files_or_dirs) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;
	int k;

	k = 0;
	formatting_lengths = get_formatting_lengths(all_files_or_dirs);
	printf("total %d\n", formatting_lengths.count);
	//print_t_lengths(formatting_lengths);
	while (all_files_or_dirs[k]) {
		lstat(all_files_or_dirs[k], &statbuff);
		print_permissions(statbuff);
		printf("%s\n", all_files_or_dirs[k]);
		k++;
	}

}
