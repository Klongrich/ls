#include "../inc/ft_ls.h"

int	compare_strs_lowercase(char *str1, char *str2){
	int count;
	char *lower_case_all_characters_one;
	char *lower_case_all_characters_two;
	int diff;
	int spec;

	count = 0;
	spec = 0; 
	lower_case_all_characters_one = (char *)malloc(sizeof(char) * ft_strlen(str1));
	lower_case_all_characters_two = (char *)malloc(sizeof(char) * ft_strlen(str2)); 
	while (str1[count]) {
		spec = 0;
		if (str1[count] == '_') {
			spec = 52;
		}
		lower_case_all_characters_one[count] = ft_tolower(str1[count] - spec);
		count++;
	}
	count = 0;
	while(str2[count]){
		spec = 0;
		if (str2[count] == '_') {
			spec = 52;
		}
		lower_case_all_characters_two[count] = ft_tolower(str2[count] - spec);
		count++;
	}

	diff = ft_strcmp(lower_case_all_characters_one, lower_case_all_characters_two);
	
	free(lower_case_all_characters_one);
	free(lower_case_all_characters_two);
	return (diff);
}
