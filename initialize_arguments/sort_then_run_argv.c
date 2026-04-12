#include "ft_ls.h"

char	**get_files_and_dirs_args(char **list_of_args, t_flags *flags) {
	int i;
	int j;
	char **result;

	i = 0;
	j = 0;
	result = (char **)malloc(sizeof(char *) * get_size(list_of_args) + 1);
	while (list_of_args[i]) {
		if(is_file(list_of_args[i], flags) || is_dir(list_of_args[i], flags)) {
			result[j] = list_of_args[i];
			j++;
		}
		i++;
	}
	return (result);
}


void	run_df_flag(char **parsed_argv, t_flags *flags) {
	char **all_files;

	all_files = get_files_and_dirs_args(parsed_argv, flags);
	check_is_file_or_dir(bubble_sort(parsed_argv, 0, get_size(parsed_argv)), flags);
	if (flags->l) {
		print_long_format(all_files, flags);
	} else if ((flags->color & isatty(STDOUT_FILENO))) {
		//make a print_all_color_df_flag to append files for proper lstat calls
		print_all_color_d_flag(all_files, flags);
	} else  
		print_list(all_files);
	free(all_files);
}


void	sort_then_run_argv(char **parsed_argv, t_flags *flags) {
	char **files;
	char **dirs;
	char **sorted_files;
	char **sorted_dirs;
	int number_of_invalid_args;

	if ((flags->d && flags->f) && get_number_of_valid_args(parsed_argv, flags) > 1) {
		run_df_flag(parsed_argv, flags);
	} else {
		number_of_invalid_args = check_is_file_or_dir(bubble_sort(parsed_argv, 0, get_size(parsed_argv)), flags);
		
		files = get_files_from_args(parsed_argv, flags);
		dirs = get_dirs_from_args(parsed_argv, flags);

		sorted_files = handel_file_sort(files, flags);
		sorted_dirs = handel_dir_sort(dirs, flags);

		run_sorted_argv(sorted_files, sorted_dirs, number_of_invalid_args, flags);
		free(files);
		free(dirs);
	}
}
