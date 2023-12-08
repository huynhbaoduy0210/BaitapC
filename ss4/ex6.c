#include <stdio.h>
int main () {
    int n1, n2, n3, n4, min,max,temp1,temp2,temp;
    printf("nhap 4 so tu ban phim");
    scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
    temp1=n1;
    temp2=n1;
    min = (n1 < n2  && n1 < n3 && n1 < n4) ? n1 : (n2 < n3 && n2 < n4) ? n2 : (n3 < n4) ? n3 : n4;
    max = (n1 > n2  && n1 > n3 && n1 > n4) ? n1 : (n2 > n3 && n2 > n4) ? n2 : (n3 > n4) ? n3 : n4;
    printf("gia tri max la: %d\n", max);
    printf("gia tri min la: %d\n", min);
    if (temp1==max||temp1==min ){
        temp1=n2;
    } else if( temp1==max || temp1==min){
        temp1=n3;
    } else if( temp1==max || temp1==min) {
        temp1 = n4;
    }
    if ( temp2==max || temp2==min || temp2==temp1){
        temp2=n2;
    }  if(temp2==max || temp2==min || temp2==temp1){
        temp2=n3;
    }  if(temp2==max || temp2==min || temp2==temp1) {
        temp2 = n4;
    } else
    if(temp1>temp2){
        temp=temp1;
        temp1=temp2;
        temp2=temp;
    } else{}
    printf("so dao nguoc la: %d%d%d%d",max,temp2,temp1,min);
    return 0;
}