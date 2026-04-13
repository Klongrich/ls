#include "../inc/ft_ls.h"

void	compare_time_reverse_a(struct stat file_one, struct stat file_two, int j, char **str) {
	if(file_one.st_atime == file_two.st_atime) {
		if(file_one.st_atimespec.tv_nsec > file_two.st_atimespec.tv_nsec)
			bubble_swap(&str[j], &str[j + 1]);
	} else {
		if (file_one.st_atime > file_two.st_atime)
			bubble_swap(&str[j], &str[j + 1]);
	}
}

void	compare_time_normal_a(struct stat file_one, struct stat file_two, int j, char **str) {
	if (file_one.st_atime == file_two.st_atime) {
		if (file_one.st_atimespec.tv_nsec < file_two.st_atimespec.tv_nsec) {
			bubble_swap(&str[j], &str[j + 1]);
		}
	} else {
		if (file_one.st_atime < file_two.st_atime) {
			bubble_swap(&str[j], &str[j + 1]);
		}
	}
}

char	**last_time_accessed_sort(char **str, int r) {
	struct stat file_one;
	struct stat file_two;
	int i;
	int j;
	int size;

	size = get_size(str);
	i = 0;
	j = 0;
	while (i < size - 1) {
		j = 0;
		while (j < size - i - 1) {
			lstat(str[j], &file_one);
			lstat(str[j + 1], &file_two);
			if (r) {
				compare_time_reverse_a(file_one, file_two, j, str);
			} else {
				compare_time_normal_a(file_one, file_two, j, str);
			}
			j++;
		}
		i++;
	}
	return (str);
}
