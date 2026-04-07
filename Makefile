NAME = ft_ls
STRING_OBJ = ft_putstr.o ft_strlen.o ft_putchar.o ft_numlen.o ft_putnbr.o ft_putstr_lowercase.o
READ_DIR_OBJ = cut_file_path_from_files_or_dirs.o read_with_hidden_files.o read_dir_standard.o print_errors_opening_dir.o
INIT_ARGS_OBJ = initialize_arguments.o run_with_no_files_or_repos_passed.o run_recursion.o run_one_valid_argument.o run_multiple_arguments.o
OBJ = $(STRING_OBJ) $(READ_DIR_OBJ) $(INIT_ARGS_OBJ) main.o parse_flags.o is_dir.o is_file.o bubble_sort.o print_list.o print_list_n.o get_size.o is_flag.o free_list.o compare_strs_lowercase.o check_end.o append_dir.o initialize_flags.o time_sort.o print_mtime.o print_nsec.o print_long_format.o append_single_dir.o get_name_from_path.o get_repo_or_file_count.o merge_sort.o initialize_t_lengths.o get_formatting_lengths.o print_t_lengths.o set_column_size.o print_permissions.o print_name_and_grid.o print_last_time_modified.o print_single_file_long_format.o get_single_file_formatting_lengths.o print_long_format_list_of_files.o merge_sort_2.o merge_time_sort.o print_file_name.o decimal_to_hex.o append_files_from_args_for_long_format.o bubble_swap.o compare_str_bubble_normal.o compare_str_bubble_reverse.o ft_strcpy.o ft_strjoin.o ft_putstr_fd.o ft_tolower.o ft_strcmp.o ft_printf.o check_start_of_flag.o check_files_link.o check_files_link_during_recur.o parse_flags_from_args_passed.o get_dirs_from_args.o get_files_from_args.o check_is_file_or_dir.o recur.o read_dir.o
INC = inc/ft_ls.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: $(addprefix ./src/,%.c)
	@gcc $(CFLAGS) $(INC) -c $< 

%.o: $(addprefix ./debug/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./sort/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./print/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./print_formatting/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./strings/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./read_dir/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./parse_flags/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./memory_management/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./parse_from_arguments_passed/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./recursion/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./initialize_arguments/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<

%.o: $(addprefix ./run/,%.c)
	@gcc $(CFLAGS) $(INC) -c $<


$(NAME): $(OBJ)
	@gcc -g $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: 
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
