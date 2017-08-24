#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "snack.h"

void Initial()                                          /* ��ͼ�ĳ�ʼ�� */
{
	int	i, j;
	int	hx, hy;
	system( "title 2048" );                          /* ����̨�ı��� */
	memset( GameMap, '0', sizeof(GameMap) );        /* ��ʼ����ͼȫ��Ϊ��'.' */
	system( "cls" );
	srand( time(NULL) );                             /* ������� */
	hx		= rand() % H;                   /* ������ͷ */
	hy		= rand() % L;
	GameMap[hx][hy] = New;
	Create_Food();                                  /* �������ʳ�� */
	for ( i = 0; i < H; i++ )                       /* ��ͼ��ʾ */
	{
		for ( j = 0; j < L; j++ )
			printf( "%d", GameMap[i][j] );
		printf( "\n" );
	}

	printf( "\nMY 2048\n" );
	printf( "Press any key to start game\n" );

	getch();        /* �Ƚ���һ������,ʹ�߿�ʼ���÷����� */
	Button();       /* ȡ������,���жϷ��� */
}

void Create_Food()      /* �ڵ�ͼ���������ʳ�� */
{
	int fx, fy;
	while ( 1 )
	{
		fx	= rand() % H;
		fy	= rand() % L;

		if ( GameMap[fx][fy] == 0 ) /*���ܳ���������ռ�е�λ�� */
		{
			GameMap[fx][fy] = 1;
			break;
		}
	}
}

void Show()                             /* ˢ����ʾ��ͼ */
{
	int i, j;
	while ( 1 )
	{
		_sleep( 500 );          /* �ӳٰ���(1000Ϊ1s),��ÿ����ˢ��һ�ε�ͼ */
		Button();               /* ���жϰ������ƶ� */
		Move();
        system( "cls" );        /* ��յ�ͼ����ʾˢ�º�ĵ�ͼ */
		for( i = 0; i < H; i++ )
		{
			for ( j = 0; j < L; j++ )
				printf( "%d", GameMap[i][j] );
			printf( "\n" );
		}
		printf( "\nMY 2048\n" );
		printf( "Press any key to start game\n" );
	}
}


void Button()                           /* ȡ������,���жϷ��� */
{
	if ( kbhit() != 0 )             /* ��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0 */
	{
		while ( kbhit() != 0 )  /* ���ܴ��ڶ������,Ҫȫ��ȡ��,�����һ��Ϊ�� */
			key = getch();  /* �������ӿ���̨��ȡ�������浽key�� */
		switch ( key )
		{ /* �� */
		case 75:  Direct = 0;
			break;
		/* �� */
		case 77:  Direct= 1;
			break;
		/*�� */
		case 72:  Direct = 2;
			break;
		/*�� */
		case 80:  Direct = 3;
			break;
		}
	}
}


void Move()                                                     /* �ߵ��ƶ� */
{
	int	i, j, x, y;
	/* ��¼��ǰ��ͷ��λ��,������Ϊ��,��ͷ���ƶ� */
	if(Direct == 0)
    {
        for ( j = 3; j > 0; j-- )
        {
            for ( i = 1; i < H; i++ )
            {
                if(GameMap[i][j - 1] == 0)
                    Swap(GameMap[i][j], GameMap[i][j - 1]);
                else if(GameMap[i][j] == GameMap[i][j - 1]
                {
                    GameMap[i][j] = 0;  GameMap[i][j - 1] *= 2;
                }
            }
        }
    }
    else if(Direct == 1)
    {
        for ( j = 0; j < 3; j++ )
        {
            for ( i = 1; i < H; i++ )
            {
                if(GameMap[i][j + 1] == 0)
                    Swap(GameMap[i][j], GameMap[i][j + 1]);
                else if(GameMap[i][j] == GameMap[i][j + 1])
                {
                    GameMap[i][j] = 0;  GameMap[i][j + 1] *= 2;
                }
            }
        }
    }
    else if(Direct == 3)
    {
        for ( i = 0; i < 3; i++ )
        {
            for ( j = 1; j < H; j++ )
            {
                if(GameMap[i + 1][j] == 0)
                    Swap(GameMap[i][j], GameMap[i + 1][j]);
                else if(GameMap[i][j] == GameMap[i + 1][j])
                {
                    GameMap[i][j] = 0;  GameMap[i + 1][j] *= 2;
                }
            }
        }
    }
    else
    {
        for ( i = 3; i > 0; i-- )
        {
            for ( j = 1; j < H; j++ )
            {
                if(GameMap[i - 1][j] == 0)
                    Swap(GameMap[i][j], GameMap[i - 1][j]);
                else if(GameMap[i][j] == GameMap[i - 1][j])
                {
                    GameMap[i][j] = 0;  GameMap[i - 1][j] *= 2;
                }
            }
        }
    }
}

void Swap(int a, int b)
{
    int t;
    t = a; a = b; b = t;
}
