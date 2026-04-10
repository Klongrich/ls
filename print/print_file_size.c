#include "../inc/ft_ls.h"

void	print_file_size(struct stat statbuff, t_lengths formatting_lengths) {
	int num;
	char *hex_temp;
	char hex[20];

	if (S_ISCHR(statbuff.st_mode) || S_ISBLK(statbuff.st_mode)) {
		num = makedev(major(statbuff.st_rdev), minor(statbuff.st_rdev));
		if(num != 0) {
			decimalToHex(num, hex);
			hex_temp = ft_strjoin("0x", hex);
			ft_printf("%#s", formatting_lengths.size, hex_temp);
			free(hex_temp);
		} else {
			hex_temp = "0";
			ft_printf("%#s", formatting_lengths.size, hex_temp);
		}
	} else
		ft_printf("%*d", formatting_lengths.size, (int)statbuff.st_size);

}
