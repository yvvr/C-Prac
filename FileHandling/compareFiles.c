//C program to compare between two files.

#include <stdio.h>

void compare(FILE *fp1, FILE *fp2)
{

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error : Files are empty");
        return;
    }

    int error = 0, pos = 0, line = 1;
    int nlCh1 = 0, nlCh2 = 0;

    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    while (ch1 != EOF && ch2 != EOF)
    {
        pos++;

        if (ch1 == '\n')
            nlCh1 = 1;

        if (ch2 == '\n')
            nlCh2 = 1;

        if (nlCh1 && nlCh2)
        {
            line++;
            pos = 0;
            nlCh1 = 0, nlCh2 = 0;
        }

        if (ch1 != ch2)
        {
            error++;
            printf("Error at Line number: %d,\t Error position :%d,\t char1 :%c,char2 :%c\n", line, pos, ch1, ch2);
        }

        if (!nlCh1)
            ch1 = getc(fp1);
        if (!nlCh2)
            ch2 = getc(fp2);
    }
}

int main()
{
    FILE *file1 = fopen("input/sampleFile1.txt", "r");
    FILE *file2 = fopen("input/sampleFile2.txt", "r");

    compare(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}