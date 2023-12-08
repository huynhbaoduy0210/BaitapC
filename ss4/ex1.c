#include<stdio.h>
int main(){
    int i;
    printf("nhap so nguyen");
    scanf_s("%d",&i);
    if (i%3==0 && i%5==0){
        printf("chia het");
        scanf("%d",&i);
    }else {
        printf("khong chia het");
        scanf("%d",&i);
    }
    return 0;