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

//ǰ3���ֽ��ǹ̶�����ġ�TAG�������ַ�����������������ַ���˵������ļ�������ID3��Ϣ��
//������������30���ֽڵĸ�����30���ֽڵ�����������30���ֽڵ�ר������4���ֽڵ���ݡ�30���ֽڵ����ۺ�1���ֽڵ����ɡ�
//ÿһ���������ռ���涨���ֽ�������ôʣ����ֽھ���0��䡣

int main()
{
    FILE *fp;
    M m;
    fp = fopen("����.mp3", "rb");
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
