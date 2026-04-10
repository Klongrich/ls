#include "../inc/ft_ls.h"

void	print_date_year(char *times) {
	char *year;
	char *date;
	int i;
               
	i = 0;  
	ft_putchar(' ');
	date = times + 4;
	year = times + 20;
	while(i < 7) {
		ft_putchar(date[i]);    
		i++;
	}
	ft_putchar(' ');
	i = 0;
	while (i < 4) {
		ft_putchar(year[i]);
		i++;
	}
	i = 0;
	while (i < 1) {
		ft_putchar(' ');
		i++;
	}
}
