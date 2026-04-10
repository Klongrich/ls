#include "../inc/ft_ls.h"

void	print_long_format(char **all_files_or_dirs, t_flags *flags) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;
	int k;

	k = 0;
	formatting_lengths = get_formatting_lengths(all_files_or_dirs);
	ft_printf("total %d\n", formatting_lengths.count);	
	while (all_files_or_dirs[k]) {
		lstat(all_files_or_dirs[k], &statbuff);
		print_permissions(statbuff, all_files_or_dirs[k]);
		print_name_and_grid(formatting_lengths, statbuff);		
		print_file_size(statbuff, formatting_lengths);
		if (flags->t & flags->u)
			print_last_time_accessed(statbuff);
		else	
			print_last_time_modified(statbuff);
		print_file_name(all_files_or_dirs[k], 0, flags);
		k++;
	}
}
