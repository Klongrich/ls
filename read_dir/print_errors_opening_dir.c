#include "../inc/ft_ls.h"

void	print_errors_opening_dir(int l_flag, char *dir_path) {
	if(l_flag)
		ft_putstr("total 0\n");
	if(errno == EACCES) {
		printf("ls: %s: Permission denied\n", dir_path);
	} else if (errno == EPERM) {
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(dir_path, 2);
		ft_putstr_fd(" Operation not permitted\n", 2);
	}
}
