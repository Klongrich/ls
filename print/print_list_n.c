#include "../inc/ft_ls.h"

void	print_list_n(char **str, int n) {
	while(str[n]) {
		printf("%s\n", str[n]);
		n++;
	}
}
