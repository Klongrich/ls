#include "../inc/ft_ls.h"

void decimalToHex(int n, char hexString[]) {
	char *hexChars;
	char temp[20];
	int i;
	int j;

	j = 0;
	i = 0;
	hexChars = "0123456789ABCDEF";
	if (n == 0) {
        	hexString[0] = '0';
        	hexString[1] = '\0';
        	return;
    	}
	while (n > 0) {
        	temp[i++] = hexChars[n % 16];
		n /= 16;
	}
	while (i > 0) {
        	hexString[j++] = temp[--i];
    	}
    	hexString[j] = '\0';
}
