NAME = ft_ls
OBJ = main.o parse_flags.o is_dir.o is_file.o bubble_sort.o print_list.o print_list_n.o get_size.o is_flag.o free_list.o compare_strs_lowercase.o check_end.o append_dir.o initialize_flags.o time_sort.o print_mtime.o print_nsec.o print_long_format.o append_single_dir.o get_name_from_path.o get_repo_or_file_count.o merge_sort.o initialize_t_lengths.o get_formatting_lengths.o print_t_lengths.o set_column_size.o print_permissions.o print_name_and_grid.o print_last_time_modified.o print_single_file_long_format.o get_single_file_formatting_lengths.o print_long_format_list_of_files.o merge_sort_2.o merge_time_sort.o print_file_name.o decimal_to_hex.o
INC = inc/ft_ls.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBH = libft/libft.h

all: $(NAME)

%.o: $(addprefix ./src/,%.c)
	@gcc $(CFLAGS) $(INC) -c $< $(LIBH)

%.o: $(addprefix ./debug/,%.c)
	@gcc $(CFLAGS) $(INC) -c $< $(LIBH)

$(NAME): $(OBJ)
	@gcc -g $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
