#include <stdio.h>
int main(){
    int soPhutSuDung;
    double phiHangThang = 25000, tongChiPhi;

    printf("Nhap so phut su dung: ");
    scanf_s("%d", &soPhutSuDung);

    if (soPhutSuDung <= 50) {
        tongChiPhi = phiHangThang + soPhutSuDung * 600;
    } else if (soPhutSuDung <= 200) {
        tongChiPhi = phiHangThang + 50 * 600 + (soPhutSuDung - 50) * 400;
    } else if (soPhutSuDung <= 400) {
        tongChiPhi = phiHangThang + 50 * 600 + 150 * 400 + (soPhutSuDung - 200) * 200;
    } else {
        tongChiPhi = phiHangThang + 50 * 600 + 150 * 400 + 200 * 200 + (soPhutSuDung - 400) * 100;
    }

    printf("Tong chi phi la: %.2lf VND", tongChiPhi);

    return 0;
}