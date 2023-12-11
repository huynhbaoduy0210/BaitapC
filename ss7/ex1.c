#include <stdio.h>

int main() {
    for (int i = 1; i <= 100; ++i) {
        // Kiểm tra bội số của cả ba và năm
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz ");
        }
            // Kiểm tra bội số của ba
        else if (i % 3 == 0) {
            printf("Fizz ");
        }
            // Kiểm tra bội số của năm
        else if (i % 5 == 0) {
            printf("Buzz ");
        }
            // In số nếu không phải là bội số của cả ba và năm
        else {
            printf("%d ", i);
        }
    }

    return 0;
}