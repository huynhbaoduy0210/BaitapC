#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct CD {
    int id;
    char name[50];
    float duration;
    char content[100];
    bool status;
} CD;

CD inputCD() {
    CD cd;
    printf("Nhap id: ");
    scanf("%d", &cd.id);
    printf("Nhap ten: ");
    scanf("%s", cd.name);
    printf("Nhap thoi luong: ");
    scanf("%f", &cd.duration);
    printf("Nhap noi dung: ");
    scanf("%s", cd.content);
    printf("Nhap trang thai: ");
    scanf("%d", &cd.status);
    return cd;
}

void printCD(CD cd) {
    printf("Id: %d\n", cd.id);
    printf("Ten: %s\n", cd.name);
    printf("Thoi luong: %.2f\n", cd.duration);
    printf("Noi dung: %s\n", cd.content);
    printf("Trang thai: %d\n", cd.status);
}

void printCDList(CD* cdList, int size) {
    for (int i = 0; i < size; i++) {
        printf("CD thu %d:\n", i + 1);
        printCD(cdList[i]);
        printf("\n");
    }
}

CD* addCD(CD* cdList, int* size) {
    CD* newList = (CD*)malloc((*size + 1) * sizeof(CD));
    for (int i = 0; i < *size; i++) {
        newList[i] = cdList[i];
    }
    printf("Nhap thong tin cua CD moi:\n");
    CD newCD = inputCD();
    newList[*size] = newCD;
    (*size)++;
    free(cdList);
    return newList;
}

void updateCD(CD* cdList, int size) {
    char name[50];
    printf("Nhap ten cua CD muon cap nhat: ");
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(cdList[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Nhap thong tin moi cho CD %s:\n", name);
        CD newCD = inputCD();
        cdList[index] = newCD;
    }
    else {
        printf("Khong tim thay CD co ten %s\n", name);
    }
}
CD* deleteCD(CD* cdList, int* size) {
    char name[50];
    printf("Nhap ten cua CD muon xoa: ");
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(cdList[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        CD* newList = (CD*)malloc((*size - 1) * sizeof(CD));
        int j = 0;
        for (int i = 0; i < *size; i++) {
            if (i != index) {
                newList[j] = cdList[i];
                j++;
            }
        }
        (*size)--;
        free(cdList);
        return newList;
    }
    else {
        printf("Khong tim thay CD co ten %s\n", name);
        return cdList;
    }
}
void sortCDList(CD* cdList, int size) {
    for (int i = 1; i < size; i++) {
        CD key = cdList[i];
        int j = i - 1;
        while (j >= 0 && cdList[j].duration > key.duration) {
            cdList[j + 1] = cdList[j];
            j--;
        }
        cdList[j + 1] = key;
    }
}
void searchCDByName(CD* cdList, int size) {
    char name[50];
    printf("Nhap ten cua CD muon tim kiem: ");
    scanf("%s", name);
    sortCDList(cdList, size);
    int left = 0;
    int right = size - 1;
    int index = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(cdList[mid].name, name) == 0) {
            index = mid;
            break;
        }
        else if (strcmp(cdList[mid].name, name) < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (index != -1) {
        printf("Tim thay CD co ten %s:\n", name);
        printCD(cdList[index]);
    }

    else {
        printf("Khong tim thay CD co ten %s\n", name);
    }
}


void searchCDByStatus(CD* cdList, int size) {

    bool status;
    printf("Nhap trang thai muon tim kiem: ");
    scanf("%d", &status);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (cdList[i].status == status) {
            printf("CD co trang thai %d:\n", status);
            printCD(cdList[i]);
            printf("\n");
            count++;
        }
    }
    if (count == 0) {
        printf("Khong tim thay CD nao co trang thai %d\n", status);
    }
}
void menu(CD* cdList, int size) {
    printf("************************MENU**************************\n");
    printf("1. In toan bo danh sach cd co o trong mang cdList tren cung mot hang\n");
    printf("2. Thuc hien chuc nang them moi cd vao vi tri cuoi cung cua cdList, Thong tin cd moi do nguoi dung nhap vao\n");
    printf("3. Thuc hien chuc nang cap nhat thong tin cua mot cd. Cho nguoi dung nhap vao ten cua cd muon chinh sua, neu tim thay thi cho nguoi dung tien hanh nhap vao thong tin moi cho cd do. Neu khong tim thay thi in ra man hinh (Khong tim thay)\n");
    printf("4. Thuc hien chuc nang xoa mot cd. Cho nguoi dung nhap vao ten cua cd muon xoa, neu tim thay thi cho nguoi dung tien hanh xoa cd do di. Neu khong tim thay thi in ra man hinh (Khong tim thay)\n");
    printf("5. Thuc hien chuc nang sap xep (Su dung thuat toan sap xep chen) va in ra danh sach cdList da duoc sap xep tang dan (Sap xep theo truong duration)\n");
    printf("6. Thuc hien chuc nang tim kiem (Tim kiem nhi phan) va in ra thong tin cua cd (Tim kiem theo ten)\n");
    printf("7. Thuc hien chuc nang tim kiem va in ra toan bo thong tin cua cac cd theo status\n");
    printf("8. Thoat chuong trinh\n");
    printf("******************************************************\n");
    int choice;
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printCDList(cdList, size);
            break;
        case 2:
            cdList = addCD(cdList, &size);
            break;
        case 3:
            updateCD(cdList, size);
            break;
        case 4:
            cdList = deleteCD(cdList, &size);
            break;
        case 5:
            sortCDList(cdList, size);
            printCDList(cdList, size);
            break;
        case 6:
            searchCDByName(cdList, size);
            break;
        case 7:
            searchCDByStatus(cdList, size);
            break;
        case 8:
            printf("Cam on ban da su dung chuong trinh. Hen gap lai.\n");
            exit(0);
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
            break;
    }
    menu(cdList, size);
}
int main() {
    int size = 2;
    CD* cd
    cdList[1].id = 2;
