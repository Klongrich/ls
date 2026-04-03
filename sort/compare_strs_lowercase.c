#include "../inc/ft_ls.h"

int	compare_strs_lowercase(char *str1, char *str2){
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
