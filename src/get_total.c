#include "../inc/ft_ls.h"

t_lengths	get_total(char	**file_or_dir_paths) {
	int	i;
	struct stat statbuf;
	t_lengths	formatting_info;

	formatting_info = initialize_t_lengths();
	i = 0;

	while (file_or_dir_paths[i]) {
		lstat(file_or_dir_paths[i], &statbuf);
		formatting_info = set_column_sizes(formatting_info, statbuf);
		i++;
		formatting_info.count += statbuf.st_blocks;	
	}
	return (formatting_info);
}
