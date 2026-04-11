#include "ft_ls.h"

void	print_color_text(char *str, char *color, int is_from_args) {
	char *msg;
	char *name;

	if(is_from_args) {
		if (str[0] != '/')
			name = cut_file_path_for_printing_file_passed_in_args(str);
		else
			name = str;
	} else
		name = get_name_from_path(str);
	msg = build_color_string(name, color);
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	free(msg);
	if(!is_from_args)
		free(name);
	if (is_from_args && str[0] != '/')
		free(name);
	ft_printf("\n");
}
