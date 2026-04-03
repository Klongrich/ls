#include "../inc/ft_ls.h"

char	**bubble_sort(char **str, int r_flag, int number_of_strs) {
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < number_of_strs - 1) {
		j = 0;
		while (j < number_of_strs - i - 1) {
			if (r_flag) 
				compare_str_bubble_reverse(str, j);
			 else 
				compare_str_bubble_normal(str, j);
			j++;
		}
		i++;
	}
	return (str);
}
