#include "ft_ls.h"

char	*cut_file_path_for_printing_file_passed_in_args(char *str) {
	char *res;
	int i;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (str[0] != '/') {
		while(str[i + 2]) {
			res[i] = str[i + 2];
			i++;
		}
	} else {
		ft_strcpy(res, str);
	}		
	return(res);
}
