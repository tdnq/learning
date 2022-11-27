#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#define N 2
void putStars(int n)
{
    int maxNum = (n - 1) * 2 + 1, spaceNum, starNum;
    char coupyChar = ' ', starChar = '*';
    FILE *tar = fopen("./abc.txt", "w");
    for (int i = 0; i < n; i++)
    {
        starNum = i * 2 + 1;
        spaceNum = (maxNum - starNum) / 2;
        while (spaceNum-- > 0)
        {
            printf("%c", coupyChar);
            fputc(coupyChar, tar);
        }
        while (starNum-- > 0)
        {
            printf("%c", starChar);
            fputc(starChar, tar);
        }
        printf("\n");
        fputc('\n', tar);
    }
    fclose(tar);
    return;
}
int main(void)
{
    return 0;
}