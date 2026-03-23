#include "../inc/ft_ls.h"

char	*append_single_dir(char *dir, char *files_or_dir) {
	char *res;
	char *dir_;

	dir_ = dir;
	res = (char *)malloc(sizeof(char) * ft_strlen(files_or_dir) + ft_strlen(dir) + 2);
	if(!res) {
		printf("error\n");
	}	
	if (!check_end(dir))
		dir_ = ft_strjoin(dir, "/");
	if ((!ft_strcmp(files_or_dir, ".") || !ft_strcmp(files_or_dir, ".."))) {
			return(files_or_dir);
	}
	res = ft_strjoin(dir_, files_or_dir);
	if (!check_end(dir))
		free(dir_);
	return(res);
}
