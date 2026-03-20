#include "../inc/ft_ls.h"

int	check_end(char *dir_path) {
	if(dir_path[ft_strlen(dir_path) - 1] == '/')
		return (1);
	else
		return (0);

}
