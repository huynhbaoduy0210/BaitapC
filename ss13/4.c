#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char inputString[MAX_LENGTH];
    char distinctString[MAX_LENGTH];
    int maxLength = 0;

    printf("Nhập vào chuỗi ký tự: ");
    fgets(inputString, sizeof(inputString), stdin);


    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }


    char *token = strtok(inputString, " ");
    while (token != NULL) {
        int currentLength = strlen(token);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            strcpy(distinctString, token);
        }
        token = strtok(NULL, " ");
    }

    printf("Chuỗi ký tự phân biệt đầu tiên có độ dài lớn nhất: %s\n", distinctString);

    return 0;
}
