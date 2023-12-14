#include <stdio.h>
int menu(){
    printf("1.nhap gia tri cac phan tu cua mang\n");
    printf("2.In gia tri cac phan thu cua mang theo ma tran\n");
    printf("3.In gia tri cac phan tu la le va tinh tong\n");
    printf("nhap so 0 de ket thuc chuong trinh\n");
}
void nhapso1(int x,int y, int a[y][x]){
    for( int i=0; i<y; i++){
        for( int j=0; j<x; j++){
            printf("nhap vao phan tu a[%d][%d] cua mang: \n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
}
void nhapso2( int x,int y, int a[y][x]){

    for( int i=0; i<y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}
void nhapso3(int x,int y,int a[y][x]){
    int sum=0;
    for( int i=0; i<y; i++) {
        for (int j = 0; j < x; j++) {
            if(a[i][j]%3==0){
                printf("cac phan tu le la :%d \n",a[i][j]);
                sum+=a[i][j];
            }
        }
    }
    printf("tong cac so le la: %d\n",sum);
}
int main() {
    int x, y;

    printf("nhap chieu dai mang: ");
    scanf("%d", &y);
    printf("nhap chieu ngang mang: ");
    scanf("%d", &x);
    int a[y][x];
    int nhapso;
    do {
        menu();
        printf("nhap so 1 den 3: ");
        scanf("%d", &nhapso);

        switch (nhapso) {
            case 1:
                nhapso1(x,y,a);
                break;
            case 2:
                nhapso2(x,y,a);
                break;
            case 3:
                nhapso3(x,y,a);
                break;
            default:
                if (nhapso > 3 || nhapso < 0) {
                    printf("so da nhap ko hop le moi nhap lai: \n");
                }
        }

    } while (nhapso != 0);
    return 0;
}
