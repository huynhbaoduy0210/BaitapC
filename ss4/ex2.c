#include<stdio.h>
int main(){
    int a,b,c;
    printf("canh 1:");
    scanf_s("%d",&a);
    printf("canh 2:");
    scanf_s("%d",&b);
    printf("canh 3:");
    scanf_s("%d",&c);
    if (a+b>c || a+c>b || b+c>a){
        printf("Day la tam giac ");
        if (a == b && b == c) {
            printf("deu.");
        } else if (a == b || a == c || b == c) {
            if ((a*a) + (b*b) == (c*c) || (a*a) + (c*c) == (b*b) || (b*b) + (c*c) == (a*a)) {
                printf("vuong can.");
            } else {
                printf("can.");
            }
        } else if ((a*a) + (b*b) == (c*c) || (a*a) + (c*c) == (b*b) || (b*b) + (c*c) == (a*a)) {
            printf("vuong.");
        } else {
            printf("thuong.");
        }
    } else {
        printf("3 so vua nhap khong phai la canh cua tam giac.");
    }

    return 0;
}