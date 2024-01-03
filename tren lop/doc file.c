#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fin = fopen("sinhvien.txt", "r");
    FILE *fout = fopen("sinhvien_out.txt", "r");
    if (fin == NULL || fout == NULL)
    {
        printf("khong the mo file.\n");
        exit(1);
    }

    char line[100];
    char word[20];
    char *token;
    int len;
    int i;
    fgets(line, 100, fin);
    fputs(line, fout);
    while (fgets(line, 100, fin) != NULL)
    {
        // Xóa ký tự xuống dòng ở cuối line
        len = strlen(line);
        if (line[len - 1] == '\n')
            line[len - 1] = '\0';
        token = strtok(line, " ");
        while (token != NULL)
        {
            word[0] = toupper(token[0]);

            for (i = 1; i < strlen(token); i++)
            {
                word[i] = tolower(token[i]);
            }

            word[i] = '\0';
            strcat(line, word);
            strcat(line, " ");

            token = strtok(NULL, " ");
        }
        fputs(line, fout);
        fputc('\n', fout);
        line[0] = '\0';
    }
    fclose(fin);
    fclose(fout);

    return 0;
}




