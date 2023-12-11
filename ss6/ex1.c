#include <stdio.h>

int main() {
    int n;


    printf("Nhap so n (1 <= n <= 9): ");
    scanf("%d", &n);

    if (n < 1 || n > 9) {
        printf("So nhap vao khong hop le. Vui long nhap lai.\n");
        return 1;
    }

    printf("Bang cuu chuong %d:\n", n);
    for (int i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
