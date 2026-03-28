#include "../inc/ft_ls.h"

char 	**read_dir(char *dir_path, t_flags *flags){
	DIR	*dir;
	struct dirent *dp;
	int repo_or_file_count;
	char **all_files_or_directories;
	char *temp;
	char *temp_name;
	int i;

	i = 0;

	repo_or_file_count = get_repo_or_file_count(dir_path, flags->a);
	
	if (!repo_or_file_count) {
		printf("\n");
		//printf("Opertaion Not Permitted\n");
		return(0);
	} else {

		//Allocating character array
		all_files_or_directories = (char **)malloc(sizeof(char *) * repo_or_file_count + 1);
		if (!all_files_or_directories)
			printf("Error mallocing\n");

		//Copying data into our new array
		dir = opendir(dir_path);
		while ((dp = readdir(dir))) {
			if(!flags->a) {
				if (!(dp->d_name[0] == '.')){
					if (flags->t || flags->l) {
						all_files_or_directories[i] = (char *)malloc(sizeof(char) * MAX_PATH_LENGTH);
						temp = append_single_dir(dir_path, dp->d_name);
						all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], temp);
						free(temp); 
					} else {
						all_files_or_directories[i] = (char *)malloc(sizeof(char) * MAX_FILE_LENGTH);
						all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], dp->d_name);
					}
					i++;		
				}
			} else {
				if(flags->t || flags->l) {
					all_files_or_directories[i] = (char *)malloc(sizeof(char) * MAX_PATH_LENGTH);
					temp = append_single_dir(dir_path, dp->d_name);
					all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], temp);
					free(temp);
				} else {
					all_files_or_directories[i] = (char *)malloc(sizeof(char) * MAX_FILE_LENGTH);
					all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], dp->d_name);
				}
				i++;
			}
		}

		all_files_or_directories[i] = 0;
		closedir(dir);

		if (flags->t) {
			all_files_or_directories = time_sort(all_files_or_directories, flags->r);
		} else {
			all_files_or_directories = bubble_sort(all_files_or_directories, flags->r);
			//all_files_or_directories = merge_sort(all_files_or_directories);
		}

		if (flags->t && !flags->l) {
			int kk;

			kk = 0;
			while(all_files_or_directories[kk]) {
				temp_name = get_name_from_path(all_files_or_directories[kk]);
				all_files_or_directories[kk] = ft_strcpy(all_files_or_directories[kk], temp_name);
				free(temp_name);
				kk++;
			}
		}

		if (flags->l) {
			print_long_format(all_files_or_directories);
			
			int kk;

			kk = 0;
			while(all_files_or_directories[kk]) {
				temp_name = get_name_from_path(all_files_or_directories[kk]);
				all_files_or_directories[kk] = ft_strcpy(all_files_or_directories[kk], temp_name);
				free(temp_name);
				kk++;
			}
		} else {

			int k;

			k = 0;
			while (all_files_or_directories[k]) {
				printf("%s\n", all_files_or_directories[k]);
				k++;
			}
		}

		return(all_files_or_directories);
	}
}

void	check_is_file_or_dir(char **sorted_args){
	int i;

	i = 0;
	while(sorted_args[i]) {
		if (!is_dir(sorted_args[i]) && !is_file(sorted_args[i])) {
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(sorted_args[i], 2);
			ft_putstr_fd(" No such file or directory\n", 2);
		}
		i++;
	}
}

char	**get_files_from_args(char **list_of_args) {
	int i;
	int j;
	char **result;

	i = 0;
	j = 0;
	result = (char **)malloc(sizeof(char *) * get_size(list_of_args) + 1);
	while (list_of_args[i]) {
		if(is_file(list_of_args[i])) {
			result[j] = list_of_args[i];
			j++;
		}
		i++;
	}

	return (result);

}

char	**get_dirs_from_args(char **list_of_args) {
	int i;
	int j;
	char **result;

	j = 0;
	i = 0;
	result = (char **)malloc(sizeof(char *) * get_size(list_of_args) + 1);
	while (list_of_args[i]) {
		if (is_dir(list_of_args[i])) {
			result[j] = list_of_args[i];
			j++;
		}
		i++; 
	}
	return (result);
}

