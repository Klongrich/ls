#include "../inc/ft_ls.h"

void	run_one_valid_dir(char **sorted_dirs, t_flags *flags) {
	char **temp;
		
	if (flags->d) {
		if (flags->l) {
			print_single_file_long_format(sorted_dirs[0], flags);
		} else if ((flags->color & isatty(STDOUT_FILENO))) {
			print_color_d_flag(sorted_dirs[0], flags);
		} else {
			ft_printf("%s\n", sorted_dirs[0]);
		}
	} else {
		temp = read_dir(sorted_dirs[0], flags);
		if(temp)
			free_list(temp);
	}
}


void	run_one_valid_file(char **sorted_files, t_flags *flags) {
	char *long_temp;	

	if (flags->l || (flags->color & isatty(STDOUT_FILENO))) {
		if (sorted_files[0][0] != '/') {
			long_temp = ft_strjoin("./", sorted_files[0]);
			if(flags->color & !flags->l)
				print_color_single(long_temp, 1, 0);
			else
				print_single_file_long_format(long_temp, flags);
			free(long_temp);
		} else {
			if(flags->color & !flags->l)
				print_color_single(sorted_files[0], 1, 0);
			else 
			print_single_file_long_format(sorted_files[0], flags);
		}
	} else {
		ft_printf("%s\n", sorted_files[0]);
	}
}

void	run_one_valid_argument(char **sorted_dirs, char **sorted_files, t_flags *flags) {
	if (sorted_dirs[0] != NULL) {
		run_one_valid_dir(sorted_dirs, flags);
	} else {
		run_one_valid_file(sorted_files, flags);
	}
}
