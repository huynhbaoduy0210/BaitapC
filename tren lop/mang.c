#include<stdio.h>
#include<string.h>
int main(void){
    printf("Nhap chuoi ky tu: ");
    char str[100];
    scanf("%s", str);
    int len = strlen(str); //Hàm strlen dùng để tính độ dài chuỗi.
    printf("Do dai chuoi: %d",len);
    return 0;
}

