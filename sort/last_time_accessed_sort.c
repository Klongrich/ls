#include "../inc/ft_ls.h"

char	**last_time_accessed_sort(char **str, int r) {
	
	struct stat file_one;
	struct stat file_two;
	int i;
	int j;
	int size;
	char temp[MAX_FILE_LENGTH];

	size = get_size(str);
	i = 0;
	j = 0;
	while (i < size - 1) {
		j = 0;
		while (j < size - i - 1) {
			lstat(str[j], &file_one);
			lstat(str[j + 1], &file_two);
			if (r) {
				if(file_one.st_atime == file_two.st_atime) {
					if(file_one.st_atimespec.tv_nsec > file_two.st_atimespec.tv_nsec) {
						ft_strcpy(temp, str[j]);
						ft_strcpy(str[j], str[j + 1]);
						ft_strcpy(str[j + 1], temp);
					}
				} else {
					if (file_one.st_atime > file_two.st_atime) {
						ft_strcpy(temp, str[j]);
						ft_strcpy(str[j], str[j + 1]);
						ft_strcpy(str[j + 1], temp);
					}
				}
			} else {
				if (file_one.st_atime == file_two.st_atime) {
					if (file_one.st_atimespec.tv_nsec < file_two.st_atimespec.tv_nsec) {
						ft_strcpy(temp, str[j]);
						ft_strcpy(str[j], str[j + 1]);
						ft_strcpy(str[j + 1], temp);
					}
				} else {
					if (file_one.st_atime < file_two.st_atime) {
						ft_strcpy(temp, str[j]);
						ft_strcpy(str[j], str[j + 1]);
						ft_strcpy(str[j + 1], temp);
					}
				}
			}
			j++;
		}
		i++;
	}
	return (str);
}
