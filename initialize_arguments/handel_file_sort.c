#include "../inc/ft_ls.h"

char    **handel_file_sort(char **files, t_flags *flags) {
	char **sorted_files;
  	
	if(flags->f) {
		sorted_files = files;
	} else if (flags->t) {
		if (flags->u) {
			sorted_files =  last_time_accessed_sort(files, flags->r);
		} else {
			sorted_files = time_sort(files, flags->r);
		}
	} else {
		sorted_files = bubble_sort(files, flags->r, get_size(files));
	}
	return (sorted_files);
}
