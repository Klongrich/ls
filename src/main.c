#include "../inc/ft_ls.h"

char 	**read_dir(char *dir_path, t_flags *flags){
	DIR	*dir;
	struct dirent *dp;
	int repo_or_file_count;
	char **all_files_or_directories;
	int i;

	i = 0;
	dir = opendir(dir_path);
	repo_or_file_count = 0;
	if (!dir) {
		printf("Opertaion Not Permitted\n");
		return (0);
	}
	else {
	//Counting the amount of character array's we have to allocate
	while ((dp = readdir(dir))) {
		if(!flags->a) {
			if (!(dp->d_name[0] == '.')) {
				repo_or_file_count++;
			}
		} else {
			repo_or_file_count++;
		}
	}
	closedir(dir);

	//Allocating character array
	all_files_or_directories = (char **)malloc(sizeof(char *) * repo_or_file_count + 1);
	if (!all_files_or_directories)
		printf("Error mallocing\n");

	//Copying data into our new array
	dir = opendir(dir_path);
	while ((dp = readdir(dir))) {
		if(!flags->a) {
			if (!(dp->d_name[0] == '.')) {
				all_files_or_directories[i] = (char *)malloc(sizeof(char) * MAX_FILE_LENGTH);
				all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], dp->d_name);
				i++;		
			}
		} else {
			all_files_or_directories[i] = (char *)malloc(sizeof(char) * MAX_FILE_LENGTH);
			all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], dp->d_name);
			i++;
		}
	}
	closedir(dir);
	
	//Sorting our array a to z
	all_files_or_directories = bubble_sort(all_files_or_directories, flags->r);

	int k;

	k = 0;
	while (all_files_or_directories[k]) {
		printf("%s\n", all_files_or_directories[k]);
		k++;
	}
	return(all_files_or_directories);
	}
}

char	**check_is_file_or_dir(char **sorted_args){
	int i;
	int j;
	char **result;

	i = 0;
	j = 0;
	result = (char **)malloc(sizeof(char *) * get_size(sorted_args) + 1);
	while(sorted_args[i]) {
		if (is_dir(sorted_args[i]) || is_file(sorted_args[i])) {
			result[j] = sorted_args[i];
			j++;
		} else {
			printf("ls: %s: file or dir not found\n", sorted_args[i]);
		}
		i++;
	}
	return(result);
}

int	recur(char **files_or_repos, t_flags *flags) {
	int i;
	char **append;
	char **files_from_repo;

	i = 0;
	printf("\n");
	while (files_or_repos[i]) {
		if(is_dir(files_or_repos[i])) {
			printf("%s:\n", files_or_repos[i]);
			files_from_repo = read_dir(files_or_repos[i],flags);
			if(files_from_repo) {
				append = append_dir(files_or_repos[i], files_from_repo);
				recur(append, flags);
			}
			//free_list(files_from_repo);
			//free_list(append);
		}
		i++;
	}
	return (0);
}

void initalize_arguments(char **argv, t_flags *flags, int i){
	char **parsed_argv;
	char **sorted;
	char **list_of_args;
	int j;
	
	j = 0;	
	parsed_argv = (char **)malloc(sizeof(char *) * get_size(argv) + 1 - i);
	if (!parsed_argv) {
		printf("error mallocing\n");
	}

	if (!argv[i]) {
		if(flags->recur) {
			recur(read_dir(".", flags), flags);
		} else {
			read_dir(".", flags);
		}
	} else {

		while(argv[i]) {
			parsed_argv[j] = (char *)malloc(sizeof(char ) * MAX_PATH_LENGTH + 1);
			parsed_argv[j]= ft_strcpy(parsed_argv[j], argv[i]);
			i++;
			j++;
		}

		sorted = bubble_sort(parsed_argv, 0);	
		list_of_args = check_is_file_or_dir(sorted);

		i = 0;
		
		if(flags->recur) {
			recur(list_of_args, flags);
		} else {
			while (list_of_args[i]) {
				if (is_dir(list_of_args[i])) {
					printf("%s:\n", list_of_args[i]);
					read_dir(list_of_args[i], flags);
					printf("\n");	
				} else {
					printf("%s\n", list_of_args[i]);
				}
				i++;
			}
		}

		if (flags) {}	
		free(list_of_args);
	}
	free_list(parsed_argv);
}

int 	main(int argc, char **argv){

	t_flags flags;	
	int i;
	int getting_flags;
	int dash_found;
	int dashdash_found;

	i = 0;
	getting_flags = 1;
	dashdash_found = 0;
	dash_found = 0;
	initialize_flags(&flags);
	if (argc == 0) {
		return (0);
	}
	if (argc == 1){
		read_dir(".", &flags);	
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
	return(0);
}
