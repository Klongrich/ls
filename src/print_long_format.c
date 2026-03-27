#include "../inc/ft_ls.h"

void	print_long_format(char **all_files_or_dirs) {
	t_lengths	file_or_dir_info;
	int k;

	k = 0;
	file_or_dir_info = get_total(all_files_or_dirs);
	ft_printf("total %d\n", file_or_dir_info.count);
	while (all_files_or_dirs[k]) {
		printf("%s\n", all_files_or_dirs[k]);
		k++;
	}

}
