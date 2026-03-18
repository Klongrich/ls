#include "../inc/ft_ls.h"

void read_dir(){
	DIR	*dir;
	struct dirent *dp;

	dir = opendir(".");
	
	if (!dir)
		printf("Error\n");

	while ((dp = readdir(dir))) {
		if (!(dp->d_name[0] == '.')) {
			printf("%s\n", dp->d_name);
		}
	}
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
		read_dir();
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
					else if (is_file(argv[i])) {	
						printf("is a file\n");
					}
					else {
						printf("ls: %s: no such file or directory\n", argv[i]);
					}
				}
			}
			i++;
		}
	
	}
	print_flags(&flags);
	return(0);
}
