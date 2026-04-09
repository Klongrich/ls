#include "../inc/ft_ls.h"

char	**get_dirs_from_args(char **list_of_args, t_flags *flags) {
	int i;
	int j;
	char **result;

	j = 0;
	i = 0;
	result = (char **)malloc(sizeof(char *) * get_size(list_of_args) + 1);
	while (list_of_args[i]) {
		if (is_dir(list_of_args[i], flags)) {
			result[j] = list_of_args[i];
			j++;
		}
		i++; 
	}
	return (result);
}
