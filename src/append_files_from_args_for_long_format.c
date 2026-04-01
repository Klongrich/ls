#include "../inc/ft_ls.h"

char	**append_files_from_args_for_long_format(char *dir, char **files) {
	int i;
	int j;
	char **res;

	j = 0;
	i = 0;
	res = (char **)malloc(sizeof(char *) * get_size(files) + 1);
	if(!res) {
		printf("error\n");
	}	
	while(files[i]) {
		if(files[i][0] != '/') {
			res[j] = ft_strjoin(dir, files[i]);
		} else {
			res[j] = (char *)malloc(sizeof(char) * ft_strlen(files[i]) + 1);
			ft_strcpy(res[j], files[i]);
		}
		i++;
		j++;
	}
	res[j] = 0;
	return(res);
}
