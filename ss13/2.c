#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void printString(char str[]) {
    printf("Nội dung chuỗi: %s\n", str);
}

int countCharacter(char str[], char ch) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

void replaceCharacters(char str[], char oldChar, char newChar) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

void removeCharacter(char str[], char ch) {
    int len = strlen(str);
    int currentIndex = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != ch) {
            str[currentIndex] = str[i];
            currentIndex++;
        }
    }

    str[currentIndex] = '\0';
}

int main() {
    char inputString[MAX_LENGTH];
    char option;
    char ch1, ch2;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhập vào chuỗi ký tự\n");
        printf("2. In ra nội dung chuỗi\n");
        printf("3. Nhập vào 1 ký tự, đếm số lần xuất hiện ký tự trong chuỗi\n");
        printf("4. Nhập vào 2 ký tự, thay thế các ký tự thứ 2 trong chuỗi thành ký tự thứ nhất\n");
        printf("5. Nhập vào 1 ký tự, xóa bỏ các ký tự trong chuỗi\n");
        printf("6. Thoát\n");

        printf("Lựa chọn của bạn: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("Nhập chuỗi ký tự: ");
                scanf("%s", inputString);
                break;

            case '2':
                printString(inputString);
                break;

            case '3':
                printf("Nhập ký tự cần đếm: ");
                scanf(" %c", &ch1);
                printf("Số lần xuất hiện của ký tự '%c' là: %d\n", ch1, countCharacter(inputString, ch1));
                break;

            case '4':
                printf("Nhập vào 2 ký tự: ");
                scanf(" %c %c", &ch1, &ch2);
                replaceCharacters(inputString, ch2, ch1);
                break;

            case '5':
                printf("Nhập ký tự cần xóa: ");
                scanf(" %c", &ch1);
                removeCharacter(inputString, ch1);
                break;

            case '6':
                return 0;

            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
                break;
        }
    }

    return 0;
}
