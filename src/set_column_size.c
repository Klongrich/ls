#include "../inc/ft_ls.h"

t_lengths	set_column_sizes(t_lengths formatting_info, struct stat statbuf) {
	struct passwd	*pwd;
	struct group	*grp;

	if ((pwd = getpwuid(statbuf.st_uid)))
		(ft_strlen(pwd->pw_name) > formatting_info.name) 
		? formatting_info.name = ft_strlen(pwd->pw_name) : 0;
	else
		(ft_numlen(statbuf.st_uid) > formatting_info.name)
		? formatting_info.name = ft_numlen(statbuf.st_uid) : 0;

	if ((grp = getgrgid(statbuf.st_gid)) != NULL)
		(ft_strlen(grp->gr_name) > formatting_info.group)
		? formatting_info.group = ft_strlen(grp->gr_name) : 0;
	else
		(ft_numlen(statbuf.st_gid) > formatting_info.group)
		? formatting_info.group = ft_numlen(statbuf.st_gid) : 0;
	return (formatting_info);
}
