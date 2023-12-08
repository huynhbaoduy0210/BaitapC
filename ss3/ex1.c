#include<stdio.h>
#define Pi 3.14
int main()
{
    printf("%f",Pi);
    float r;
    printf("ban kinh hinh tron:");
    scanf_s("%f",&r);
    printf("chu vi hinh tron:%.2f\n",2*Pi*r);
    printf("dien tich hinh tron:%.2f",r*r);
}