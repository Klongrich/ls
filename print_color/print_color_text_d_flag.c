#include "ft_ls.h"

void	print_color_text_d_flag(char *str, char *color) {
	char *msg;
	
	msg = build_color_string(str, color);
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	free(msg);
	ft_printf("\n");
}
