#include "../inc/ft_ls.h"

void decimalToHex(int n, char hexString[]) {
    char hexChars[] = "0123456789ABCDEF";
    char temp[20];
    int i = 0;

    if (n == 0) {
        hexString[0] = '0';
        hexString[1] = '\0';
        return;
    }

    while (n > 0) {
        temp[i++] = hexChars[n % 16];
        n /= 16;
    }

    int j = 0;
    while (i > 0) {
        hexString[j++] = temp[--i];
    }
    hexString[j] = '\0';
}
