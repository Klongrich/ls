#include "../inc/ft_ls.h"

void	bubble_swap(char **str_one, char **str_two) {
	char *temp;

	temp = *str_one;
	
	*str_one = *str_two;
	*str_two = temp;
}
