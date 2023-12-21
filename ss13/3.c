#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Nhập vào chuỗi ký tự: ");
    scanf(" %[^\n]s", str);

    int count[256] = {0};

    for (int i = 0; i < strlen(str); i++) {
        count[(int)str[i]]++;
    }


    printf("Số lần xuất hiện của mỗi ký tự trong chuỗi:\n");
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("Ký tự '%c': %d lần\n", (char)i, count[i]);
        }
    }

    return 0;
}
