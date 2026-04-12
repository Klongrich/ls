#include "../inc/ft_ls.h"

int     get_number_of_valid_args(char **sorted_args, t_flags *flags){
         int i;
         int valid_file_or_repo_count;
 
         i = 0;
         valid_file_or_repo_count = 0;
         while(sorted_args[i]) {
                 if (is_dir(sorted_args[i], flags) || is_file(sorted_args[i], flags)) {
                         valid_file_or_repo_count++;
                 }
                 i++;
         }
         return (valid_file_or_repo_count);
}
