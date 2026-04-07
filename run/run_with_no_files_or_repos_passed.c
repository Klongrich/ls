#include "../inc/ft_ls.h"

void	run_with_no_files_or_repos_passed(t_flags *flags) {
	char **temp;
	char **temp3;
	char **temp4;	

	if(flags->recur) {
		temp3 = read_dir(".", flags);
		temp4 = append_dir("./", temp3);;
		recur(temp4, flags);
		free_list(temp3);
		free_list(temp4);
	} else {
		temp = read_dir(".", flags);
		free_list(temp);
	}
}
