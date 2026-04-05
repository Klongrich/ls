#include "../inc/ft_ls.h"

int	get_repo_or_file_count(char *dir_path, int a_flag, int l_flag) {
	DIR *dir;
	struct dirent  *dp;
	int count;
	
	count = 0;
	dir = opendir(dir_path);
	if (!dir) {
		if(l_flag)
			ft_putstr("total 0\n");
		if(errno == EACCES) {
			printf("ls: %s: Permission denied\n", dir_path);
		} else if (errno == EPERM) {
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(dir_path, 2);
			ft_putstr_fd(" Operation not permitted\n", 2);
		}
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
		if(l_flag && count == 0)
			ft_putstr("total 0\n");
	}
	closedir(dir);
	return (count);
}
