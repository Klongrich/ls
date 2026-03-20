#include "../inc/ft_ls.h"

int	is_file(const char *path){
	struct stat path_stat;

	if ((stat(path, &path_stat)) == -1)
		return(0);
	mode_t file_type = path_stat.st_mode & S_IFMT;
	//printf("mode_t: %hu\n", file_type);
	
	//Character device (e.g. /dev/tty)
	if (S_ISCHR(path_stat.st_mode)) {
		return (1);
	}

	//Block device (eg /dev/sda)
	if (S_ISBLK(path_stat.st_mode)){
		return(1);
	}
	//Regular files?
	/*
	if (file_type == S_IFREG) {
		printf("S_IFREG\n");
		return(1);\
	}
	*/
	return(S_ISREG(path_stat.st_mode));

}
