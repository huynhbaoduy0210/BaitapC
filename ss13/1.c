#include <stdio.h>
#include <string.h>
#include <ctype.h>


void printMenu() {
    printf("MENU\n");
    printf("1. Nhập vào chuỗi ký tự\n");
    printf("2. In ra độ dài chuỗi và nội dung chuỗi vừa nhập\n");
    printf("3. In ra chuỗi đảo ngược\n");
    printf("4. In ra số lượng chữ cái trong chuỗi\n");
    printf("5. In ra số lượng chữ số trong chuỗi\n");
    printf("6. Thoát\n");
}

int main() {
    char str[100];

    int choice;
    do {
        printMenu();
        printf("Chọn chức năng (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Nhập vào chuỗi ký tự: ");
                scanf(" %[^\n]s", str);
                break;
            case 2:
                printf("Độ dài chuỗi: %lu\n", strlen(str));
                printf("Nội dung chuỗi: %s\n", str);
                break;
            case 3:
                printf("Chuỗi đảo ngược: ");
                for (int i = strlen(str) - 1; i >= 0; i--) {
                    printf("%c", str[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("Số lượng chữ cái trong chuỗi: ");
                int countAlpha = 0;
                for (int i = 0; i < strlen(str); i++) {
                    if (isalpha(str[i])) {
                        countAlpha++;
                    }
                }
                printf("%d\n", countAlpha);
                break;
            case 5:
                printf("Số lượng chữ số trong chuỗi: ");
                int countDigit = 0;
                for (int i = 0; i < strlen(str); i++) {
                    if (isdigit(str[i])) {
                        countDigit++;
                    }
                }
                printf("%d\n", countDigit);
                break;
            case 6:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Chọn không hợp lệ. Vui lòng chọn lại.\n");
        }

    } while (choice != 6);

    return 0;
}
