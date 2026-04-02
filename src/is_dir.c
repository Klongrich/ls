#include "../inc/ft_ls.h"

int	is_dir(const char *path){
	struct stat path_stat;

	if((lstat(path,  &path_stat)) == -1)
		return(0);
	return (S_ISDIR(path_stat.st_mode));
}
