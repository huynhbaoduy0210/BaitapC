#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    char class[10];
    char dob[15];
    double gpa;
} student;

int compare(const void *a, const void *b) {
    student *stuA = (student *)a;
    student *stuB = (student *)b;
    if (stuA->gpa > stuB->gpa) return -1;
    if (stuA->gpa < stuB->gpa) return 1;
    return 0;
}

int main() {

    char line[100];
    char *token;
    student *arrStu = NULL;
    int n = 0;
    int i;


    FILE *fin = fopen("sinhvien.txt", "r");
    FILE *fout = fopen("sinhvien_out.txt", "w");
    if (fin == NULL || fout == NULL) {
        printf("khong the mo file.\n");
        exit(1);
    }


    while (fgets(line, 100, fin) != NULL) {

        student stu;

        token = strtok(line, ",");

        strcpy(stu.name, token);

        token = strtok(NULL, ",");
        strcpy(stu.class, token);


        token = strtok(NULL, ",");
        strcpy(stu.dob, token);


        token = strtok(NULL, ",");
        stu.gpa = atof(token);

        arrStu = (student *)realloc(arrStu, sizeof(student) * (n + 1));
        arrStu[n] = stu;
        n++;
    }

    qsort(arrStu, n, sizeof(student), compare);

    for (i = 0; i < n; i++) {
        fprintf(fout, "%s,%s,%s,%.1f\n", arrStu[i].name, arrStu[i].class, arrStu[i].dob, arrStu[i].gpa);
    }

    free(arrStu);

    fclose(fin);
    fclose(fout);

    return 0;
}

