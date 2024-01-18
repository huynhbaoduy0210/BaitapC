#include <stdio.h>

int main(){
    // Hinh vuong : Day la hinh vuong
    int square = 20;
    printf("Chu vi hinh vuong %d - Dien tich hinh vuong %d \n", square*4, square*square);
    // Hinh chu nhat;
    int length = 20, witdh = 10;
    printf("Chu vi hinh CN %d - Dien tich hinh CN %d \n", (length+witdh)*2, length*witdh);
    const double PI = 3.14;
    int R = 20;
    printf("Chu vi hinh tron %.2lf - Dien tich hinh tron %.2lf \n", 2*PI*R , PI*R*R );
    return 0;
}