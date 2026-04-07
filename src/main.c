#include "../inc/ft_ls.h"

int 	main(int argc, char **argv){
	t_flags flags;	
	char **temp;
	int i;

	i = 0;
	initialize_flags(&flags);
	if (argc == 0) {
		return (0);
	}
	if (argc == 1){
		temp = read_dir(".", &flags);	
		free_list(temp);		
	}
	if (argc > 1) {
		parse_flags_from_args_passed(argv, argc, flags, i);
	}
	return (0);
}
