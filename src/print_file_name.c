#include "../inc/ft_ls.h"

int	check_files_link(char *str)
{
	struct stat stuff;

	lstat(str, &stuff);
	if (S_ISLNK(stuff.st_mode))
		return(1);
	else
		return(0);
}

void	print_file_name(char *filepath)
{
	size_t			len;
	char			buff[1024];
	char			*name;

	name = get_name_from_path(filepath);
	if (check_files_link(filepath))
	{
		len = readlink(filepath, buff, 1023);
		buff[len] = '\0';
		ft_printf("%s -> %s\n", name, buff);
	}
	else
		ft_printf("%s\n", name);
	free(name);
}
