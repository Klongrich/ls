#include "../inc/ft_ls.h"

void	print_file_name(char *filepath, int is_single_file)
{
	size_t			len;
	char			buff[1024];
	char			*name;

	if (!is_single_file)
		name = get_name_from_path(filepath);
	else
		name = filepath;
	if (check_files_link(filepath))
	{
		len = readlink(filepath, buff, 1023);
		buff[len] = '\0';
		if (name[0] != '/' && is_single_file){
			name++;
			name++;
		}
		ft_printf("%s -> %s\n", name, buff);
	}
	else
		ft_printf("%s\n", name);
	if (!is_single_file)
		free(name);
}
