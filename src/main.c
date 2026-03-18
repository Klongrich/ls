#include "../inc/ft_ls.h"

void read_dir(){
	DIR	*dir;
	struct dirent *dp;

	dir = opendir(".");
	
	if (!dir)
		printf("Error\n");

	while ((dp = readdir(dir))) {
		printf("%s\n", dp->d_name);
	}
}

int is_file(const char *path) {	
	printf("is_file path: %s\n", path);
	struct stat path_stat;

	if((stat(path, &path_stat)) == -1)
		return(0);
	mode_t file_type = path_stat.st_mode & S_IFMT;
	printf("mode_t: %hu\n", file_type);

	//Character device (e.g. /dev/tty)
	if (S_ISCHR(path_stat.st_mode)) {
		return(1);
	}
	//Block device (eg /dev/sda)
	if (S_ISBLK(path_stat.st_mode)){
		return(1);
	}
	
	//Regular Files?
	/*
	if (file_type == S_IFREG) {
		printf("S_IFREG\n");
		return (1);
	}
	*/
	return(S_ISREG(path_stat.st_mode));
}

int 	main(int argc, char **argv){

	t_flags flags;	
	int i;
	int getting_flags;
	int dash_found;
	int dashdash_found;

	i = 0;
	getting_flags = 1;
	dashdash_found = 0;
	dash_found = 0;
	initialize_flags(&flags);
	if (argc == 0) {
		return (0);
	}
	if (argc == 1){
		printf("%s\n", argv[0]);
	}
	if (argc > 1) {
		i = 1;
		while (argv[i]) {
			if (argv[i][0] == '-' && getting_flags) {
				if (!argv[i][1]) {
					getting_flags = 0;
					dash_found = 1;
				} else if (argv[i][1] == '-' && !argv[i][2]) {
					getting_flags = 0;
				} else {
					if((parse_flags(argv[i], &flags) == 0)) {
						printf("error, invalid flag. Usage: [-lratR]\n");
						return (0);
					}
				}
			}
			if (argv[i][0] != '-') {
				getting_flags = 0;
			}

			if (!getting_flags) {
				if (argv[i][0] == '-' && argv[i][1] == '-' && !dashdash_found && !dash_found) {
					dashdash_found = 1;
				} else {
					if (is_dir(argv[i])) {
						printf("is a dir\n");
					}
					if (is_file(argv[i])) {	
						printf("is a file\n");
					}
				}
			}
			i++;
		}
	
	}
	print_flags(&flags);
	return(0);
}
