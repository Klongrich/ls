#include "../inc/ft_ls.h"

void initialize_arguments(char **argv, t_flags *flags, int i){
	char **parsed_argv;
	char **sorted;
	int number_of_valid_args;
	int number_of_invalid_args;
	int j;
	
	j = 0;
	number_of_invalid_args = 0;	
	parsed_argv = (char **)malloc(sizeof(char *) * get_size(argv) + 1 - i);
	if (!parsed_argv) {
		printf("error mallocing\n");
	}
	if (!argv[i] || (!ft_strcmp(argv[i], "--"))) {
		run_with_no_files_or_repos_passed(flags);	
	} else {
		while(argv[i]) {
			parsed_argv[j] = (char *)malloc(sizeof(char ) * MAX_PATH_LENGTH + 1);
			parsed_argv[j]= ft_strcpy(parsed_argv[j], argv[i]);
			i++;
			j++;
		}
		char **files;
		char **dirs;

		char **sorted_files;
		char **sorted_dirs;

		sorted = bubble_sort(parsed_argv, 0, get_size(parsed_argv));
		number_of_invalid_args = check_is_file_or_dir(sorted, flags->l);

		files = get_files_from_args(parsed_argv, flags->l);
		dirs = get_dirs_from_args(parsed_argv, flags->l);
		//Could use strcoll() to mimic extact behavior with special characters
		if (flags->t) {
			sorted_files = time_sort(files, flags->r);
			sorted_dirs = time_sort(dirs, flags->r);
		} else {
			sorted_files = bubble_sort(files, flags->r, get_size(files));
			sorted_dirs = bubble_sort(dirs, flags->r, get_size(dirs));
		}
		
		i = 0;
		number_of_valid_args = get_size(sorted_files) + get_size(sorted_dirs);
		if(flags->recur) {
			run_recursion(sorted_files, sorted_dirs, flags, number_of_invalid_args);		
		} else {
			if(number_of_valid_args == 1 && number_of_invalid_args == 0) 
				run_one_valid_argument(sorted_dirs, sorted_files, flags);
			else 
				run_multiple_arguments(sorted_files, sorted_dirs, flags);
		}
		free(files);
		free(dirs);
	}
	free_list(parsed_argv);
}
