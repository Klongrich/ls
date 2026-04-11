#include "ft_ls.h"

void	print_colored_link(char *str, char *color, int is_from_args) {
	size_t	len;
	char	buff[1024];

	len = readlink(str, buff, 1023);
	buff[len] = '\0';
	
	print_colored_text_no_newline(str, color, is_from_args);
	ft_printf(" -> %s\n", buff);
}
