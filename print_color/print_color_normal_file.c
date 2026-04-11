#include "ft_ls.h"

void	print_color_normal_file(int is_from_args, char *path) {
	char *temp;

	if(is_from_args) {
		temp = cut_file_path_for_printing_file_passed_in_args(path);
		ft_printf("%s\n", temp);	
		free(temp);
	} else {
		temp = get_name_from_path(path);
		ft_printf("%s\n", temp);
		free(temp);
	}
}
