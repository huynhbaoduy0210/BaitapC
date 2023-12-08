#include <stdio.h>

int main() {
    int day, month, year, soNgay;
    printf("Nhap ngay thang nam: ");
    scanf("%d%d%d", &day, &month, &year);

    if (day <= 0 || month < 0 || month > 12 || year <= 0) {
        printf("Ngay thang nam khong hop le\n");
    } else {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                soNgay = 31;
                break;
            case 4: case 6: case 9: case 11:
                soNgay = 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    soNgay = 29;
                } else {
                    soNgay = 28;
                }
                break;

        }

        if (day >= 1 && day <= soNgay) {
            printf("Ngay thang nam hop le\n");
        } else {
            printf("Ngay thang nam khong hop le\n");
        }
    }

    return 0;
}
