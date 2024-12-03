#include <stdio.h>

int main() {
    int dung, nam, gia;
    for (dung = 0; dung <= 100; dung++) {
        for (nam = 0; nam <= 100; nam++) {
            gia = 100 - dung - nam;
            if (gia >= 0 && dung * 5 + nam * 3 + gia / 3 == 100 && gia % 3 == 0) {
                printf("Trau dung: %d, Trau nam: %d, Trau gia: %d\n", dung, nam, gia);
            }
        }
    }
    return 0;
}

