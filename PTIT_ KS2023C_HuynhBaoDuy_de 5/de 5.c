#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX_SIZE 100

    void nhapMang(int a[MAX_SIZE][MAX_SIZE], int *n, int *m);
    void inMenu();
    void inMang(int a[MAX_SIZE][MAX_SIZE], int n, int m);
    int demLeChiaHetCho5(int a[MAX_SIZE][MAX_SIZE], int n, int m);
    void timMinMaxBienChinhPhu(int a[MAX_SIZE][MAX_SIZE], int n, int m);
    void sapXepGiamDanTheoDong(int a[MAX_SIZE][MAX_SIZE], int n, int m);
    int laSoNguyenTo(int num);
    int tongSoNguyenTo(int a[MAX_SIZE][MAX_SIZE], int n, int m);
    void sapXepChenDuongCheoPhu(int a[MAX_SIZE][MAX_SIZE], int n, int m);
    void chenMang1ChieuVao2Chieu(int a[MAX_SIZE][MAX_SIZE], int n, int m);

    int main() {
        int a[MAX_SIZE][MAX_SIZE];
        int n, m;
        int choice;

        do {
            inMenu();
            printf("Nhap lua chon cua ban: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    nhapMang(a, &n, &m);
                    break;
                case 2:
                    inMang(a, n, m);
                    break;
                case 3:
                    printf("So luong phan tu le chia het cho 5: %d\n", demLeChiaHetCho5(a, n, m));
                    break;
                case 4:
                    timMinMaxBienChinhPhu(a, n, m);
                    break;
                case 5:
                    sapXepGiamDanTheoDong(a, n, m);
                    printf("Mang sau khi sap xep giam dan theo dong:\n");
                    inMang(a, n, m);
                    break;
                case 6:
                    printf("Tong cac phan tu la so nguyen to: %d\n", tongSoNguyenTo(a, n, m));
                    break;
                case 7:
                    sapXepChenDuongCheoPhu(a, n, m);
                    printf("Mang sau khi sap xep tang dan tren duong cheo phu:\n");
                    inMang(a, n, m);
                    break;
                case 8:
                    chenMang1ChieuVao2Chieu(a, n, m);
                    printf("Mang sau khi chen:\n");
                    inMang(a, n, m);
                    break;
                case 9:
                    printf("Ket thuc chuong trinh.\n");
                    break;
                default:
                    printf("Lua chon khong hop le. Vui long nhap lai.\n");
            }

        } while (choice != 9);

        return 0;
    }

    void nhapMang(int a[MAX_SIZE][MAX_SIZE], int *n, int *m) {
        printf("Nhap so hang n: ");
        scanf("%d", n);
        printf("Nhap so cot m: ");
        scanf("%d", m);

        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                printf("Nhap a[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }
    }



            void inMenu() {
                printf("************************MENU**************************\n");
                printf("1. Nhap gia tri cac phan tu cua mang\n");
                printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
                printf("3. Tinh so luong cac phan tu le chia het cho 5 trong mang\n");
                printf("4. In ra cac phan tu co gia tri lon nhat, nho nhat nam tren duong bien, duong cheo chinh, duong cheo phu\n");
                printf("5. Sap xep cac phan tu giam dan theo dong cua mang\n");
                printf("6. Tinh tong cac phan tu la so nguyen to trong mang\n");
                printf("7. Sap xep cac phan tu tren duong cheo phu tang dan\n");
                printf("8. Chen mang 1 chieu vao mang 2 chieu\n");
                printf("9. Thoat\n");
            }

            void inMang(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d\t", a[i][j]);
                    }
                    printf("\n");
                }
            }

            int demLeChiaHetCho5(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] % 2 != 0 && a[i][j] % 5 == 0) {
                            count++;
                        }
                    }
                }
                return count;
            }

            void timMinMaxBienChinhPhu(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
                int maxBien = INT_MIN, minBien = INT_MAX;
                int maxCheoChinh = INT_MIN, minCheoChinh = INT_MAX;
                int maxCheoPhu = INT_MIN, minCheoPhu = INT_MAX;

                for (int i = 0; i < n; i++) {
                    if (a[i][0] > maxBien) maxBien = a[i][0];
                    if (a[i][m - 1] > maxBien) maxBien = a[i][m - 1];
                    if (a[i][0] < minBien) minBien = a[i][0];
                    if (a[i][m - 1] < minBien) minBien = a[i][m - 1];

                    if (i < m && a[i][i] > maxCheoChinh) maxCheoChinh = a[i][i];
                    if (i < m && a[i][i] < minCheoChinh) minCheoChinh = a[i][i];

                    if (i < m && a[i][m - i - 1] > maxCheoPhu) maxCheoPhu = a[i][m - i - 1];
                    if (i < m && a[i][m - i - 1] < minCheoPhu) minCheoPhu = a[i][m - i - 1];
                }

                printf("Phan tu lon nhat tren bien: %d\n", maxBien);
                printf("Phan tu nho nhat tren bien: %d\n", minBien);
                printf("Phan tu lon nhat tren duong cheo chinh: %d\n", maxCheoChinh);
                printf("Phan tu nho nhat tren duong cheo chinh: %d\n", minCheoChinh);
                printf("Phan tu lon nhat tren duong cheo phu: %d\n", maxCheoPhu);
                printf("Phan tu nho nhat tren duong cheo phu: %d\n", minCheoPhu);
            }

            void sapXepGiamDanTheoDong(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m - 1; j++) {
                        for (int k = j + 1; k < m; k++) {
                            if (a[i][j] < a[i][k]) {
                                int temp = a[i][j];
                                a[i][j] = a[i][k];
                                a[i][k] = temp;
                            }
                        }
                    }
                }
            }

            int laSoNguyenTo(int num) {
                if (num < 2) return 0;
                for (int i = 2; i <= sqrt(num); i++) {
                    if (num % i == 0) return 0;
                }
                return 1;
            }

            int tongSoNguyenTo(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (laSoNguyenTo(a[i][j])) {
                            sum += a[i][j];
                        }
                    }
                }
                return sum;
            }

            void sapXepChenDuongCheoPhu(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (a[j][m - j - 1] > a[j + 1][m - j - 2]) {
                            int temp = a[j][m - j - 1];
                            a[j][m - j - 1] = a[j + 1][m - j - 2];
                            a[j + 1][m - j - 2] = temp;
                        }
                    }
                }
            }

            void chenMang1ChieuVao2Chieu(int a[MAX_SIZE][MAX_SIZE], int n, int m) {
                int arr[MAX_SIZE];
                int col;

                printf("Nhap so phan tu cua mang 1 chieu: ");
                scanf("%d", &col);

                printf("Nhap gia tri cho mang 1 chieu:\n");
                for (int i = 0; i < col; i++) {
                    printf("Nhap a[%d]: ", i);
                    scanf("%d", &arr[i]);
                }

                printf("Nhap cot muon chen vao mang 2 chieu: ");
                scanf("%d", &col);

                for (int i = 0; i < n && i < col; i++) {
                    a[i][col] = arr[i];
                }
            }
