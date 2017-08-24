#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>
int main()
{
    memset(words, '\0', sizeof(words));
    FILE *fp1, *fp2;
    fp1 = fopen("D:\\51\\2.txt", "rb");
    if(!fp1) {
        printf("open error!");
        exit(0);
    }
    int i, j = 0, ch;

    for(i = 0; (ch = fgetc(fp1)) != EOF;)
    {
        if((ch == 0x0A))
        {
            j++;
            i = 0;
            continue;
        }
        else if((ch == 0x0D) || (ch == '\0'))
        {
            continue;
        }
        words[j][i] = ch;
        i++;
    }
    fclose(fp1);

    qsort(words, j, sizeof(words[0]), cmp_string);

    int f = j;
    fp2 = fopen("D:\\51\\1.txt", "rb");
    if(!fp2) {printf("open error fp2!");    exit(0);};

    ch = 1;
    while(ch != EOF)
    {
        for(i = 0, memset(line, '\0', sizeof(line)); ((ch = fgetc(fp2)) != 0x0A) && (ch != ' '); )
        {
            if((ch == 0x0A) || (ch == 0x0D) || (ch == ' '))
                continue;
            else if(ch == EOF)
                break;
            line[i++] = ch;
        }
        if(ch == EOF)
            break;
        int flag = 1;
        while(1)
        {
            if(flag == 0)
                flag = Find(words, buf2, f);
            else
                flag = Find(words, line, f);

            if(line[0] == '\0')
                break;
        }
    }

    SortWordtimes();

    for(i = 0; i < t; i++)
    {
        printf("%s:%d\n", word_times[i].word, word_times[i].n);
    }

    fclose(fp2);
    return 0;
}
