#include <stdio.h>
int main(){
    int ten, twenty, fifty;
    int cnt = 0;
    for (fifty = 0; fifty <= 200000 / 50000; fifty++){
        for (twenty = 0; twenty <= (200000 - 50000 * fifty) / 20000; twenty++){
            ten = (200000 - 50000 * fifty - 20000 * twenty) / 10000;
            if (50000 * fifty + 20000 * twenty + 10000 * ten == 200000){
                printf("So to 50000 VND = %d, So to 20000 VND = %d, So to 10000 VND = %d\n",
                        fifty, twenty, ten);
                cnt++;
            }
        }
    }
    printf("Co tat ca %d cach de co tong so tien la 200000 VND.\n", cnt);
    return 0;
}

