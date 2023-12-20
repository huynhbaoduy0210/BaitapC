#include <stdio.h>
#include <string.h>

int main() {
    char chuoi1[100], chuoi2[100];
    char *ptr_chuoi1, *ptr_chuoi2;

    printf("Nhap chuoi thu nhat: ");
    fgets(chuoi1, sizeof(chuoi1), stdin);

    printf("Nhap chuoi thu hai: ");
    fgets(chuoi2, sizeof(chuoi2), stdin);

    chuoi1[strcspn(chuoi1, "\n")] = '\0';
    chuoi2[strcspn(chuoi2, "\n")] = '\0';

    ptr_chuoi1 = chuoi1;
    ptr_chuoi2 = chuoi2;

    int do_dai_chuoi1 = strlen(ptr_chuoi1);
    int do_dai_chuoi2 = strlen(ptr_chuoi2);

    printf("\nDo dai cua chuoi thu nhat: %d\n", do_dai_chuoi1);
    printf("Do dai cua chuoi thu hai: %d\n", do_dai_chuoi2);

    if (do_dai_chuoi1 > do_dai_chuoi2) {
        printf("Chuoi thu nhat co do dai lon hon.\n");
        printf("Chuoi thu nhat: %s\n", ptr_chuoi1);
    } else if (do_dai_chuoi2 > do_dai_chuoi1) {
        printf("Chuoi thu hai co do dai lon hon.\n");
        printf("Chuoi thu hai: %s\n", ptr_chuoi2);
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }

    return 0;
}
