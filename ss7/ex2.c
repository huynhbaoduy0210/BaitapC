#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int originalNum, remainder, result = 0, n = 0;

    originalNum = num;

    // Đếm số chữ số
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    // Tính tổng lập phương của các chữ số
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    // Kiểm tra nếu là số Armstrong
    if (result == num) {
        return 1;  // Là số Armstrong
    } else {
        return 0;  // Không phải là số Armstrong
    }
}

int main() {
    printf("Cac so Armstrong co 3 chu so:\n");

    for (int i = 100; i < 1000; ++i) {
        if (isArmstrong(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}