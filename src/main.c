#include "../inc/ft_ls.h"

void read_dir(){
	DIR	*dir;
	struct dirent *dp;
	int repo_or_file_count;
	char **all_files_or_directories;
	int i;

	i = 0;
	dir = opendir(".");
	repo_or_file_count = 0;
	if (!dir)
		printf("Error\n");

	//Counting the amount of character array's we have to allocate
	while ((dp = readdir(dir))) {
		if (!(dp->d_name[0] == '.')) {
			repo_or_file_count++;
		}
	}
	closedir(dir);	

	//Allocating character array
	all_files_or_directories = (char **)malloc(sizeof(char *) * repo_or_file_count + 1);
	if (!all_files_or_directories)
		printf("Error mallocing\n");

	//Copying data into our new array
	dir = opendir(".");
	while ((dp = readdir(dir))) {
		if (!(dp->d_name[0] == '.')) {
			all_files_or_directories[i] = ft_memalloc(ft_strlen(dp->d_name) + 1);
			all_files_or_directories[i] = ft_strcpy(all_files_or_directories[i], dp->d_name);
			i++;		
		}
	}
	closedir(dir);
	
	//Sorting our array a to z
	all_files_or_directories = bubble_sort(all_files_or_directories);

	int k;

	k = 0;
	while (all_files_or_directories[k]) {
		printf("%s\n", all_files_or_directories[k]);
		free(all_files_or_directories[k]);
		k++;
	}
	free(all_files_or_directories);
}


void run_recur(char **argv, t_flags *flags, int i) {
	while (argv[i]) {
		printf("%s\n", argv[i]);
		i++;
	}
	print_flags(flags);
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
			
			if (i + 1 == argc) {
				getting_flags = 0;
			}

			if (!getting_flags) {
				if (argv[i][0] == '-' && argv[i][1] == '-' && !dashdash_found && !dash_found) {
					dashdash_found = 1;
				} else {
					
					if(flags.recur) {
						run_recur(argv, &flags, i);
						return(0);
					}
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
	//print_flags(&flags);
	return(0);
}
