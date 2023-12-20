#include <stdio.h>
#include <stdlib.h>


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


void sao_chep_mang(int a[], int b[], int n) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }
    printf("Da sao chep mang.\n");
}


void doi_cho_mang(int a[], int b[], int n) {
    for (int i = 0; i < n; ++i) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    printf("Da doi cho hai mang.\n");
}


void dao_nguoc_mang(int a[], int n) {
    int temp;
    for (int i = 0; i < n / 2; ++i) {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    printf("Da dao nguoc mang.\n");
}


void tim_kiem_ky_tu(int a[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == key) {
            printf("Tim thay ky tu %d tai vi tri %d.\n", key, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay ky tu %d trong mang.\n", key);
    }
}

int main() {
    int mang[100], mang_khac[100], n, choice;
    char ky_tu;

    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &n);

    do {

        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. In ra mang\n");
        printf("3. Sao chep mang vao mang khac\n");
        printf("4. Nhap vao mang khac, doi cho 2 mang voi nhau\n");
        printf("5. Dao nguoc mang\n");
        printf("6. Nhap vao mot ky tu, tim kiem ky tu trong mang\n");
        printf("7. Thoat\n");


        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhap_mang(mang, n);
                break;
            case 2:
                in_mang(mang, n);
                break;
            case 3:
                sao_chep_mang(mang, mang_khac, n);
                break;
            case 4:
                nhap_mang(mang_khac, n);
                doi_cho_mang(mang, mang_khac, n);
                break;
            case 5:
                dao_nguoc_mang(mang, n);
                break;
            case 6:
                printf("Nhap vao mot ky tu: ");
                scanf(" %c", &ky_tu);
                tim_kiem_ky_tu(mang, n, ky_tu);
                break;
            case 7:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }

    } while (choice != 7);

    return 0;
}
