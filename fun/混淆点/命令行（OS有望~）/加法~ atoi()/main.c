#include  <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int  i, j;
	printf("The number of command line arguments is:%d\n", argc);
	printf("The program name is:%s\n", argv[0]);
	if (argc != 3)
	{
		printf("Input error!:\n");
		printf("Usage: %s <data1> <data2>\n", argv[0]);
		exit(0);
	}

	i = atoi(argv[1]);
	j = atoi(argv[2]);
	printf("%d", i + j);

	return 0;
}
