#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap gia tri cho cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    int findNumber;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &findNumber);

    int sum = 0;
    printf("Chung ta tim kiem gia tri %d trong mang:\n", findNumber);
    for (int i = 0; i < n; i++) {
        if (arr[i] == findNumber) {
            printf("arr[%d] = %d\n", i, findNumber);
            sum += findNumber;
        }
    }

    printf("Tong cac phan tu co gia tri bang %d la: %d\n", findNumber, sum);

    return 0;
}
