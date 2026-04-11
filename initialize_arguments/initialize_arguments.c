#include "../inc/ft_ls.h"


void	init_parsed_argv(char **parsed_argv, char **argv, int i, int j) {
	while(argv[i]) {
		parsed_argv[j] = (char *)malloc(sizeof(char ) * MAX_PATH_LENGTH + 1);
		parsed_argv[j]= ft_strcpy(parsed_argv[j], argv[i]);
		i++;
		j++;
        }
}

void initialize_arguments(char **argv, t_flags *flags, int i){
	char **parsed_argv;
	int j;
	
	j = 0;
	parsed_argv = (char **)malloc(sizeof(char *) * get_size(argv) + 1 - i);
	if (!parsed_argv) {
		printf("error mallocing\n");
	}
	if (!argv[i] || (!ft_strcmp(argv[i], "--"))) {
		run_with_no_files_or_repos_passed(flags);	
	} else {
		init_parsed_argv(parsed_argv, argv, i, j);
		sort_then_run_argv(parsed_argv, flags);
	}
	free_list(parsed_argv);
}
