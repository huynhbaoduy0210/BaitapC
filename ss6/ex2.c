#include <stdio.h>

// Hàm tính ước chung lớn nhất
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tính bội chung nhỏ nhất
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1, num2, choice;

    // Nhập hai số nguyên từ bàn phím
    printf("Nhap so nguyen 1: ");
    scanf("%d", &num1);

    printf("Nhap so nguyen 2: ");
    scanf("%d", &num2);

    do {
        // Hiển thị menu
        printf("\nCALCULATOR\n");
        printf("1. Tong 2 so\n");
        printf("2. Hieu 2 so\n");
        printf("3. Tich 2 so\n");
        printf("4. Thuong 2 so\n");
        printf("5. So du trong phep chia 2 so\n");
        printf("6. Uoc chung lon nhat\n");
        printf("7. Boi chung nho nhat\n");
        printf("8. Thoat\n");

        // Nhập lựa chọn từ người dùng
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        // Thực hiện chức năng tương ứng với lựa chọn
        switch (choice) {
            case 1:
                printf("Tong 2 so la: %d\n", num1 + num2);
                break;
            case 2:
                printf("Hieu 2 so la: %d\n", num1 - num2);
                break;
            case 3:
                printf("Tich 2 so la: %d\n", num1 * num2);
                break;
            case 4:
                if (num2 != 0) {
                    printf("Thuong 2 so la: %.2f\n", (float)num1 / num2);
                } else {
                    printf("Khong the chia cho 0.\n");
                }
                break;
            case 5:
                if (num2 != 0) {
                    printf("So du trong phep chia 2 so la: %d\n", num1 % num2);
                } else {
                    printf("Khong the chia cho 0.\n");
                }
                break;
            case 6:
                printf("Uoc chung lon nhat la: %d\n", gcd(num1, num2));
                break;
            case 7:
                printf("Boi chung nho nhat la: %d\n", lcm(num1, num2));
                break;
            case 8:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 8);  // Lặp lại cho đến khi người dùng chọn thoát

    return 0;
}


