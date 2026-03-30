#include "../inc/ft_ls.h"

void	print_long_format(char **all_files_or_dirs) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;
	int k;

	k = 0;
	formatting_lengths = get_formatting_lengths(all_files_or_dirs);
	ft_printf("total %d\n", formatting_lengths.count);
	while (all_files_or_dirs[k]) {
		lstat(all_files_or_dirs[k], &statbuff);
		print_permissions(statbuff);
		print_name_and_grid(formatting_lengths, statbuff);
		if (S_ISCHR(statbuff.st_mode) || S_ISBLK(statbuff.st_mode)) {
			//printf("%#010x", makedev(major(statbuff.st_rdev), minor(statbuff.st_rdev)));
			ft_printf("%*d,", 5, major(statbuff.st_rdev));
			ft_printf("%*d",5, minor(statbuff.st_rdev));
		} else
			ft_printf("%*d", formatting_lengths.size, (int)statbuff.st_size);
		print_last_time_modified(statbuff);
		print_file_name(all_files_or_dirs[k]);
		k++;
	}

}
