#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// std: standard: tieu chuan
// io: input - output
// h: header
//

int sum(int a , int b){
    int sum = a + b;
    return sum;
}

int main(){
    //int nd;
    int newDistance;
    // factorial, prime
    int discount = 20;
    double age = 18.222;
    printf("khuyen mai %d - %.2lf \n",discount, age);
    // Kiểu dữ liệu (int / long / double / float/ char) + tên biến
    int dog, cat = 4, salary;
    // Khai báo và gán giá trị cho biến
    //   int salary;
    salary = 20000;
    // int salary = 20000;
    printf("%d\n",salary); // print format
    char t = 'ABCDDDDDDDX'; // In ra ký tự cuối cùng
    printf("%c\n",t);

    //Cau lenh in hello
    /*
     * xin chao
     * xin chao
     * */
    printf("Hello");
//     int: integer: so nguyen : 7
//     double: 15.2
//     case: truong hop
//     switch: thay doi
//     switch -case: thay doi giua cac truong hop
    // boolean: true/ false
    // return tra ve
    // char: character: ky tu: 'a'
    // string: "Hello"
    // string - char: string duoc tao thanh tu nhieu ky tu
    // while: lặp cho đến khi
    // for: vòng lặp
    // Cac buoc giai bai toan:
    // Xác định input - output:
    // B1: Khai báo biến
    int a = 3, b = 4, temp;

    // In ra giá trị trước khi hoán đổi
    printf("Truoc khi hoan doi: a = %d, b = %d\n", a, b);

    // Sử dụng biến tạm để hoán đổi giá trị
    temp = a;
    a = b;
    b = temp;

    // In ra giá trị sau khi hoán đổi
    printf("Sau khi hoan doi: a = %d, b = %d\n", a, b);
    // boolean
    int c = 4;
    c++; // tang 1 don vi
    // c-- ; giam 1 don vi
    printf("Gia tri cua c la: %d\n", c); // 5
    // Toán tử !: phủ định
    bool d = false;
    bool result = !d;
    printf("Gia tri cua d la: %d\n", result); // True trả về 1, false trả về 0
    return 0;
}