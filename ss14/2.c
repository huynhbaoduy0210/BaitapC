#include <stdio.h>

int main() {
    int a, b;
    int *ptr_a, *ptr_b;


    printf("Nhap gia tri cho bien a: ");
    scanf("%d", &a);
    printf("Nhap gia tri cho bien b: ");
    scanf("%d", &b);


    printf("\nGia tri ban dau:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    ptr_a = &a;
    ptr_b = &b;


    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;


    printf("\nGia tri sau khi doi cho:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);


    int hieu_truoc_doi_cho = a - b;
    printf("\nHieu truoc khi doi cho: %d\n", hieu_truoc_doi_cho);

    int hieu_sau_doi_cho = *ptr_a - *ptr_b;
    printf("Hieu sau khi doi cho: %d\n", hieu_sau_doi_cho);

    return 0;
}
