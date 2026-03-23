NAME = ft_ls
OBJ = main.o parse_flags.o is_dir.o is_file.o bubble_sort.o print_list.o print_list_n.o get_size.o is_flag.o free_list.o compare_strs_lowercase.o check_end.o append_dir.o initialize_flags.o time_sort.o print_mtime.o print_nsec.o print_long_format.o append_single_dir.o get_name_from_path.o
INC = inc/ft_ls.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBH = libft/libft.h

all: $(NAME)

%.o: $(addprefix ./src/,%.c)
	@gcc $(CFLAGS) $(INC) -c $< $(LIBH)

$(NAME): $(OBJ)
	@gcc -g $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
