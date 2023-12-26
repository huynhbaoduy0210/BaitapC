#include <stdio.h>


struct SinhVien {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};


void nhapThongTinSinhVien(struct SinhVien *sv) {
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &sv->tuoi);

    fflush(stdin);
    printf("Nhap so dien thoai: ");
    fgets(sv->soDienThoai, sizeof(sv->soDienThoai), stdin);

    printf("Nhap email: ");
    fgets(sv->email, sizeof(sv->email), stdin);
}

void xuatThongTinSinhVien(const struct SinhVien *sv) {
    printf("\nThong tin cua sinh vien:\n");
    printf("Ho va ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s", sv->soDienThoai);
    printf("Email: %s", sv->email);
}

int main() {

    struct SinhVien sinhVien1;


    nhapThongTinSinhVien(&sinhVien1);


    xuatThongTinSinhVien(&sinhVien1);

    return 0;
}
