#include "../inc/ft_ls.h"

char	**append(char **files_or_dirs, char *dir_){
	int i;
	int j;
	char **res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * get_size(files_or_dirs) + 1);
	if(!res) 
		printf("error\n");
	while(files_or_dirs[i]) {
		while ((!ft_strcmp(files_or_dirs[i], ".") || !ft_strcmp(files_or_dirs[i], ".."))) {
			i++;
			if (!files_or_dirs[i])
				break;
		}
		if(!files_or_dirs[i])
			break;
		res[j] = ft_strjoin(dir_, files_or_dirs[i]);
		i++;
		j++;
	}
	res[j] = 0;
	return(res);
}

char	**append_dir(char *dir, char **files_or_dirs) {
	char **res;
	char *dir_;

	dir_ = dir;
	if (!check_end(dir))
		dir_ = ft_strjoin(dir, "/");
	res = append(files_or_dirs, dir_);
	if (!check_end(dir))
		free(dir_);
	return(res);
}
