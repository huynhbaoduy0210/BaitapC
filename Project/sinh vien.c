#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100

typedef struct {
    char maSV[6];
    char hoTen[31];
    char lop[11];
    float diemToan;
    float diemLy;
    float diemHoa;
} SinhVien;

void chuanHoaTen(char ten[]) {
    int length = strlen(ten);
    if (length > 0) {
        ten[0] = toupper(ten[0]);
        for (int i = 1; i < length; i++) {
            if (ten[i - 1] == ' ') {
                ten[i] = toupper(ten[i]);
            } else {
                ten[i] = tolower(ten[i]);
            }
        }
    }
}

void hienThiSinhVien(SinhVien sv) {
    printf("Ma SV: %s, Ho Ten: %s, Lop: %s, Diem TB: %.2f\n",
           sv.maSV, sv.hoTen, sv.lop, (sv.diemToan + sv.diemLy + sv.diemHoa) / 3);
}

void hienThiDanhSach(SinhVien danhSach[], int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        hienThiSinhVien(danhSach[i]);
    }
}

void ghiDanhSach(SinhVien danhSach[], int soLuong) {
    FILE *file = fopen("student.txt", "w");
    if (file == NULL) {
        printf("Loi mo file.\n");
        exit(1);
    }

    for (int i = 0; i < soLuong; i++) {
        fprintf(file, "%s %s %s %.2f %.2f %.2f\n",
                danhSach[i].maSV,
                danhSach[i].hoTen,
                danhSach[i].lop,
                danhSach[i].diemToan,
                danhSach[i].diemLy,
                danhSach[i].diemHoa);
    }

    fclose(file);
}

void docDanhSach(SinhVien danhSach[], int *soLuong) {
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        *soLuong = 0;
        return;
    }

    *soLuong = 0;
    while (fscanf(file, "%s %s %s %f %f %f",
                  danhSach[*soLuong].maSV,
                  danhSach[*soLuong].hoTen,
                  danhSach[*soLuong].lop,
                  &danhSach[*soLuong].diemToan,
                  &danhSach[*soLuong].diemLy,
                  &danhSach[*soLuong].diemHoa) == 6) {
        (*soLuong)++;
    }

    fclose(file);
}

void themSinhVien(SinhVien danhSach[], int *soLuong) {
    if (*soLuong < MAX_STUDENTS) {
        SinhVien sv;

        printf("Nhap ma sinh vien (5 ky tu): ");
        scanf("%5s", sv.maSV);

        printf("Nhap ho ten sinh vien (5-30 ky tu): ");
        scanf("%30s", sv.hoTen);
        chuanHoaTen(sv.hoTen);

        printf("Nhap lop (max 10 ky tu): ");
        scanf("%10s", sv.lop);

        do {
            printf("Nhap diem toan(0-10): ");
            scanf("%f", &sv.diemToan);
        } while (sv.diemToan < 0 || sv.diemToan > 10);

        do {
            printf("Nhap diem ly(0-10u): ");
            scanf("%f", &sv.diemLy);
        } while (sv.diemLy < 0 || sv.diemLy > 10);

        do {
            printf("Nhap diem hoa(0-10): ");
            scanf("%f", &sv.diemHoa);
        } while (sv.diemHoa < 0 || sv.diemHoa > 10);

        danhSach[*soLuong] = sv;
        (*soLuong)++;

        ghiDanhSach(danhSach, *soLuong);
    } else {
        printf("Danh sach sinh vien da day, khong the them moi.\n");
    }
}

