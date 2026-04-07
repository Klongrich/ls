#include "../inc/ft_ls.h"

void	handel_printing(char **all_files_or_directories, t_flags *flags) {
	if(flags->l)
		print_long_format(all_files_or_directories);
	if(flags->color & !flags->l)
		print_color(all_files_or_directories);    
	if (flags->l || flags->t || flags->color) 
		cut_file_path_from_files_or_dirs(all_files_or_directories);
	if(!flags->l & !flags->color)
		print_list(all_files_or_directories);
}

char 	**read_dir(char *dir_path, t_flags *flags){
	int repo_or_file_count;
	char **all_files_or_directories;

	repo_or_file_count = get_repo_or_file_count(dir_path, flags->a, flags->l);	
	if (!repo_or_file_count) {
		return(0);
	} else {
		all_files_or_directories = (char **)malloc(sizeof(char *) * repo_or_file_count + 1);
		if(flags->a) 
			read_dir_with_hidden_files(all_files_or_directories, dir_path, flags);
		else
			read_dir_standard(all_files_or_directories, dir_path, flags);
		if (flags->t) {
			if(flags->u) 
				merge_last_time_accessed_sort(all_files_or_directories, 0, get_size(all_files_or_directories) - 1, flags->r);
			else
				merge_time_sort(all_files_or_directories, 0, get_size(all_files_or_directories) - 1, flags->r);
		} else 
			merge_sort2(all_files_or_directories, 0, get_size(all_files_or_directories) - 1, flags->r);
		handel_printing(all_files_or_directories, flags);
		return(all_files_or_directories);
	}
}

