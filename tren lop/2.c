#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void*a, const void*b) {
    return (*(int *) a - *(int *) b);

}
int main () {
    int a[4][5] = {1, 2, 3, 4, 6,
                   1, 3, 5, 7, 8,
                   4, 6, 10, 12, 21,
                   34, 21, 17, 1, 4,
    };
    int x, y;
    printf("nhap gia tri x vao mang 2 chieu: ");
    scanf("%d ", &x);
    printf("nhap gia tri y vao mang 2 chieu: ");
    scanf("%d ", &y);

    int arr[y][x];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("nhap so phan tu cot: %d hang: %d ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Mang 2 chieu chua  sap xep: \n");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    qsort(arr, x * y, sizeof(int), cmpfunc);
    printf("mang 2 chieu sau khi duoc sap xep:\n ");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}