int	recur(char **files_or_repos, t_flags *flags) {
	int i;
	char **append;
	char **files_from_repo;

	i = 0;
	while (files_or_repos[i]) {
		if(is_dir(files_or_repos[i])) {
			printf("%s:\n", files_or_repos[i]);
			files_from_repo = read_dir(files_or_repos[i],flags);
			printf("\n");
			if(files_from_repo) {
				append = append_dir(files_or_repos[i], files_from_repo);	
				recur(append, flags);

				free_list(append);
				free_list(files_from_repo);
			};
		}
		i++;
	}
	return (0);
}

void initalize_arguments(char **argv, t_flags *flags, int i){
	char **parsed_argv;
	char **sorted;
	char **temp;
	char **temp3;
	char **temp4;
	char *long_temp;
	int number_of_valid_args;
	int j;
	
	j = 0;	
	parsed_argv = (char **)malloc(sizeof(char *) * get_size(argv) + 1 - i);
	if (!parsed_argv) {
		printf("error mallocing\n");
	}

	if (!argv[i]) {
		if(flags->recur) {
			temp3 = read_dir(".", flags);
			printf("\n");
			temp4 = append_dir("./", temp3);;
			recur(temp4, flags);
			printf("\033[1A");
    			printf("\033[0G");
			free_list(temp3);
			free_list(temp4);
		} else {
			temp = read_dir(".", flags);
			free_list(temp);
		}
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

		sorted = bubble_sort(parsed_argv, 0);
		check_is_file_or_dir(sorted);

		files = get_files_from_args(parsed_argv);
		dirs = get_dirs_from_args(parsed_argv);

		//Can check if time_sort is passed
		sorted_files = bubble_sort(files, flags->r);
		sorted_dirs = bubble_sort(dirs, flags->r);
		
		i = 0;
		number_of_valid_args = get_size(sorted_files) + get_size(sorted_dirs);
		if(flags->recur) {
			if (flags->l) {
				print_long_format_files_from_args(sorted_files);
			} else {
				print_list(sorted_files);
			}
			recur(sorted_dirs, flags);
			if (sorted_dirs[0] != NULL) {
				printf("\033[1A");
				printf("\033[0G");
			}		
		} else {

			if(number_of_valid_args == 1) {
				if (sorted_dirs[0] != NULL) {
					temp = read_dir(sorted_dirs[0], flags);
					free_list(temp);
				} else {
					if (flags->l) {
						long_temp = ft_strjoin("./", sorted_files[0]);
						print_single_file_long_format(long_temp);
						free(long_temp);
					} else {
						printf("%s\n", sorted_files[0]);
					}
				}
			} else {
				if(sorted_files[0] != NULL) {
					if(flags->l) {
						print_long_format_files_from_args(sorted_files);
						printf("\n");
					} else {
						while(sorted_files[i]) {
							printf("%s\n", sorted_files[i]);
						}
					}
				}
				i = 0;
				while(sorted_dirs[i]) {
					printf("%s:\n", sorted_dirs[i]);
					temp = read_dir(sorted_dirs[i], flags);
					printf("\n");
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

int 	main(int argc, char **argv){

	t_flags flags;	
	int i;
	int getting_flags;
	int dash_found;
	int dashdash_found;
	char **temp;

	i = 0;
	getting_flags = 1;
	dashdash_found = 0;
	dash_found = 0;
	initialize_flags(&flags);
	if (argc == 0) {
		return (0);
	}
	if (argc == 1){
		temp = read_dir(".", &flags);	
		free_list(temp);		
	}
	if (argc > 1) {
		i = 1;
		while (argv[i]) {
			if (argv[i][0] == '-' && getting_flags) {
				if (!argv[i][1]) {
					getting_flags = 0;
					dash_found = 1;
				} else if (argv[i][1] == '-' && !argv[i][2]) {
					getting_flags = 0;
				} else {
					if((parse_flags(argv[i], &flags) == 0)) {
						printf("error, invalid flag. Usage: [-lratR]\n");
						return (0);
					}
				}
			}
			if (argv[i][0] != '-') {
				getting_flags = 0;
			}
			
			if (i + 1 == argc) {
				getting_flags = 0;
			}

			if (!getting_flags) {
				if (argv[i][0] == '-' && argv[i][1] == '-' && !dashdash_found && !dash_found) {
					dashdash_found = 1;
				} else {
				
					if (is_flag(argv[i]))
						i++;
					initalize_arguments(argv, &flags, i);
					break;
				}
			}
			i++;
		}
	
	}


}
