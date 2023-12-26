#include<stdio.h>
#include<stdlib.h>
intmain(void){
    int y , x;
    printf("Nhap so hang va so cot cua mang 2 chieu: ");
    scanf("%d", &y);
    scanf("%d", &x);
    int *nums2;


    nums2 =malloc(sizeof(int) * x * y);
    for(int i =0; i < y; i++) {
        for(int j =0; j < x; j++) {
            scanf("%d",&nums2[i * x + j]);
        }
    }

    printf("Mang 2 chieu vua nhap\n");

    int x= 2, y= 3
    for(int i =0; i < y; i++) {
        for(int j =0; j < x; j++) {
            if(j < x-1) {
                printf("%d ", nums2[i * x + j]);
            }else {
                printf("%d\n", nums2[i * x + j]);
            }
        }
    }
    //chạy vòng lập bên ngoài(i=0; i<3)
    // chạy vòng lập bên trong vòng lặp j(i=2, i<3)
    //if(j< x-1)Một câu lệnh điều kiện kiểm tra xem có phải là phần tử cuối cùng của hàng hay không
    //printf("%d ", nums2[i * x + j])Nếu không phải là phần tử cuối cùng của hàng, in giá trị của phần tử tại vị trí
    //else Nếu là phần tử cuối cùng
    // in ra giá trị cuối cùng của hàng và xuống dòng 