void suaThongTinSinhVien(SinhVien danhSach[], int soLuong) {
    char maSV[6];
    printf("Nhap ma sinh vien can sua thong tin: ");
    scanf("%5s", maSV);

    int timThay = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(danhSach[i].maSV, maSV) == 0) {
            SinhVien sv;

            printf("Nhap ho ten moi (5-30 ky tu): ");
            scanf("%30s", sv.hoTen);
            chuanHoaTen(sv.hoTen);

            printf("Nhap lop moi (max 10 ky tu): ");
            scanf("%10s", sv.lop);

            do {
                printf("Nhap diem toan moi (0-10): ");
                scanf("%f", &sv.diemToan);
            } while (sv.diemToan < 0 || sv.diemToan > 10);

            do {
                printf("Nhap diem ly moi (0-10): ");
                scanf("%f", &sv.diemLy);
            } while (sv.diemLy < 0 || sv.diemLy > 10);

            do {
                printf("Nhap diem hoa moi (0-10): ");
                scanf("%f", &sv.diemHoa);
            } while (sv.diemHoa < 0 || sv.diemHoa > 10);

            danhSach[i] = sv;
            timThay = 1;

            ghiDanhSach(danhSach, soLuong);
            printf("Da cap nhat thong tin sinh vien.\n");
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien co ma %s.\n", maSV);
    }
}

void xoaSinhVien(SinhVien danhSach[], int *soLuong) {
    char maSV[6];
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%5s", maSV);

    int timThay = 0;
    for (int i = 0; i < *soLuong; i++) {
        if (strcmp(danhSach[i].maSV, maSV) == 0) {
            for (int j = i; j < *soLuong - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            (*soLuong)--;

            ghiDanhSach(danhSach, *soLuong);
            printf("Da xoa sinh vien co ma %s.\n", maSV);
            timThay = 1;
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien co ma %s.\n", maSV);
    }
}

void sapXepTheoDiem(SinhVien danhSach[], int soLuong, int giamDan) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            float diemI = danhSach[i].diemToan + danhSach[i].diemLy + danhSach[i].diemHoa;
            float diemJ = danhSach[j].diemToan + danhSach[j].diemLy + danhSach[j].diemHoa;

            if ((giamDan && diemI < diemJ) || (!giamDan && diemI > diemJ)) {
                SinhVien temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

void timKiemTheoLop(SinhVien danhSach[], int soLuong) {
    char lop[11];
    printf("Nhap lop can tim kiem: ");
    scanf("%10s", lop);

    int timThay = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(danhSach[i].lop, lop) == 0) {
            hienThiSinhVien(danhSach[i]);
            timThay = 1;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien trong lop %s.\n", lop);
    }
}

void timKiemTheoDiem(SinhVien danhSach[], int soLuong) {
    float diemMin, diemMax;
    printf("Nhap diem toi thieu: ");
    scanf("%f", &diemMin);
    printf("Nhap diem toi da: ");
    scanf("%f", &diemMax);

    int timThay = 0;
    for (int i = 0; i < soLuong; i++) {
        float diemTB = (danhSach[i].diemToan + danhSach[i].diemLy + danhSach[i].diemHoa) / 3;
        if (diemTB >= diemMin && diemTB <= diemMax) {
            hienThiSinhVien(danhSach[i]);
            timThay = 1;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien trong khoang diem %.2f den %.2f.\n", diemMin, diemMax);
    }
}

int main() {
    SinhVien danhSach[MAX_STUDENTS];
    int soLuong = 0;

    docDanhSach(danhSach, &soLuong);

    int luaChon;
    do {
        printf("\nMENU:\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Sap xep sinh vien theo diem trung binh tang dan\n");
        printf("6. Sap xep sinh vien theo diem trung binh giam dan\n");
        printf("7. Tim kiem sinh vien theo lop\n");
        printf("8. Tim kiem sinh vien theo diem\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themSinhVien(danhSach, &soLuong);
                break;
            case 2:
                hienThiDanhSach(danhSach, soLuong);
                break;
            case 3:
                suaThongTinSinhVien(danhSach, soLuong);
                break;
            case 4:
                xoaSinhVien(danhSach, &soLuong);
                break;
            case 5:
                sapXepTheoDiem(danhSach, soLuong, 0);
                printf("Da sap xep tang dan theo diem trung binh.\n");
                break;
            case 6:
                sapXepTheoDiem(danhSach, soLuong, 1);
                printf("Da sap xep giam dan theo diem trung binh.\n");
                break;
            case 7:
                timKiemTheoLop(danhSach, soLuong);
                break;
            case 8:
                timKiemTheoDiem(danhSach, soLuong);
                break;
            case 0:
                ghiDanhSach(danhSach, soLuong);
                printf("Cam on ban da su dung chuong trinh. Hen gap lai.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}
