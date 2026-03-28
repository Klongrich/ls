#include "../inc/ft_ls.h"

void	print_single_file_long_format(char *file_path) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;
	char *temp;

	formatting_lengths = get_single_file_formatting_lengths(file_path);

	lstat(file_path, &statbuff);
	print_permissions(statbuff);
	print_name_and_grid(formatting_lengths, statbuff);
	ft_printf("%*d", formatting_lengths.size, (int)statbuff.st_size);
	print_last_time_modified(statbuff);

	temp = get_name_from_path(file_path);
	printf("%s\n", temp);
	free(temp);
}

