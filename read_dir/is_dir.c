#include "../inc/ft_ls.h"

int	is_dir(const char *path, t_flags *flags){
	struct stat path_stat;

	if(flags->l || flags->color) {
		if((lstat(path, &path_stat)) == -1)
			return(0);
	} else {
		if((stat(path,  &path_stat)) == -1)
			return(0);
	}
	return (S_ISDIR(path_stat.st_mode));
}
