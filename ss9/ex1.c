#include <stdio.h>
void menu(){
    printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
}
int a[5];
void Nhapso1(){
    for(int i=0; i<5; i++){
        printf("moi nhap phan tu thu a[%d]:  ",i);
        scanf("%d",&a[i]);
    }
}
void Nhapso2(){
    printf("Cac so da nhap la: \n");
    for (int i=0; i<5; i++){
        printf("%d   \n",a[i]);

    }
}
void Nhapso3(){
    int sum=0;
    for( int i=0; i<5; i++){
        if(a[i]%2==0){
            printf("Cac so chan la: %d\n",a[i]);
            sum+=a[i];
        }
    }printf("Tong la: %d\n",sum);
}
int main(){
    int Nhapso;
    do {
        menu();
        printf("nhap so ban muon chon:");
        scanf("%d",&Nhapso);
        switch (Nhapso) {
            case 1 :
                Nhapso1();
                break;
            case 2:
                Nhapso2();
                break;
            case 3:
                Nhapso3();
                break;
            default:
                if (Nhapso>3 && Nhapso<0){
                    printf("lua chon khong hop le moi chon lai \n");
                }
        }
    } while (Nhapso!=0);
    return 0;
}