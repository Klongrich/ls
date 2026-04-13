#include "../inc/ft_ls.h"

void	put_file_name(char *file_path, t_flags *flags) {
	if (flags->d) {
		if(is_file(file_path, flags)) {
			file_path++;
			file_path++;
		}
		ft_printf("%s\n", file_path);
	} else if(file_path[0] != '/') {
		file_path++;
		file_path++;
		printf("%s\n", file_path);
	} else {
		print_file_name(file_path, 1, flags);
	}
}

void	print_dl_single(char *file_path, t_flags *flags) {
	if(is_file(file_path, flags) && file_path[0] == '.') {
		file_path++;
		file_path++;
	}	
	print_color_d_flag(file_path, flags);
}

void	print_single_file_long_format(char *file_path, t_flags *flags) {
	t_lengths	formatting_lengths;
	struct stat	statbuff;

	formatting_lengths = get_single_file_formatting_lengths(file_path);
	lstat(file_path, &statbuff);
	print_permissions(statbuff, file_path);
	print_name_and_grid(formatting_lengths, statbuff);
	print_file_size(statbuff, formatting_lengths);
	if(flags->t & flags->u)
		print_last_time_accessed(statbuff);
	else
		print_last_time_modified(statbuff);	
	if(flags->color & isatty(STDOUT_FILENO)) {
		if (flags->d) 
			print_dl_single(file_path, flags);
		else
			print_color_single(file_path, 1, 1);
	} else {
		if(check_files_link(file_path)) {
			print_file_name(file_path, 1, flags);
		} else {
			put_file_name(file_path, flags);
		}
	}
}
