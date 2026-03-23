#include "../inc/ft_ls.h"

int	get_repo_or_file_count(char *dir_path, int a_flag) {
	DIR *dir;
	struct dirent  *dp;
	int count;
	
	count = 0;
	dir = opendir(dir_path);
	if (!dir) {
		return(0);
	} else {
		if (a_flag) {
			while((dp = readdir(dir))) 
				count++;
		} else {
			while((dp = readdir(dir))) {
				if(!(dp->d_name[0] == '.'))
					count++; 
			}		
		}
	}
	closedir(dir);
	return (count);
}
