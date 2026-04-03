#include "../inc/ft_ls.h"

void	compare_str_bubble_reverse(char **str, int j) {
	if (compare_strs_lowercase(str[j], str[j + 1]) < 0) {
		bubble_swap(&str[j], &str[j + 1]);
	}
}
