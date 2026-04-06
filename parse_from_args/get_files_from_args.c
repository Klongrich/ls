#include "../inc/ft_ls.h"

char	**get_files_from_args(char **list_of_args, int l_flag) {
	int i;
	int j;
	char **result;

	i = 0;
	j = 0;
	result = (char **)malloc(sizeof(char *) * get_size(list_of_args) + 1);
	while (list_of_args[i]) {
		if(is_file(list_of_args[i], l_flag)) {
			result[j] = list_of_args[i];
			j++;
		}
		i++;
	}
	return (result);

}