#include "../inc/ft_ls.h"

void	print_long_format_files_from_args(char **all_files, t_flags *flags) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;
	int k;
	int i;
	char **all_files_appended;

	k = 0;
	i = 0;	
	all_files_appended = append_files_from_args_for_long_format("./", all_files);
	formatting_lengths = get_formatting_lengths(all_files_appended);
	while (all_files_appended[k]) {
		lstat(all_files[k], &statbuff);
		print_permissions(statbuff, all_files[k]);
		print_name_and_grid(formatting_lengths, statbuff);
		ft_printf("%*d", formatting_lengths.size, (int)statbuff.st_size);
		if (flags->t & flags->u)
			print_last_time_accessed(statbuff);
		else
			print_last_time_modified(statbuff);
		if(all_files_appended[k][0] != '/') {
			i = 2;
			while (all_files_appended[k][i]) {
				ft_putchar(all_files_appended[k][i]);
				i++;
			}
			ft_putchar('\n');
		} else {
			print_file_name(all_files_appended[k], 1, flags);
		}	
		k++;
	}
	free_list(all_files_appended);
}
