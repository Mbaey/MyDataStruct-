#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>
int cmp_string(const void *a, const void *b)
{
    char *c = a;
    char *d = b;
    return strcmp(c, d);
}
void SwapString(char *a, char *b)
{
    char c;
    c = *a; *a = *b; *b = c;
}
int Find(char word[][N] ,char *want, int n)
{
    int l, r, m, i;
    l = 0;
    r = n - 1;

//    if(want[0] == '\0')
//        return 0;

    while(l <= r)
    {
        m = l + (r - l) / 2;
        if(strcmp(words[m], want) > 0)
            r = m - 1;
        else if(strcmp(words[m], want) < 0)
            l = m + 1;
        else if((l == r) && (strcmp(words[m], want) != 0))
        {
           break;
        }
        else
        {
            int fi = 0;
            for(i = 0; i <= t; i++)
            {
                if(strcmp(words[m], word_times[i].word) == 0)
                    fi = 1;
            }
            if(fi)
            {
                word_times[t].n ++;
            }
            else
            {
                strcpy(word_times[t].word, want);
                word_times[t].n ++;
                t++;
            }
            int k = strlen(line), j = strlen(want);
            for(i = 0; i < j; i++)
            {
                line[i] = '\0';
            }

            for(i = 0; i < k; i++)
            {
                line[i] = line[i + j];
            }
            //line[] -= want[];
            return 1;

        }
    }


    memset(buf, '\0', sizeof(buf));
    for(i = 0; (i < strlen(want) - 2) && (strlen(want) - 2  > 0); i++)
    {
        buf[i] = want[i];
    }
    memset(buf2, '\0', sizeof(buf2));
    for(i = 0; i < strlen(buf); i++)
    {
        buf2[i] = buf[i];
    }
//    Find(words, buf2, n);
    return 0;

}

void SortWordtimes()
{
    int i, j, max;
    WORDNUM temp;
    for(i = 0; i < t; i++)
    {
        max = i;
        for(j = i; j < t; j++)
        {
            if(word_times[max].n < word_times[j].n)
                max = j;
        }
        if(max != i)
        {
            temp = word_times[max];
            word_times[max] = word_times[i];
            word_times[i] = temp;
        }
    }
}
