#include "../inc/ft_ls.h"

void initialize_arguments(char **argv, t_flags *flags, int i){
	char **parsed_argv;
	char **sorted;
	char **temp;
	int number_of_valid_args;
	int number_of_invalid_args;
	int j;
	int sorted_dirs_size;
	
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
			if(number_of_valid_args == 1 && number_of_invalid_args == 0) {
				run_one_valid_argument(sorted_dirs, sorted_files, flags);
				/*
				if (sorted_dirs[0] != NULL) {
					temp = read_dir(sorted_dirs[0], flags);
					if(temp)
						free_list(temp);
				} else {
					if (flags->l) {
						if (sorted_files[0][0] != '/') {
							long_temp = ft_strjoin("./", sorted_files[0]);
							print_single_file_long_format(long_temp);
							free(long_temp);
						}
						else {
							print_single_file_long_format(sorted_files[0]);
						}
					} else {
						ft_printf("%s\n", sorted_files[0]);
					}
				}
				*/
			} else {
				if(sorted_files[0] != NULL) {
					if(flags->l) {
						print_long_format_files_from_args(sorted_files);
					} else {
						while(sorted_files[i]) {
							ft_printf("%s\n", sorted_files[i]);
							i++;
						}
					}
					if(sorted_dirs[0] != NULL)
						printf("\n");
				}
				i = 0;
				sorted_dirs_size = get_size(sorted_dirs);
				while(sorted_dirs[i]) {
					ft_printf("%s:\n", sorted_dirs[i]);
					temp = read_dir(sorted_dirs[i], flags);
					if (i + 1 != sorted_dirs_size)
						ft_printf("\n");
					if (temp)
						free_list(temp);
					i++;
				}
			}
		}
		free(files);
		free(dirs);
	}
	free_list(parsed_argv);
}
