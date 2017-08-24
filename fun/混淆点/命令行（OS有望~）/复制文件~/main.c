#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(int argc, char *argv[])
{
    FILE *fp, *fp2;
    int a, i = 0, j;

    char buf[240*1024];

    if(argc != 3)
    {
        printf("Usage: %s <filename> <copy filename>", argv[0]);
        exit(0);
    }
    fp = fopen(argv[1], "rb+");
    assert(fp != NULL);

    while((a = fgetc(fp)) != EOF)
    {
        buf[i++] = a;
    }
    fclose(fp);
    fp2 = fopen(argv[2], "wb+");
    assert(fp2 != NULL);
    for(j = 0; j < i + 1; j++)
    {
        fputc(buf[j], fp2);
    }
    fclose(fp2);

    printf("Success ~\n");
    return 0;
}
