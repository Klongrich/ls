#include "../inc/ft_ls.h"

void	run_recursion(char **sorted_files, char **sorted_dirs, t_flags *flags, int number_of_invalid_args) {
	char **temp3;
	char **temp4;
	int number_of_valid_args;
	
	number_of_valid_args = get_size(sorted_files) + get_size(sorted_dirs);
	if (flags->l) {
		print_long_format_files_from_args(sorted_files);
	} else {
		print_list(sorted_files);
	}
	if(number_of_valid_args == 1 && number_of_invalid_args == 0 && sorted_dirs[0]) {
		temp3 = read_dir(sorted_dirs[0], flags);
		temp4 = append_dir(sorted_dirs[0], temp3);
		recur(temp4, flags);
		free_list(temp3);
		free_list(temp4);	
	} else {
		recur(sorted_dirs, flags);
	}
}
