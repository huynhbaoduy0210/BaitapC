#include <stdio.h>

// Khai báo cấu trúc SinhVien
struct SinhVien {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};

int main() {
    struct SinhVien sinhVien1;


    printf("Nhap ho va ten: ");
    fgets(sinhVien1.hoTen, sizeof(sinhVien1.hoTen), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &sinhVien1.tuoi);

    fflush(stdin);
    printf("Nhap so dien thoai: ");
    fgets(sinhVien1.soDienThoai, sizeof(sinhVien1.soDienThoai), stdin);

    printf("Nhap email: ");
    fgets(sinhVien1.email, sizeof(sinhVien1.email), stdin);


    printf("\nThong tin cua sinh vien:\n");
    printf("Ho va ten: %s", sinhVien1.hoTen);
    printf("Tuoi: %d\n", sinhVien1.tuoi);
    printf("So dien thoai: %s", sinhVien1.soDienThoai);
    printf("Email: %s", sinhVien1.email);

    return 0;
}
