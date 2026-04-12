#include "ft_ls.h"

int	check_isdir_isexecutable_d_flag(struct stat data, struct stat ldata, char *path) {
	if(S_ISDIR(data.st_mode)) {
		if(ldata.st_mode & S_ISVTX)
			print_color_text_d_flag(path, BLACK_GREEN);
		else if (ldata.st_mode & S_IWOTH)
			print_color_text_d_flag(path, BLACK_YELLOW);	
		else
			print_color_text_d_flag(path, BLUE);
		return (1);
	} else if (S_ISREG(data.st_mode) && access(path, X_OK) == 0) {
       	 	if (ldata.st_mode & S_ISUID)
			print_color_text_d_flag(path, BLACK_RED);
		else if (ldata.st_mode & S_ISGID)
			print_color_text_d_flag(path, BLACK_CYAN);
		else
			print_color_text_d_flag(path, RED);
		return (1);
	}
	return (0);
}

void	print_color_d_flag(char *path, t_flags *flags) {
	struct stat data;
	struct stat ldata;

	stat(path, &data);
	lstat(path, &ldata);
	if(S_ISLNK(ldata.st_mode)) {
		if(flags->l)
			print_colored_link(path, MAGENTA, 0);
		else
			print_color_text_d_flag(path, MAGENTA);
	} else if (check_isdir_isexecutable_d_flag(data, ldata, path) ){ 
	} else if (S_ISCHR(ldata.st_mode)) {
		print_color_text_d_flag(path, BLUE_YELLOW);
	} else if (S_ISBLK(ldata.st_mode)) {
		 print_color_text_d_flag(path, BLUE_CYAN);
	} else if (S_ISSOCK(ldata.st_mode)) {
		print_color_text_d_flag(path, GREEN);
	} else if (S_ISFIFO(ldata.st_mode)) {
		print_color_text_d_flag(path, YELLOW);
	} else {
		print_color_normal_file(0, path);
	}
}

void	print_all_color_d_flag(char **paths, t_flags *flags) {
	int i;

	i = 0;
	while (paths[i]) {
		print_color_d_flag(paths[i], flags);
		i++;
	}
}



