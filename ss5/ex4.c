#include <stdio.h>

int main() {
    double tongThuNhap, tongCacKhoanTru, thueThuNhap, thue, luongRong;

    printf("Nhap tong thu nhap cua nhan vien: ");
    scanf_s("%lf", &tongThuNhap);

    printf("Nhap tong ss tien giam tru: ");
    scanf_s("%lf", &tongCacKhoanTru);

    thueThuNhap = tongThuNhap - tongCacKhoanTru;

    if (thueThuNhap <= 5000000) {
        thue = thueThuNhap * 0.05;
    } else if (thueThuNhap <= 10000000) {
        thue = 250000 + (thueThuNhap - 5000000) * 0.1;
    } else if (thueThuNhap <= 18000000) {
        thue = 750000 + (thueThuNhap - 10000000) * 0.15;
    } else if (thueThuNhap <= 32000000) {
        thue = 1950000 + (thueThuNhap - 18000000) * 0.2;
    } else if (thueThuNhap <= 52000000) {
        thue = 4750000 + (thueThuNhap - 32000000) * 0.25;
    } else if (thueThuNhap <= 80000000) {
        thue = 9750000 + (thueThuNhap - 52000000) * 0.3;
    } else {
        thue = 18150000 + (thueThuNhap - 80000000) * 0.35;
    }

    luongRong = tongThuNhap - thue;

    printf("Thue thu nhap la: %.2lf VND\n", thue);
    printf("Luong rong la: %.2lf VND", luongRong);

    return 0;
}
