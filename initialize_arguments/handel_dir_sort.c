#include "../inc/ft_ls.h"

char    **handel_dir_sort(char **dirs, t_flags *flags) {
	char **sorted_dirs;
  	
	if(flags->f) {
		sorted_dirs = dirs;
	} else if (flags->t) {
		if (flags->u) {
			sorted_dirs =  last_time_accessed_sort(dirs, flags->r);
		} else {
			sorted_dirs = time_sort(dirs, flags->r);
		}
	} else {
		sorted_dirs = bubble_sort(dirs, flags->r, get_size(dirs));
	}
	return (sorted_dirs);
}
