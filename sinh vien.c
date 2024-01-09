#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100

// Định nghĩa cấu trúc SinhVien
typedef struct {
    char maSV[6];
    char hoTen[31];
    char lop[11];
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
} SinhVien;

// Định nghĩa hàm chuẩn hóa tên sinh viên
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

// Định nghĩa hàm nhập thông tin sinh viên
void nhapThongTin(SinhVien *sv) {
    printf("Nhap ma sinh vien (5 ky tu): ");
    scanf("%5s", sv->maSV);

    printf("Nhap ho va ten sinh vien (tu 5 den 30 ky tu): ");
    scanf(" %[^\n]", sv->hoTen);
    chuanHoaTen(sv->hoTen);

    printf("Nhap lop (toi da 10 ky tu): ");
    scanf("%10s", sv->lop);

    do {
        printf("Nhap diem Toan (tu 0 den 10): ");
        scanf("%f", &sv->diemToan);
    } while (sv->diemToan < 0 || sv->diemToan > 10);

    do {
        printf("Nhap diem Ly (tu 0 den 10): ");
        scanf("%f", &sv->diemLy);
    } while (sv->diemLy < 0 || sv->diemLy > 10);

    do {
        printf("Nhap diem Hoa (tu 0 den 10): ");
        scanf("%f", &sv->diemHoa);
    } while (sv->diemHoa < 0 || sv->diemHoa > 10);

    sv->diemTB = (sv->diemToan + sv->diemLy + sv->diemHoa) / 3.0;
}

// Định nghĩa hàm hiển thị thông tin sinh viên
void hienThiThongTin(const SinhVien *sv) {
    printf("Ma SV: %-5s | Ho va ten: %-30s | Lop: %-10s | Diem TB: %.2f\n",
           sv->maSV, sv->hoTen, sv->lop, sv->diemTB);
}

// Định nghĩa hàm ghi thông tin sinh viên vào tệp tin
void ghiDuLieuVaoFile(const SinhVien *sv) {
    FILE *file = fopen("student.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s %s %.2f %.2f %.2f\n",
                sv->maSV, sv->hoTen, sv->lop, sv->diemToan, sv->diemLy, sv->diemHoa);
        fclose(file);
    } else {
        printf("Loi khi mo tep tin.\n");
    }
}

// Định nghĩa hàm sửa thông tin sinh viên
void suaThongTinSinhVien(SinhVien *danhSach, int soLuong) {
    char maSua[6];
    printf("Nhap ma sinh vien can sua: ");
    scanf("%5s", maSua);

    int timThay = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(danhSach[i].maSV, maSua) == 0) {
            nhapThongTin(&danhSach[i]);  // Cập nhật thông tin mới
            timThay = 1;
            printf("Sua thong tin sinh vien thanh cong.\n");
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien co ma %s.\n", maSua);
    }
}

// Định nghĩa hàm xóa sinh viên
void xoaSinhVien(SinhVien *danhSach, int *soLuong) {
    char maXoa[6];
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%5s", maXoa);

    int timThay = 0;
    for (int i = 0; i < *soLuong; i++) {
        if (strcmp(danhSach[i].maSV, maXoa) == 0) {
            // Di chuyển các sinh viên phía sau lên để xóa sinh viên tại vị trí i
            for (int j = i; j < *soLuong - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            (*soLuong)--;
            timThay = 1;
            printf("Xoa sinh vien thanh cong.\n");
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien co ma %s.\n", maXoa);
    }
}

// Hàm chính main
int main() {
    int choice;
    int soLuong = 0;  // Biến lưu số lượng sinh viên
    SinhVien danhSach[MAX_STUDENTS];

    do {
        printf("\nMENU:\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi thong tin sinh vien\n");
        printf("3. Sap xep sinh vien theo diem trung binh tang dan\n");
        printf("4. Sap xep sinh vien theo diem trung binh giam dan\n");
        printf("5. Tim kiem sinh vien theo lop\n");
        printf("6. Tim kiem sinh vien theo diem trong khoang\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTin(&danhSach[soLuong]);
                soLuong++;
                break;
            case 2:
                printf("Danh sach sinh vien:\n");
                printf(" %-5s | %-30s | %-10s | %-8s\n", "Ma SV", "Ho va ten", "Lop", "Diem TB");
                for (int i = 0; i < soLuong; i++) {
                    hienThiThongTin(&danhSach[i]);
                }
                break;
            case 3:
                // Thêm code để sắp xếp sinh viên theo điểm trung bình tăng dần
                break;
            case 4:
                // Thêm code để sắp xếp sinh viên theo điểm trung bình giảm dần
                break;
            case 5:
                // Thêm code để tìm kiếm sinh viên theo lớp
                break;
            case 6:
                // Thêm code để tìm kiếm sinh viên theo điểm trong khoảng
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
