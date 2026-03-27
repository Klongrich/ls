#include "../inc/ft_ls.h"

void	print_t_lengths(t_lengths to_print) {
	printf("links: %d\n", to_print.links);
	printf("name: %d\n", to_print.name);
	printf("group: %d\n", to_print.group);
	printf("size: %d\n", to_print.size);
	printf("count: %d\n", to_print.count);
}
