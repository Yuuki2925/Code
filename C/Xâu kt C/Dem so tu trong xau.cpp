// Dem so tu trong xau ki tu
#include <stdio.h>
#include <string.h>

int countWords(const char str[]) {
    int inWord = 0; 
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    gets(str);
    int words = countWords(str);
    printf("So tu trong chuoi la: %d\n", words);
    return 0;
}
