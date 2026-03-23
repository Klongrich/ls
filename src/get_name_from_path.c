#include "../inc/ft_ls.h"

char	*get_name_from_path(char *path) {
	int i;
	int len;
	char *res;

	i = 0;
	len = ft_strlen(path);
	res = (char *)malloc(sizeof(char) * MAX_FILE_LENGTH);
//	printf("len before: %d\n", len);
	while(path[len] != '/')	{
//		printf("checking characters %c\n", path[len]);
		len--;
	}		
//	printf("len after: %d\n", len);
	len++;	
	while(path[len]) {
		res[i] = path[len];
		i++;
		len++;
	}
	return (res);
}
