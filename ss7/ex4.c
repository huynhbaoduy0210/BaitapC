#include <stdio.h>

// Hàm kiểm tra số nguyên tố
int isPrime(int num) {
    if (num < 2) {
        return 0; // Không phải số nguyên tố
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; // Không phải số nguyên tố
        }
    }
    return 1; // Là số nguyên tố
}

// Hàm kiểm tra số hoàn hảo
int isPerfect(int num) {
    int sum = 1; // 1 luôn là ước số của mọi số
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum == num; // Trả về 1 nếu là số hoàn hảo, ngược lại trả về 0
}

// Hàm tính giai thừa
long long factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

// Hàm in số đảo ngược
void reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    printf("So dao nguoc cua n la: %d\n", reversed);
}

int main() {
    int n, choice;

    // Nhập số nguyên từ bàn phím
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    do {
        // Hiển thị menu
        printf("\nINTEGER NUMBER\n");
        printf("1. In ra day so co gia tri nho hon hoac bang n va tinh tong\n");
        printf("2. In ra va dem cac so chia het cho 3 nho hon n\n");
        printf("3. Kiem tra so nguyen co phai la so nguyen to khong\n");
        printf("4. Kiem tra so nguyen co phai la so hoan hao khong\n");
        printf("5. Tinh tong cac uoc so cua n\n");
        printf("6. Tinh giai thua cua n\n");
        printf("7. In ra so dao nguoc cua n\n");
        printf("8. In ra cac so nguyen to tu 1 den n\n");
        printf("9. Thoat\n");

        // Nhập lựa chọn từ người dùng
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        // Thực hiện chức năng tương ứng với lựa chọn
        switch (choice) {
            case 1:
                printf("Day so co gia tri nho hon hoac bang %d va tong la: ", n);
                int sum = 0;
                for (int i = 1; i <= n; ++i) {
                    printf("%d ", i);
                    sum += i;
                }
                printf("\nTong: %d\n", sum);
                break;
            case 2:
                printf("Cac so chia het cho 3 va nho hon %d la: ", n);
                int count = 0;
                for (int i = 1; i < n; ++i) {
                    if (i % 3 == 0) {
                        printf("%d ", i);
                        count++;
                    }
                }
                printf("\nSo luong: %d\n", count);
                break;
            case 3:
                if (isPrime(n)) {
                    printf("%d la so nguyen to.\n", n);
                } else {
                    printf("%d khong phai la so nguyen to.\n", n);
                }
                break;
            case 4:
                if (isPerfect(n)) {
                    printf("%d la so hoan hao.\n", n);
                } else {
                    printf("%d khong phai la so hoan hao.\n", n);
                }
                break;
            case 5:
                printf("Tong cac uoc so cua %d la: ", n);
                int uocSum = 0;
                for (int i = 1; i <= n; ++i) {
                    if (n % i == 0) {
                        printf("%d ", i);
                        uocSum += i;
                    }
                }
                printf("\nTong: %d\n", uocSum);
                break;
            case 6:
                printf("Giai thua cua %d la: %lld\n", n, factorial(n));
                break;
            case 7:
                reverseNumber(n);
                break;
            case 8:
                printf("Cac so nguyen to tu 1 den %d la: ", n);
                for (int i = 2; i <= n; ++i) {
                    if (isPrime(i)) {
                        printf("%d ", i);
                    }
                }
                printf("\n");
                break;
            case 9:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 9);  // Lặp lại cho đến khi người dùng chọn thoát

    return 0;
}
