#include "../inc/ft_ls.h"

char	*get_name_from_path(char *path) {
	int i;
	int len;
	char *res;

	i = 0;
	len = ft_strlen(path);
	res = (char *)malloc(sizeof(char) * MAX_FILE_LENGTH);

	while(path[len] != '/')	{
		len--;
	}		
	len++;	
	while(path[len]) {
		res[i] = path[len];
		i++;
		len++;
	}
	return (res);
}
