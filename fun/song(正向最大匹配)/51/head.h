#define M 500000
#define N 51
#define SIZE 1000

typedef struct wordnum
{
    char word[50];
    int  n;
}WORDNUM;
WORDNUM word_times[SIZE];

char words[M][N];
char line[1024];
char buf[1024];
char buf2[1024];
int t;
int cmp_string(const void *a, const void *b);
int Find(char words[][N], char *want, int n);
void SwapString(char *a, char *b);
void SortWordtimes();
