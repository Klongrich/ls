#include "../inc/ft_ls.h"

void	print_long_format_files_from_args(char **all_files) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;
	int k;
	char *temp;
	char **all_files_appended;

	k = 0;
	
	all_files_appended = append_dir("./", all_files);
	formatting_lengths = get_formatting_lengths(all_files_appended);
	while (all_files_appended[k]) {
		lstat(all_files[k], &statbuff);
		print_permissions(statbuff);
		print_name_and_grid(formatting_lengths, statbuff);
		ft_printf("%*d", formatting_lengths.size, (int)statbuff.st_size);
		print_last_time_modified(statbuff);

		temp = get_name_from_path(all_files_appended[k]);
		printf("%s\n", temp);
		free(temp);
		k++;
	}
	free(all_files_appended);
}
