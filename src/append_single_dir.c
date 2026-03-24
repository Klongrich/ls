#include "../inc/ft_ls.h"

char	*append_single_dir(char *dir, char *files_or_dir) {
	char *res;
	char *dir_;

	dir_ = dir;	
	if (!check_end(dir))
		dir_ = ft_strjoin(dir, "/");
	res = ft_strjoin(dir_, files_or_dir);
	if (!check_end(dir))
		free(dir_);
	return(res);
}
