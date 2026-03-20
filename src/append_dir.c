#include "../inc/ft_ls.h"

char	**append_dir(char *dir, char **files_or_dirs) {
	int i;
	char **res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * get_size(files_or_dirs) + 1);
	if(!res) {
		printf("error\n");
	}	
	while(files_or_dirs[i]) {
		res[i] = ft_strjoin(dir_, files_or_dirs[i]);
		i++;
	}
	return(res);
}
