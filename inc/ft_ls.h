#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include "../libft/libft.h"

# define MAX_FILE_LENGTH 255
# define MAX_PATH_LENGTH 4096

typedef struct 		flags {

	int	l;
	int 	r;
	int 	recur;
	int	t;
	int	a;

}
			t_flags;

typedef struct		lengths {
	int	links;
	int 	name;
	int	group;
	int	size;
	int	count;
}			t_lengths;

int	parse_flags(char *str, t_flags *flags);
void	initialize_flags(t_flags *flags);
void	print_flags(t_flags *flags);
int	is_dir(const char *path);
int	is_file(const char *path);
char	**bubble_sort(char **str, int r);
void	print_list(char **str);
void	print_list_n(char **str, int n);
int	get_size(char **str);
int	is_flag(char *str);
void	free_list(char **list);
int	compare_strs_lowercase(char *str1, char *str2);
char	**append_dir(char *dir, char **file_or_dirs);
int	check_end(char *dir_path);
void	initialize_flags(t_flags *flags);
char 	**time_sort(char **str, int r);
void	print_mtime(char *file_path);
void	print_nsec(char *file_path);
void	print_long_format(char **all_files_or_dirs);
char	*append_single_dir(char *dir, char *files_or_dir);
char	*get_name_from_path(char *path);
int	get_repo_or_file_count(char *dir_path, int a_flag);
char	**merge_sort(int size, char **str);
t_lengths	initialize_t_lengths(void);
t_lengths	get_formatting_lengths(char **file_or_dir_paths);
void	print_t_lengths(t_lengths to_print);
t_lengths	set_column_sizes(t_lengths formatting_info, struct stat statbuff);
