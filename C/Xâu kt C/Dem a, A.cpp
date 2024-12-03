//Dem so lan a va A xuat hien
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];  
    int cnt = 0;  
    printf("Nhap xau: ");
    gets(str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'A') {
            cnt++;
        }
    }
    printf("So lan xuat hien 'a' hoac 'A' la: %d\n", cnt);
    return 0;
}

