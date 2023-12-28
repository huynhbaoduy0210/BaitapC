include<iostream>
using namespace std;

int main() {
    int month;
    cout << "Nhập vào một tháng (1-12): ";
    cin >> month;

    if(month == 1) {
        cout << "Tháng 1 có 31 ngày";
    } else if(month == 2) {
        cout << "Tháng 2 có 28 hoặc 29 ngày";
    } else if(month == 3) {
        cout << "Tháng 3 có 31 ngày";
    } else if(month == 4) {
        cout << "Tháng 4 có 30 ngày";
    } else if(month == 5) {
        cout << "Tháng 5 có 31 ngày";
    } else if(month == 6) {
        cout << "Tháng 6 có 30 ngày";
    } else if(month == 7) {
        cout << "Tháng 7 có 31 ngày";
    } else if(month == 8) {
        cout << "Tháng 8 có 31 ngày";
    } else if(month == 9) {
        cout << "Tháng 9 có 30 ngày";
    } else if(month == 10) {
        cout << "Tháng 10 có 31 ngày";
    } else if(month == 11) {
        cout << "Tháng 11 có 30 ngày";
    } else if(month == 12) {
        cout << "Tháng 12 có 31 ngày";
    } else {
        cout << "Không phải là một tháng hợp lệ. Vui lòng nhập một số từ 1 đến 12.";
    }

    return 0;
}