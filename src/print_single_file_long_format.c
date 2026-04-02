#include "../inc/ft_ls.h"

void	print_single_file_long_format(char *file_path) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;

	formatting_lengths = get_single_file_formatting_lengths(file_path);

	lstat(file_path, &statbuff);
	print_permissions(statbuff, file_path);
	print_name_and_grid(formatting_lengths, statbuff);
	ft_printf("%*d", formatting_lengths.size, (int)statbuff.st_size);
	print_last_time_modified(statbuff);

	if(file_path[0] != '/') {
		file_path++;
		file_path++;
		printf("%s\n", file_path);
	} else {
		print_file_name(file_path, 1);
	}
}

