#include "../inc/ft_ls.h"

char	**append_dir(char *dir, char **files_or_dirs) {
	int i;
	int j;
	char **res;
	char *dir_;

	j = 0;
	i = 0;
	dir_ = dir;
	res = (char **)malloc(sizeof(char *) * get_size(files_or_dirs) + 1);
	if(!res) {
		printf("error\n");
	}	
	if (!check_end(dir))
		dir_ = ft_strjoin(dir, "/");
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
	if (!check_end(dir))
		free(dir_);
	return(res);
}
