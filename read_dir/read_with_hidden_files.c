#include "../inc/ft_ls.h"

void	read_dir_with_hidden_files(char **all_files_or_directories, char *dir_path, t_flags *flags) {
	DIR	*dir;
	struct	dirent *dp;
	int	i;
	char	*temp;

	i = 0;
	dir = opendir(dir_path);
	while ((dp = readdir(dir))) {
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
	all_files_or_directories[i] = 0;
	closedir(dir);
}
