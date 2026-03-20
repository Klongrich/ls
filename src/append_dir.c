#include "../inc/ft_ls.h"

char	**append_dir(char *dir, char **files_or_dirs) {
	int i;
	char **res;
	char *dir_;

	i = 0;
	dir_ = dir;
	res = (char **)malloc(sizeof(char *) * get_size(files_or_dirs) + 1);
	if(!res) {
		printf("error\n");
	}	
	if (!check_end(dir))
		dir_ = ft_strjoin(dir, "/");
	while(files_or_dirs[i]) {
		res[i] = ft_strjoin(dir_, files_or_dirs[i]);
		i++;
	}
	if (!check_end(dir))
		free(dir_);
	return(res);
}
