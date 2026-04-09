#include "../inc/ft_ls.h"

int     check_is_file_or_dir(char **sorted_args, t_flags *flags){
         int i;
         int invalid_file_or_repo_count;
 
         i = 0;
         invalid_file_or_repo_count = 0;
         while(sorted_args[i]) {
                 if (!is_dir(sorted_args[i], flags) && !is_file(sorted_args[i], flags)) {
                         ft_putstr_fd("ls: ", 2);
                         ft_putstr_fd(sorted_args[i], 2);
                         ft_putstr_fd(" No such file or directory\n", 2);
                         invalid_file_or_repo_count++;
                 }
                 i++;
         }
         return (invalid_file_or_repo_count);
}
