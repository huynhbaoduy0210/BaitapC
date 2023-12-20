#include <stdio.h>

void nhap_mang(int a[][100], int n, int m) {
    printf("Nhap gia tri cac phan tu cua mang:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("Nhap phan tu tai vi tri (%d, %d): ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void in_ma_tran(int a[][100], int n, int m) {
    printf("Gia tri cac phan tu cua mang theo ma tran:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void in_le_va_tinh_tong(int a[][100], int n, int m) {
    int tong_le = 0;
    printf("Cac phan tu le trong mang:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 != 0) {
                printf("%d\t", a[i][j]);
                tong_le += a[i][j];
            }
        }
    }
    printf("\nTong cac phan tu le: %d\n", tong_le);
}

void in_bien_va_tinh_tich(int a[][100], int n, int m) {
    int tich = 1;
    printf("Cac phan tu tren bien cua mang:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                printf("%d\t", a[i][j]);
                tich *= a[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren bien: %d\n", tich);
}

void in_cheo_va_tinh_tong(int a[][100], int n, int m) {
    int tong_cheo_chinh = 0;
    int tong_cheo_phu = 0;
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; ++i) {
        tong_cheo_chinh += a[i][i];
        printf("%d\t", a[i][i]);
    }
    printf("\nTong cac phan tu tren duong cheo chinh: %d\n", tong_cheo_chinh);

    printf("Cac phan tu tren duong cheo phu:\n");
    for (int i = 0; i < n; ++i) {
        tong_cheo_phu += a[i][m - 1 - i];
        printf("%d\t", a[i][m - 1 - i]);
    }
    printf("\nTong cac phan tu tren duong cheo phu: %d\n", tong_cheo_phu);
}

void tim_max_min(int a[][100], int n, int m) {
    int max_value = a[0][0];
    int min_value = a[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > max_value) {
                max_value = a[i][j];
            }
            if (a[i][j] < min_value) {
                min_value = a[i][j];
            }
        }
    }
    printf("Gia tri lon nhat trong mang: %d\n", max_value);
    printf("Gia tri nho nhat trong mang: %d\n", min_value);
}

void tinh_trung_binh_va_thong_ke(int a[][100], int n, int m) {
    int tong = 0;
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tong += a[i][j];
            ++dem;
        }
    }
    float trung_binh = (float)tong / dem;
    printf("Gia tri trung binh cua cac phan tu trong mang (lam tron xuong): %.0f\n", trung_binh);

    int dem_bang_trung_binh = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == trung_binh) {
                ++dem_bang_trung_binh;
            }
        }
    }
    printf("Co %d phan tu co gia tri bang gia tri trung binh\n", dem_bang_trung_binh);
}

void in_dong_tong_lon_nhat(int a[][100], int n, int m) {
    int max_tong = 0;
    int dong_max_tong = 0;
    for (int i = 0; i < n; ++i) {
        int tong_dong = 0;
        for (int j = 0; j < m; ++j) {
            tong_dong += a[i][j];
        }
        if (tong_dong > max_tong) {
            max_tong = tong_dong;
            dong_max_tong = i;
        }
    }
    printf("Dong co tong gia tri lon nhat:\n");
    for (int j = 0; j < m; ++j) {
        printf("%d\t", a[dong_max_tong][j]);
    }
    printf("\n");
}

int main() {
    int a[100][100];
    int n, m;
    int choice;

    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In ra cac phan tu nam tren bien va tinh tich\n");
        printf("5. In ra cac phan tu tren duong cheo chinh va phu va tinh tong\n");
        printf("6. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("7. Tinh gia tri trung binh va thong ke so luong phan tu bang gia tri trung binh\n");
        printf("8. In ra dong co tong gia tri lon nhat\n");
        printf("9. Thoat\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhap_mang(a, n, m);
                break;
            case 2:
                in_ma_tran(a, n, m);
                break;
            case 3:
                in_le_va_tinh_tong(a, n, m);
                break;
            case 4:
                in_bien_va_tinh_tich(a, n, m);
                break;
            case 5:
                in_cheo_va_tinh_tong(a, n, m);
                break;
            case 6:
                tim_max_min(a, n, m);
                break;
            case 7:
                tinh_trung_binh_va_thong_ke(a, n, m);
                break;
            case 8:
                in_dong_tong_lon_nhat(a, n, m);
                break;
            case 9:
                printf("Ket thuc chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }

    } while (choice != 9);

    return 0;
}