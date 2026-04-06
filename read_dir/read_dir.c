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

	repo_or_file_count = get_repo_or_file_count(dir_path, flags->a, flags->l);
		
	if (!repo_or_file_count) {
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
			merge_time_sort(all_files_or_directories, 0, get_size(all_files_or_directories) - 1, flags->r);
		} else {
			merge_sort2(all_files_or_directories, 0, get_size(all_files_or_directories) - 1, flags->r);
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
				ft_printf("%s\n", all_files_or_directories[k]);
				k++;
			}
		}

		return(all_files_or_directories);
	}
}

