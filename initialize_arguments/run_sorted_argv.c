#include "ft_ls.h"

void	run_sorted_argv(char **sorted_files, char **sorted_dirs, int number_of_invalid_args, t_flags *flags) {
	int number_of_valid_args;	

	number_of_valid_args = get_size(sorted_files) + get_size(sorted_dirs);
	if(flags->recur) {
		run_recursion(sorted_files, sorted_dirs, flags, number_of_invalid_args);
	} else {
		if(number_of_valid_args == 1 && number_of_invalid_args == 0)
			run_one_valid_argument(sorted_dirs, sorted_files, flags);
		else
			run_multiple_arguments(sorted_files, sorted_dirs, flags);
	}  
}
