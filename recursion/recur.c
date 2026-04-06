#include "../inc/ft_ls.h"

int     recur(char **files_or_repos, t_flags *flags) {
	int i;
        char **append;
        char **files_from_repo;
 
        i = 0;
        while (files_or_repos[i]) {
               if(is_dir(files_or_repos[i], flags->l)) {
                        if (!check_files_link_during_recur(files_or_repos[i])) {
                        	ft_printf("\n");
                                ft_printf("%s:\n", files_or_repos[i]);
                                files_from_repo = read_dir(files_or_repos[i],flags);
                                if(files_from_repo) {
                                        append = append_dir(files_or_repos[i], files_from_repo);            
                                        recur(append, flags);
 
                                        free_list(append);
                                        free_list(files_from_repo);
                                 }
                         }
                 }
                 i++;
         }
         return (0);
}
