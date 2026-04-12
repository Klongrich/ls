#include "../inc/ft_ls.h"

void	print_link(char *filepath, int is_single_file, char *name) {
	size_t	len;
	char	buff[1024];
	
	len = readlink(filepath, buff, 1023);
	buff[len] = '\0';
	if (name[0] != '/' && is_single_file){
		name++;
		name++;
	}
	ft_printf("%s -> %s\n", name, buff);
}

void	print_file_name(char *filepath, int is_single_file, t_flags *flags) {
	char	*name;

	if (!is_single_file && !flags->d)
		name = get_name_from_path(filepath);
	else
		name = filepath;
	if (check_files_link(filepath) & !flags->color) {
		print_link(filepath, is_single_file, name);
	} else {
		if (flags->color & isatty(STDOUT_FILENO))
			print_color_single(filepath, 0, 1);
		else
			ft_printf("%s\n", name);
	}
	if (!is_single_file && !flags->d)
		free(name);
}
