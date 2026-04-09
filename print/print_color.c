#include "../inc/ft_ls.h"

#define BLUE		"\033[34m"
#define RED		"\033[31m"
#define RESET  		"\033[0m"
#define MAGENTA 	"\033[35m"
#define BLUE_YELLOW	"\033[34;43m"
#define BLUE_CYAN	"\033[34;46m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLACK_RED	"\033[30;41m"
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
char	*cut_file_path_for_printing_file_passed_in_args(char *str) {
	char *res;
	int i;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (str[0] != '/') {
		while(str[i + 2]) {
			res[i] = str[i + 2];
			i++;
		}
	}		
	return(res);
}


void	print_color_text(char *str, char *color, int is_from_args) {
	char *msg;
	char *name;

	if(is_from_args) {
		if (str[0] != '/')
			name = cut_file_path_for_printing_file_passed_in_args(str);
		else
			name = str;
	} else
		name = get_name_from_path(str);
	msg = build_color_string(name, color);
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	free(msg);
	if(!is_from_args)
		free(name);
	if (is_from_args && str[0] != '/')
		free(name);
	ft_printf("\n");
}

void	print_color_text_no_newline(char *str, char *color, int is_from_args) {
	char *msg;
	char *name;

	if(is_from_args) {
		if (str[0] != '/')
			name = cut_file_path_for_printing_file_passed_in_args(str);
		else
			name = str;
	} else
		name = get_name_from_path(str);
	msg = build_color_string(name, color);
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	free(msg);
	if(!is_from_args)
		free(name);
	if (is_from_args && str[0] != '/')
		free(name);
}


void	print_link_with_color(char *str, char *color, int is_from_args) {
	size_t	len;
	char	buff[1024];

	len = readlink(str, buff, 1023);
	buff[len] = '\0';
	
	print_color_text_no_newline(str, color, is_from_args);
	ft_printf(" -> %s\n", buff);
}


void	print_color_single(char *path, int is_from_args) {
	struct stat data;
	struct stat ldata;
	char	*temp;

	stat(path, &data);
	lstat(path, &ldata);
	if(S_ISLNK(ldata.st_mode)) {
		print_link_with_color(path, MAGENTA, is_from_args);
	} else if(S_ISDIR(data.st_mode)) {
		if(ldata.st_mode & S_ISVTX)
			print_color_text(path, GREEN_BACKGROUND, is_from_args);
		else if (ldata.st_mode & S_IWOTH)
			print_color_text(path, YELLOW_BACKGROUND, is_from_args);	
		else
			print_color_text(path, BLUE, is_from_args);
	} else if (S_ISREG(data.st_mode) && access(path, X_OK) == 0) {
       	 	if (ldata.st_mode & S_ISUID)
			print_color_text(path, BLACK_RED, is_from_args);

		else
			print_color_text(path, RED, is_from_args);
    	} else if (S_ISCHR(ldata.st_mode)) {
		print_color_text(path, BLUE_YELLOW, is_from_args);
	} else if (S_ISBLK(ldata.st_mode)) {
		 print_color_text(path, BLUE_CYAN, is_from_args);
	} else if (S_ISSOCK(ldata.st_mode)) {
		print_color_text(path, GREEN, is_from_args);
	} else if (S_ISFIFO(ldata.st_mode)) {
		print_color_text(path, YELLOW, is_from_args);
	} 
	else {
		if(is_from_args) {
			temp = cut_file_path_for_printing_file_passed_in_args(path);
			ft_printf("%s\n", temp);	
			free(temp);
		} else {
			temp = get_name_from_path(path);
			ft_printf("%s\n", temp);
			free(temp);
		}
	}
}

void	print_color(char **paths, int is_from_args) {
	int i;

	i = 0;
	while(paths[i]) {
		print_color_single(paths[i], is_from_args);	
		i++;
	}
}
