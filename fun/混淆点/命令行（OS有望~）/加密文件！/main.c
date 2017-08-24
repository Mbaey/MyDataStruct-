#include <stdio.h>
#include <stdlib.h>  //atoi()
#include <assert.h>
int main(int argc, char *argv[])
{
    FILE *fp, *fp2;
    int a, i = 0, j;
    int password = argv[2];  //我也不知道为什么atoi(argv[2]) 会错、、、、、、
    char buf[240*1024];
    printf("password is %d\n", password);
    if(argc != 3)
    {
        printf("Usage: %s <filename> <password>", argv[0]);
        exit(0);
    }
    fp = fopen(argv[1], "rb+");
    assert(fp != NULL);

    while((a = fgetc(fp)) != EOF)
    {
        buf[i++] = a;
    }
    fclose(fp);
    fp2 = fopen(argv[1], "wb+");
    assert(fp2 != NULL);
    for(j = 0; j < i + 1; j++)
    {
        fputc(buf[j] ^ password, fp2);
    }
    fclose(fp2);

    printf("Success ~\n");
    return 0;
}
