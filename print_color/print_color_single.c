#include "ft_ls.h"

int	check_isdir_isexecutable(struct stat data, struct stat ldata, char *path, int is_from_args) {
	if(S_ISDIR(data.st_mode)) {
		if(ldata.st_mode & S_ISVTX)
			print_color_text(path, BLACK_GREEN, is_from_args);
		else if (ldata.st_mode & S_IWOTH)
			print_color_text(path, BLACK_YELLOW, is_from_args);	
		else
			print_color_text(path, BLUE, is_from_args);
		return (1);
	} else if (S_ISREG(data.st_mode) && access(path, X_OK) == 0) {
       	 	if (ldata.st_mode & S_ISUID)
			print_color_text(path, BLACK_RED, is_from_args);
		else if (ldata.st_mode & S_ISGID)
			print_color_text(path, BLACK_CYAN, is_from_args);
		else
			print_color_text(path, RED, is_from_args);
		return (1);
	}
	return (0);
}

void	print_color_single(char *path, int is_from_args, int l_flag) {
	struct stat data;
	struct stat ldata;

	stat(path, &data);
	lstat(path, &ldata);
	if(S_ISLNK(ldata.st_mode)) {
		if(l_flag)
			print_colored_link(path, MAGENTA, is_from_args);
		else
			print_color_text(path, MAGENTA, is_from_args);
	} else if (check_isdir_isexecutable(data, ldata, path, is_from_args) ){ 
	} else if (S_ISCHR(ldata.st_mode)) {
		print_color_text(path, BLUE_YELLOW, is_from_args);
	} else if (S_ISBLK(ldata.st_mode)) {
		 print_color_text(path, BLUE_CYAN, is_from_args);
	} else if (S_ISSOCK(ldata.st_mode)) {
		print_color_text(path, GREEN, is_from_args);
	} else if (S_ISFIFO(ldata.st_mode)) {
		print_color_text(path, YELLOW, is_from_args);
	} else {
		print_color_normal_file(is_from_args, path);
	}
}
