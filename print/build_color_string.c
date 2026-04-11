#include "ft_ls.h"

char	*build_color_string(char *str, char *color) {
	char	*res;
	char	*temp;

	temp = ft_strjoin(color, str);
	res = ft_strjoin(temp, RESET);
	free(temp);
	return (res);
}
