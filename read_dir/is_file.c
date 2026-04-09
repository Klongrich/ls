#include "../inc/ft_ls.h"


bool	is_block_device(mode_t file_type) {
	if(S_ISBLK(file_type))
		return (true);
	return (false);
}

int	is_regular_file(mode_t file_type) {
	return (S_ISREG(file_type));
}

int	is_file(const char *path, t_flags *flags){
	struct stat path_stat;

	if ((lstat(path, &path_stat)) == -1)
		return(0);
	//mode_t file_type = path_stat.st_mode & S_IFMT;
	//printf("mode_t: %hu\n", file_type);
	
	//Character device (e.g. /dev/tty)
	if (S_ISCHR(path_stat.st_mode)) {
		return (1);
	}

	//Socket file (e.g. /mysql/socket
	if (S_ISSOCK(path_stat.st_mode)){
		return (1);
	}
	if (is_block_device(path_stat.st_mode))
		return(1);
	if(flags->l || flags->color) {
		//Symoblic Link (e.g. /home -> );
		if (S_ISLNK(path_stat.st_mode)) {
			return(1);
		}
	}

	//Regular files?
	/*
	if (file_type == S_IFREG) {
		printf("S_IFREG\n");
		return(1);\
	}
	*/
	return(is_regular_file(path_stat.st_mode));

}
