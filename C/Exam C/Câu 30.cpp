#include <stdio.h>
int main() {
    int du, temp;
    for (int i = 1000; i <= 9999; i++) {
        temp = i;
        int sum = 0;
        while (temp) {
            du = temp % 10; 
            sum += du;      
            temp /= 10; 
        }
        if (sum == 12) {
            printf("%d ", i);
        }
    }
    return 0;
}

