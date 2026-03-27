#include "../inc/ft_ls.h"

t_lengths	initialize_t_lengths(void) {
	t_lengths initialized_t_length;

	initialized_t_length.links = 0;
	initialized_t_length.name = 0;
	initialized_t_length.group = 0;
	initialized_t_length.size = 0;
	initialized_t_length.count = 0;
	return(initialized_t_length);

}
