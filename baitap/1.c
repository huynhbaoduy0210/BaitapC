#include<stdio.h>
#include <string.h>

struct City {
    char name[50];
    int income;
    int population;
    float literacyRate;
};

int main() {
    struct City cities[3];
            cities[3];
    int i, maxIncomeIndex = 0, maxLiteracyIndex = 0;


    for (i = 0; i < 3; i++) {
        printf(" nhap thong tin thanh pho %d:\n", i + 1);
        printf("Ten thanh pho: ");
        scanf("%s", cities[i].name);
        printf("Tong thu nhap: ");
        scanf("%d", &cities[i].income);
        printf("dan so: ");
        scanf("%d", &cities[i].population);
        printf("ti le biet doc viet: ");
        scanf("%f", &cities[i].literacyRate);
    }


    for (i = 1; i < 3; i++) {
        if (cities[i].income > cities[maxIncomeIndex].income) {
            maxIncomeIndex = i;
        }
    }


    for (i = 1; i < 3; i++) {
        if (cities[i].literacyRate > cities[maxLiteracyIndex].literacyRate) {
            maxLiteracyIndex = i;
        }
    }


    printf("\nthanh pho co tong thu nhap cao nhat la %s voi tong thu nhap la %d.\n", cities[maxIncomeIndex].name, cities[maxIncomeIndex].income);
    printf("thanh pho co ti le biet doc viet cao nhat la %s voi ti le biet đoc viet la %.2f.\n", cities[maxLiteracyIndex].name, cities[maxLiteracyIndex].literacyRate);

    return 0;
}
