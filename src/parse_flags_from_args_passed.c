#include "../inc/ft_ls.h"

int	final_flag_parse_from_args(char **argv, int i, t_dash dash_check, t_flags flags) {	
	if (argv[i][0] == '-' && argv[i][1] == '-' && !dash_check.dash_found && !dash_check.dashdash_found && argv[i + 1]) {
		return (2);
	} else {
		if (is_flag(argv[i]) && !dash_check.dashdash_found)
			i++;
		initalize_arguments(argv, &flags, i);
		return (1);
	}
	return(0);
}

int	quick_check(char **argv, int argc, int i, int getting_flags) {
	if(argv[i][0] != '-' || i + 1 == argc)
		return (0);
	return (getting_flags);
}

void	parse_flags_from_args_passed(char **argv, int argc, t_flags flags, int i) {
	int getting_flags;
	t_dash dash_check;
	
	getting_flags = 1;

	dash_check.dash_found = 0;
	dash_check.dashdash_found = 0;
	while (argv[i++]) {
		if (argv[i][0] == '-' && getting_flags) {
			if (!argv[i][1]) {
				dash_check.dash_found = 1;
				getting_flags = 0;
			} else if (argv[i][1] == '-' && !argv[i][2]) {
				getting_flags = 0;
			} else if ((parse_flags(argv[i], &flags) == 0))
				break;
		}
		getting_flags = quick_check(argv, argc, i, getting_flags);
		if (!getting_flags) {
			dash_check.dashdash_found = final_flag_parse_from_args(argv, i, dash_check, flags);
			if(dash_check.dashdash_found == 1) 
				break; 
		}
	}
}
