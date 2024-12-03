#include <stdio.h>

int main() {
    // Duyệt qua các số từ 1 đến 100
    for (int i = 1; i < 100; i++) {
        int sum = 0;  // Khởi tạo tổng các ước của i
        // Tìm các ước của i
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;  // Cộng ước vào tổng
            }
        }
        // Kiểm tra nếu tổng bằng với số i thì đó là số hoàn hảo
        if (sum == i) {
            printf("%d là số hoàn hảo\n", i);
        }
    }
    return 0;
}
