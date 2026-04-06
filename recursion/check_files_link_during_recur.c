#include "../inc/ft_ls.h"

int	check_files_link_during_recur(char *str){
	char *file_path;
	int res;

	file_path = ft_strjoin("./", str);
	res = check_files_link(file_path);
	free(file_path);
	return(res);
}
