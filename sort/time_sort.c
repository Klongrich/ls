#include "../inc/ft_ls.h"

void	compare_time_reverse(struct stat file_one, struct stat file_two, int j, char **str) {
	if(file_one.st_mtime == file_two.st_mtime) {
		if(file_one.st_mtimespec.tv_nsec > file_two.st_mtimespec.tv_nsec)
			bubble_swap(&str[j], &str[j + 1]);
	} else {
		if (file_one.st_mtime > file_two.st_mtime)
			bubble_swap(&str[j], &str[j + 1]);
	}
}

void	compare_time_normal(struct stat file_one, struct stat file_two, int j, char **str) {
	if (file_one.st_mtime == file_two.st_mtime) {
		if (file_one.st_mtimespec.tv_nsec < file_two.st_mtimespec.tv_nsec) {
			bubble_swap(&str[j], &str[j + 1]);
		}
	} else {
		if (file_one.st_mtime < file_two.st_mtime) {
			bubble_swap(&str[j], &str[j + 1]);
		}
	}
}

char	**time_sort(char **str, int r) {
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
				compare_time_reverse(file_one, file_two, j, str);
			} else {
				compare_time_normal(file_one, file_two, j, str);
			}
			j++;
		}
		i++;
	}
	return (str);
}
