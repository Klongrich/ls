#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include "libft.h"

# define MAX_FILE_LENGTH 255
# define MAX_PATH_LENGTH 4096

typedef struct 		flags {

	int	l;
	int 	r;
	int 	recur;
	int	t;
	int	a;
	int	color;
	int	u;

}
			t_flags;

typedef struct		lengths {
	int	links;
	int 	name;
	int	group;
	int	size;
	int	count;
}			t_lengths;

typedef struct		dash {

	int dash_found;
	int dashdash_found;
}			t_dash;


int	parse_flags(char *str, t_flags *flags);
void	initialize_flags(t_flags *flags);
void	print_flags(t_flags *flags);
int	is_dir(const char *path, int l_flag);
int	is_file(const char *path, int l_flag);
char	**bubble_sort(char **str, int r, int size);
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
void	print_long_format(char **all_files_or_dirs, t_flags *flags);
void	print_single_file_long_format(char *file_path, t_flags *flags);
char	*append_single_dir(char *dir, char *files_or_dir);
char	*get_name_from_path(char *path);
int	get_repo_or_file_count(char *dir_path, int a_flag, int l_flag);
void	merge_sort(char **arr, int l, int r);
t_lengths	initialize_t_lengths(void);
t_lengths	get_formatting_lengths(char **file_or_dir_paths);
t_lengths	get_single_file_formatting_lengths(char *file_path);
void	print_t_lengths(t_lengths to_print);
t_lengths	set_column_sizes(t_lengths formatting_info, struct stat statbuff);
void	print_permissions(struct stat statbuff, char *file_path);
void	print_name_and_grid(t_lengths formatting_info, struct stat statbuff);
void	print_last_time_modified(struct stat statbuff);
void	print_long_format_files_from_args(char **all_files, t_flags *flags);
void	merge_sort2(char *arr[], int l, int r, int r_flag);
void	merge_time_sort(char *arr[], int l, int r, int r_flag);
void	print_file_name(char *filepath, int is_single_file);
void	decimalToHex(int n, char hextString[]);
char	**append_files_from_args_for_long_format(char *dir, char **files);
void	bubble_swap(char **str_one, char **str_two);
void	compare_str_bubble_normal(char **str, int j);
void	compare_str_bubble_reverse(char **str, int j);
void	ft_putstr_lowercase(char const *s);
int	check_start_of_flag(char *str);
int	check_files_link(char *str);
int	check_files_link_during_recur(char *str);
void	parse_flags_from_args_passed(char **argv, int argc, t_flags flags, int i);
void	initalize_arguments(char **argv, t_flags *flags, int i);
char	**get_files_from_args(char **list_of_args, int l_flag);
char	**get_dirs_from_args(char **list_of_args, int l_flag);
int	check_is_file_or_dir(char **sorted_args, int l_flag);
int	recur(char **files_or_repos, t_flags *flags);
char	**read_dir(char *dir_path, t_flags *flags);
void	cut_file_path_from_files_or_dirs(char **all_files_or_directories);
void	read_dir_with_hidden_files(char **all_files_or_directories, char *dir_path, t_flags *flags);
void    read_dir_standard(char **all_files_or_directories, char *dir_path, t_flags *flags);
void	initialize_arguments(char **argv, t_flags *flags, int i);
void	run_with_no_files_or_repos_passed(t_flags *flags);
void	print_errors_opening_dir(int l_flag, char *dir_path);
void    run_recursion(char **sorted_files, char **sorted_dirs, t_flags *flags, int number_of_invalid_args);
void    run_one_valid_argument(char **sorted_dirs, char **sorted_files, t_flags *flags);
void    run_multiple_arguments(char **sorted_files, char **sorted_dirs, t_flags *flags);
void	print_color(char **paths);
char	**last_time_accessed_sort(char **str, int r);
void	merge_last_time_accessed_sort(char* arr[], int l, int r, int r_flag);
void	print_last_time_accessed(struct stat statbuff);
