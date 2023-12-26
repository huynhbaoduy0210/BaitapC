#include <stdio.h>
#include <string.h>

// Định nghĩa kích thước tối đa của mảng sinh viên
#define MAX_SINH_VIEN 100

// Khai báo cấu trúc SinhVien
struct SinhVien {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};

// Khai báo cấu trúc DanhSachSinhVien
struct DanhSachSinhVien {
    struct SinhVien sinhVien[MAX_SINH_VIEN];
    int soLuong;
};

// Hàm nhập thông tin sinh viên
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

// Hàm in thông tin sinh viên
void inThongTinSinhVien(const struct SinhVien *sv) {
    printf("\nThong tin cua sinh vien:\n");
    printf("Ho va ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s", sv->soDienThoai);
    printf("Email: %s", sv->email);
}

// Hàm thêm sinh viên vào danh sách
void themSinhVien(struct DanhSachSinhVien *ds, const struct SinhVien *sv, int viTri) {
    // Kiểm tra xem danh sách đã đầy chưa
    if (ds->soLuong >= MAX_SINH_VIEN) {
        printf("Danh sach da day, khong the them sinh vien moi.\n");
        return;
    }

    // Dời các sinh viên sau vị trí cần thêm để tạo chỗ cho sinh viên mới
    for (int i = ds->soLuong; i > viTri; --i) {
        ds->sinhVien[i] = ds->sinhVien[i - 1];
    }

    // Thêm sinh viên mới vào vị trí
    ds->sinhVien[viTri] = *sv;
    ds->soLuong++;
}

// Hàm sửa thông tin sinh viên tại vị trí
void suaThongTinSinhVien(struct DanhSachSinhVien *ds, int viTri) {
    // Kiểm tra vị trí hợp lệ
    if (viTri < 0 || viTri >= ds->soLuong) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    // Nhập thông tin mới cho sinh viên tại vị trí
    nhapThongTinSinhVien(&ds->sinhVien[viTri]);
}

// Hàm xóa sinh viên tại vị trí
void xoaSinhVien(struct DanhSachSinhVien *ds, int viTri) {
    // Kiểm tra vị trí hợp lệ
    if (viTri < 0 || viTri >= ds->soLuong) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    // Dời các sinh viên sau vị trí cần xóa để loại bỏ sinh viên đó
    for (int i = viTri; i < ds->soLuong - 1; ++i) {
        ds->sinhVien[i] = ds->sinhVien[i + 1];
    }

    // Giảm số lượng sinh viên trong danh sách
    ds->soLuong--;
}

// Hàm in thông tin tất cả sinh viên trong danh sách
void inDanhSachSinhVien(const struct DanhSachSinhVien *ds) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < ds->soLuong; ++i) {
        inThongTinSinhVien(&ds->sinhVien[i]);
    }
}

int main() {
    // Khởi tạo một biến danh sách sinh viên
    struct DanhSachSinhVien danhSachSV;
    danhSachSV.soLuong = 0; // Khởi tạo số lượng sinh viên bằng 0

    // Menu chương trình
    int luaChon;
    do {
        printf("\nMenu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua thong tin sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. In danh sach sinh vien\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                // Thêm sinh viên
                if (danhSachSV.soLuong < MAX_SINH_VIEN) {
                    struct SinhVien sv;
                    nhapThongTinSinhVien(&sv);
                    int viTri;
                    printf("Nhap vi tri can them (tu 0 den %d): ", danhSachSV.soLuong);
                    scanf("%d", &viTri);
                    themSinhVien(&danhSachSV, &sv, viTri);
                } else {
                    printf("Danh sach da day, khong the them sinh vien moi.\n");
                }
                break;
            case 2:
                // Sửa thông tin sinh viên
                if (danhSachSV.soLuong > 0) {
                    int viTriSua;
                    printf("Nhap vi tri can sua (tu 0 den %d): ", danhSachSV.soLuong - 1);
                    scanf("%d", &viTriSua);
                    suaThongTinSinhVien(&danhSachSV, viTriSua);
                } else {
                    printf("Danh sach rong, khong co sinh vien de sua.\n");
                }
                break;
            case 3:
                // Xóa sinh viên
                if (danhSachSV.soLuong > 0) {
                    int viTriXoa;
                    printf("Nhap vi tri can xoa (tu 0 den %d): ", danhSachSV.soLuong - 1);
                    scanf("%d", &viTriXoa);
                    xoaSinhVien(&danhSachSV, viTriXoa);
                } else {
                    printf("Danh sach rong, khong co sinh vien de xoa.\n");
                }
                break;
            case 4:
                // In danh sách sinh viên
                inDanhSachSinhVien(&danhSachSV);
                break;
            case 0:
                // Thoát chương trình
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}
