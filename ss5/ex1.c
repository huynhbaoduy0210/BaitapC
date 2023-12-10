#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c , x1, x2;
    float delta = pow(b,2) - 4 * a * c;
    printf("nhap he so a:");
    scanf("%f",&a);
    printf("nhap he so b:");
    scanf("%f",&b);
    printf("nhap he so c:");
    scanf("%f",&c);
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2= (-b - sqrt(delta)) / (2 * a);
        printf("Phuong trinh co hai nghiem:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("Phuong trinh co nghiem kep:\n");
        printf("x = %.2f\n", x1);
    } else {
        printf("phuong trinh vo nghiem.\n");
    }
    return 0;
}
