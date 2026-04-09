#include "../inc/ft_ls.h"

void	run_dirs(char **sorted_dirs, t_flags *flags) {
	int i;
	char **temp;
	int sorted_dirs_size;

	i = 0;
	sorted_dirs_size = get_size(sorted_dirs);
        while (sorted_dirs[i]) {
		ft_printf("%s:\n", sorted_dirs[i]);
                temp = read_dir(sorted_dirs[i], flags);
		if (i + 1 != sorted_dirs_size)
			ft_printf("\n");
		if (temp)
			free_list(temp);
		 i++;
	}
}


void	run_files(char **sorted_files, char **sorted_dirs, t_flags *flags) {
	int i;
	char **all_files_appended;

	i = 0;
	if(sorted_files[0] != NULL) { 
		if(flags->l || flags->color) {
			if(flags->color & !flags->l) {
				all_files_appended = append_files_from_args_for_long_format("./", sorted_files);
				print_color(all_files_appended, 1, 0);
				free_list(all_files_appended);
			} else 
				print_long_format_files_from_args(sorted_files, flags);
                  } else {
                          while(sorted_files[i]) {
                                  ft_printf("%s\n", sorted_files[i]);
                                  i++;    
                         }       
                  }       
                  if(sorted_dirs[0] != NULL)
                          printf("\n");
          }  
}

void	run_multiple_arguments(char **sorted_files, char **sorted_dirs, t_flags *flags) {
	run_files(sorted_files, sorted_dirs, flags);
	run_dirs(sorted_dirs, flags);
}


