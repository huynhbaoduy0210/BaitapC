#include <stdio.h>

int main() {
    int row, col;
    printf("Nhap so hang cua mang: ");
    scanf("%d", &row);

    printf("Nhap so cot cua mang: ");
    scanf("%d", &col);
    float arr[row][col];
    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%f", &arr[i][j]);
        }
    }
    float sum = 0;
    printf("Gia tri cac phan tu co gia tri chan:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((int)arr[i][j] % 2 == 0) {
                printf("arr[%d][%d] = %.2f\n", i, j, arr[i][j]);
                sum += arr[i][j];
            }
        }
    }
    printf("Tong cac phan tu co gia tri chan la: %.2f\n", sum);

    return 0;
}
