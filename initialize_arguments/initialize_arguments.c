#include "../inc/ft_ls.h"


void	init_parsed_argv(char **parsed_argv, char **argv, int i, int j) {
	while(argv[i]) {
		parsed_argv[j] = (char *)malloc(sizeof(char ) * MAX_PATH_LENGTH + 1);
		parsed_argv[j]= ft_strcpy(parsed_argv[j], argv[i]);
		i++;
		j++;
        }
}

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

void	sort_then_run_argv(char **parsed_argv, t_flags *flags) {
	char **files;
	char **dirs;
	char **sorted_files;
	char **sorted_dirs;
	int number_of_invalid_args;
	
	number_of_invalid_args = check_is_file_or_dir(bubble_sort(parsed_argv, 0, get_size(parsed_argv)), flags->l);
	files = get_files_from_args(parsed_argv, flags->l);
	dirs = get_dirs_from_args(parsed_argv, flags->l);

	if (flags->t) {
		if (flags->u) {
			sorted_files = last_time_accessed_sort(files, flags->r);
			sorted_dirs =  last_time_accessed_sort(dirs, flags->r);
		} else {
			sorted_files = time_sort(files, flags->r);
			sorted_dirs = time_sort(dirs, flags->r);
		}
	} else {

		sorted_files = bubble_sort(files, flags->r, get_size(files));
		sorted_dirs = bubble_sort(dirs, flags->r, get_size(dirs));
	}

	run_sorted_argv(sorted_files, sorted_dirs, number_of_invalid_args, flags);
	free(files);
	free(dirs);
}


void initialize_arguments(char **argv, t_flags *flags, int i){
	char **parsed_argv;
	int j;
	
	j = 0;
	parsed_argv = (char **)malloc(sizeof(char *) * get_size(argv) + 1 - i);
	if (!parsed_argv) {
		printf("error mallocing\n");
	}
	if (!argv[i] || (!ft_strcmp(argv[i], "--"))) {
		run_with_no_files_or_repos_passed(flags);	
	} else {
		init_parsed_argv(parsed_argv, argv, i, j);
		sort_then_run_argv(parsed_argv, flags);
	}
	free_list(parsed_argv);
}
