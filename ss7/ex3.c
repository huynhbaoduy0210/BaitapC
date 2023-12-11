#include <stdio.h>
#include <math.h>

int main() {
    double principal, annualRate, monthlyRate, interest, totalAmount;
    int months;

    // Nhập số tiền gửi ban đầu
    printf("Nhap so tien gui ban dau: ");
    scanf("%lf", &principal);

    // Nhập lãi suất hàng năm
    printf("Nhap lai suat nam (dinh dang phan tram): ");
    scanf("%lf", &annualRate);

    // Chuyển lãi suất hàng năm sang lãi suất hàng tháng
    monthlyRate = annualRate / 12 / 100;

    // Nhập số tháng gửi
    printf("Nhap so thang gui: ");
    scanf("%d", &months);

    // Tính số tiền lãi
    interest = principal * pow(1 + monthlyRate, months) - principal;

    // Tính tổng số tiền nhận được sau thời gian gửi
    totalAmount = principal + interest;

    // Hiển thị kết quả
    printf("\nSo tien lai: %.2lf\n", interest);
    printf("So tien nhan duoc sau thoi gian gui: %.2lf\n", totalAmount);

    return 0;
}
