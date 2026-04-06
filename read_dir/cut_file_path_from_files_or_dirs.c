#include "../inc/ft_ls.h"

void	cut_file_path_from_files_or_dirs(char **all_files_or_directories) {
	char *temp_name;
	int i;		

	i = 0;
	while (all_files_or_directories[i]) {
		temp_name = get_name_from_path(all_files_or_directories[i]);
		all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], temp_name);
	
		free(temp_name);
		i++;
	}
}
