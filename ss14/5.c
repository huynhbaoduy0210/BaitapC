#include <stdio.h>

void nhap_mang(int a[], int n) {
    printf("Nhap vao cac phan tu cua mang:\n");
    for (int i = 0; i < n; ++i) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void in_mang(int a[], int n) {
    printf("Cac phan tu cua mang:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sap_xep_mang(int a[], int n, int giam_dan) {
    int *ptr;
    int temp;

    for (int i = 0; i < n - 1; ++i) {
        ptr = &a[i];
        for (int j = i + 1; j < n; ++j) {
            if ((giam_dan && *ptr < a[j]) || (!giam_dan && *ptr > a[j])) {
                ptr = &a[j];
            }
        }
        if (ptr != &a[i]) {
            temp = *ptr;
            *ptr = a[i];
            a[i] = temp;
        }
    }
}

int main() {
    int mang[100], n, choice;

    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &n);

    nhap_mang(mang, n);
    printf("\nMang truoc khi sap xep:\n");
    in_mang(mang, n);

    printf("\nChon cach sap xep:\n");
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sap_xep_mang(mang, n, 0);  // 0: tang dan
            printf("\nMang sau khi sap xep tang dan:\n");
            in_mang(mang, n);
            break;
        case 2:
            sap_xep_mang(mang, n, 1);  // 1: giam dan
            printf("\nMang sau khi sap xep giam dan:\n");
            in_mang(mang, n);
            break;
        default:
            printf("Lua chon khong hop le.\n");
    }

    return 0;
}
