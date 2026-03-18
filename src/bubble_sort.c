#include "../inc/ft_ls.h"

int number_of_files_or_repos(char **str){

	int i;

	i = 0;
	while(str[i]) {
		i++;
	}
	return(i);
}


//Chaning our characters arrays to all lowercase before using ft_strcmp
int	compare_strs(char *str1, char *str2){
	int count;
	char *lower_case_all_characters_one;
	char *lower_case_all_characters_two;
	int diff;

	count = 0;
	lower_case_all_characters_one = (char *)malloc(sizeof(char) * ft_strlen(str1));
	lower_case_all_characters_two = (char *)malloc(sizeof(char) * ft_strlen(str2)); 
	while (str1[count]) {
		lower_case_all_characters_one[count] = ft_tolower(str1[count]);
		count++;
	}
	count = 0;
	while(str2[count]){
		lower_case_all_characters_two[count] = ft_tolower(str2[count]);
		count++;
	}

	diff = ft_strcmp(lower_case_all_characters_one, lower_case_all_characters_two);
	
	free(lower_case_all_characters_one);
	free(lower_case_all_characters_two);
	return (diff);
}


char	**bubble_sort(char **str) {

	int i;
	int j;
	int size;
	char temp[MAX_FILE_LENGTH];

	size = number_of_files_or_repos(str);
	i = -1;
	j = i;
	while (i++ < size - 1) {
		j = i;
		while (j++ < size - 1) {
			if (compare_strs(str[i], str[j]) > 0) {
				ft_strcpy(temp, str[i]);
				ft_strcpy(str[i], str[j]);
				ft_strcpy(str[j], temp);
			}
		}

	}
	return (str);
}
