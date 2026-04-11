#include "ft_ls.h"

void	sort_then_run_argv(char **parsed_argv, t_flags *flags) {
	char **files;
	char **dirs;
	char **sorted_files;
	char **sorted_dirs;
	int number_of_invalid_args;
	
	number_of_invalid_args = check_is_file_or_dir(bubble_sort(parsed_argv, 0, get_size(parsed_argv)), flags);
	files = get_files_from_args(parsed_argv, flags);
	dirs = get_dirs_from_args(parsed_argv, flags);

	sorted_files = handel_file_sort(files, flags);
	sorted_dirs = handel_dir_sort(dirs, flags);

	run_sorted_argv(sorted_files, sorted_dirs, number_of_invalid_args, flags);
	free(files);
	free(dirs);
}
