#include <stdio.h>
#include <stdlib.h>

typedef struct music
{
    char head[4];
    char name[31];
    char artist[31];
    char zhuanji[31];
    char year[5];
    char comment[31];
    char pai[2];
}M;

//前3个字节是固定不变的“TAG”三个字符。如果不是这三个字符，说明这个文件不含有ID3信息。
//接下来依次是30个字节的歌名、30个字节的艺术家名、30个字节的专辑名、4个字节的年份、30个字节的评论和1个字节的流派。
//每一项如果不能占满规定的字节数，那么剩余的字节就用0填充。

int main()
{
    FILE *fp;
    M m;
    fp = fopen("王菲.mp3", "rb");
    if(!fp) { printf("error\n"); exit(0); }

    fseek(fp, -128, SEEK_END);
    fread(m.head, 3, 1, fp);
    m.head[3] = '\0';
    printf("%s\n", m.head);

    fread(m.name, 30, 1, fp);
    m.name[30] = '\0';
    printf("%s\n", m.name);

    fread(m.artist, 30, 1, fp);
    m.artist[30] = '\0';
    printf("%s\n", m.artist);

    fread(m.zhuanji, 30, 1, fp);
    m.zhuanji[30] = '\0';
    printf("%s\n", m.zhuanji);

    fread(m.year, 3, 1, fp);
    m.year[3] = '\0';
    printf("%s\n", m.year);

    fread(m.comment, 30, 1, fp);
    m.comment[30] = '\0';
    printf("%s\n", m.comment);

    fread(m.pai, 1, 1, fp);
    m.pai[1] = '\0';
    printf("%s\n", m.pai);

    fclose(fp);
    return 0;
}
