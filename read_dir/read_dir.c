#include "../inc/ft_ls.h"

char 	**read_dir(char *dir_path, t_flags *flags){
///	DIR	*dir;
//	struct dirent *dp;
	int repo_or_file_count;
	char **all_files_or_directories;
//	char *temp;
//	int i;

//	i = 0;
	repo_or_file_count = get_repo_or_file_count(dir_path, flags->a, flags->l);	
	if (!repo_or_file_count) {
		return(0);
	} else {

		all_files_or_directories = (char **)malloc(sizeof(char *) * repo_or_file_count + 1);
		if (!all_files_or_directories)
			printf("Error mallocing\n");

		if(flags->a) 
			read_dir_with_hidden_files(all_files_or_directories, dir_path, flags);
		else
			read_dir_standard(all_files_or_directories, dir_path, flags);

		/*
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

		*/
		
		if (flags->t) 
			merge_time_sort(all_files_or_directories, 0, get_size(all_files_or_directories) - 1, flags->r);
		else 
			merge_sort2(all_files_or_directories, 0, get_size(all_files_or_directories) - 1, flags->r);

		if(flags->l)
			print_long_format(all_files_or_directories);	
		if (flags->l || flags->t) 
			cut_file_path_from_files_or_dirs(all_files_or_directories);
		if(!flags->l)
			print_list(all_files_or_directories);

		return(all_files_or_directories);
	}
}

