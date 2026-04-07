#include "../inc/ft_ls.h"

#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET   "\033[0m"

char	*build_color_string(char *str, char *color) {
	char	*res;
	char	*temp;

	temp = ft_strjoin(color, str);
	res = ft_strjoin(temp, RESET);
	free(temp);
	return (res);
}

void	print_color_text(char *str, char *color) {
	char *msg;

	msg = build_color_string(get_name_from_path(str), color);
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	free(msg);
	ft_printf("\n");
}

void	print_color(char **paths) {
	int i;
	struct stat data;

	i = 0;
	while(paths[i]) {
		stat(paths[i], &data);
		if(S_ISDIR(data.st_mode)) {
			print_color_text(paths[i], BLUE);
		}
	   	else if (S_ISREG(data.st_mode) && access(paths[i], X_OK) == 0) {
       	 		print_color_text(paths[i], RED);
    		} else {
			ft_printf("%s\n", get_name_from_path(paths[i]));
		}
		i++;
	}
}
