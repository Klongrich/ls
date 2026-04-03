#include "../inc/ft_ls.h"

t_lengths	get_single_file_formatting_lengths(char *file_path) {
	struct stat statbuf;
	t_lengths	formatting_info;

	formatting_info = initialize_t_lengths();

	lstat(file_path, &statbuf);
	formatting_info.links = ft_numlen(statbuf.st_nlink);	
	formatting_info = set_column_sizes(formatting_info, statbuf);
	formatting_info.size = ft_numlen(statbuf.st_size);
	formatting_info.count += statbuf.st_blocks;	
	return (formatting_info);
}
