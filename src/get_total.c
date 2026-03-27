#include "../inc/ft_ls.h"

t_lengths	get_total(char	**file_or_dir_paths) {
	int	i;
	struct stat statbuf;
	t_lengths	file_or_dir_info;

	file_or_dir_info = initialize_t_lengths();
	i = 0;

	while (file_or_dir_paths[i]) {
		lstat(file_or_dir_paths[i], &statbuf);
		i++;
		file_or_dir_info.count += statbuf.st_blocks;	
	}
	return (file_or_dir_info);
}
