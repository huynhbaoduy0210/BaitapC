#include <stdio.h>

int main() {
    double doangThu, hoaHong;

    printf("Nhap doanh thu ban hang cua dai ly: ");
    scanf_s("%lf", &doangThu);

    if (doangThu <= 100000000) {
        hoaHong = doangThu * 0.05;
    } else if (doangThu <= 300000000) {
        hoaHong = doangThu * 0.1;
    } else {
        hoaHong = doangThu * 0.2;
    }

    printf("Hoa hong dai ly la: %.2lf", hoaHong);

    return 0;
}