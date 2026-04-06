#include "../inc/ft_ls.h"

void	run_one_valid_argument(char **sorted_dirs, char **sorted_files, t_flags *flags) {
	char **temp;
	char *long_temp;

	if (sorted_dirs[0] != NULL) {
		temp = read_dir(sorted_dirs[0], flags);
		if(temp)
			free_list(temp);
	} else {
		if (flags->l) {
			if (sorted_files[0][0] != '/') {
				long_temp = ft_strjoin("./", sorted_files[0]);
				print_single_file_long_format(long_temp);
				free(long_temp);
			}
			else {
				print_single_file_long_format(sorted_files[0]);
			}
		} else {
			ft_printf("%s\n", sorted_files[0]);
		}
	}
}
