#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d",&m);scanf("%d",&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("nhap so phan tu hang %d cot %d: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]%2==0) {
                printf("so chan: %d\n ", a[i][j]);
                sum += a[i][j];
                printf("\n");
            }
        }


    }
    printf("tong so chan: %d ",sum);
    return 0;
}
