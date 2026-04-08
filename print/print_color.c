#include "../inc/ft_ls.h"

#define BLUE		"\033[34m"
#define RED		"\033[31m"
#define RESET  		"\033[0m"
#define MAGENTA 	"\033[35m"
#define BLUE_YELLOW	"\033[34;43m"
#define BLUE_CYAN	"\033[34;46m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define RED_BACKGROUND	"\033[41m"
#define CYAN_BACKGROUND "\033[46m"
#define GREEN_BACKGROUND "\033[42m"
#define YELLOW_BACKGROUND "\033[43m"

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

void	print_color_single(char *path) {
	struct stat data;
	struct stat ldata;

	stat(path, &data);
	lstat(path, &ldata);
	if(S_ISLNK(ldata.st_mode)) {
		print_color_text(path, MAGENTA);
	} else if(S_ISDIR(data.st_mode)) {
		if(ldata.st_mode & S_ISVTX)
			print_color_text(path, GREEN_BACKGROUND);
		else if (ldata.st_mode & S_IWOTH)
			print_color_text(path, YELLOW_BACKGROUND);	
		else
			print_color_text(path, BLUE);
	} else if (S_ISREG(data.st_mode) && access(path, X_OK) == 0) {
       	 	if (ldata.st_mode & S_ISUID)
			print_color_text(path, RED_BACKGROUND);
		else if (ldata.st_mode & S_ISGID)
			print_color_text(path, CYAN_BACKGROUND);
		else
			print_color_text(path, RED);
    	} else if (S_ISCHR(ldata.st_mode)) {
		print_color_text(path, BLUE_YELLOW);
	} else if (S_ISBLK(ldata.st_mode)) {
		 print_color_text(path, BLUE_CYAN);
	} else if (S_ISSOCK(ldata.st_mode)) {
		print_color_text(path, GREEN);
	} else if (S_ISFIFO(ldata.st_mode)) {
		print_color_text(path, YELLOW);
	} 
	else {
		ft_printf("%s\n", get_name_from_path(path));
	}
}


void	print_color(char **paths) {
	int i;

	i = 0;
	while(paths[i]) {
		print_color_single(paths[i]);	
		i++;
	}
}
