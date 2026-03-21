#include "../inc/ft_ls.h"

char	**bubble_sort(char **str, int r) {

	int i;
	int j;
	int size;
	char temp[MAX_FILE_LENGTH];

	size = get_size(str);
	i = 0;
	j = 0;
	while (i < size - 1) {
		j = 0;
		while (j < size - i - 1) {
			if (r) {
				if (compare_strs_lowercase(str[j], str[j + 1]) < 0) {
					ft_strcpy(temp, str[j]);
					ft_strcpy(str[j], str[j + 1]);
					ft_strcpy(str[j + 1], temp);
				}
			} else {
				if (compare_strs_lowercase(str[j], str[j + 1]) > 0) {
					ft_strcpy(temp, str[j]);
					ft_strcpy(str[j], str[j + 1]);
					ft_strcpy(str[j + 1], temp);
				}
			}
			j++;
		}
		i++;
	}
	return (str);
}
