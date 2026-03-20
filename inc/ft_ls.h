#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../libft/libft.h"

# define MAX_FILE_LENGTH 255
# define MAX_PATH_LENGTH 4096

typedef struct 		flags {

	int	l;
	int 	r;
	int 	recur;
	int	t;
	int	a;

}			t_flags;

int	parse_flags(char *str, t_flags *flags);
void	initialize_flags(t_flags *flags);
void	print_flags(t_flags *flags);
int	is_dir(const char *path);
int	is_file(const char *path);
char	**bubble_sort(char **str);
void	print_list(char **str);
