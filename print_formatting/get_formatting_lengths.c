#include "../inc/ft_ls.h"

void	set_file_size_column_length(t_lengths *formatting_info, struct stat statbuf) {
	int hex_len;
	int num;
	char hex[20];
	
	hex_len = 0;
	if (S_ISCHR(statbuf.st_mode) || S_ISBLK(statbuf.st_mode)) {
		num = makedev(major(statbuf.st_rdev), minor(statbuf.st_rdev));
		decimalToHex(num, hex);
		hex_len = ft_strlen(hex) + 2;
	}
	if (hex_len > formatting_info->size)
		formatting_info->size = hex_len;
}


t_lengths	get_formatting_lengths(char **file_or_dir_paths) {
	int	i;
	struct stat statbuf;
	t_lengths	formatting_info;

	formatting_info = initialize_t_lengths();
	i = 0;
	while (file_or_dir_paths[i]) {
		lstat(file_or_dir_paths[i], &statbuf);
		if(ft_numlen(statbuf.st_nlink) > formatting_info.links)
			formatting_info.links = ft_numlen(statbuf.st_nlink);
		formatting_info = set_column_sizes(formatting_info, statbuf);
		set_file_size_column_length(&formatting_info, statbuf);
		if(ft_numlen(statbuf.st_size) > formatting_info.size)
			formatting_info.size = ft_numlen(statbuf.st_size);
		i++;
		formatting_info.count += statbuf.st_blocks;	
	}
	return (formatting_info);
}
