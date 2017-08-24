#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "snack.h"

void Initial()                                          /* 地图的初始化 */
{
	int	i, j;
	int	hx, hy;
	system( "title 2048" );                          /* 控制台的标题 */
	memset( GameMap, '0', sizeof(GameMap) );        /* 初始化地图全部为空'.' */
	system( "cls" );
	srand( time(NULL) );                             /* 随机种子 */
	hx		= rand() % H;                   /* 产生蛇头 */
	hy		= rand() % L;
	GameMap[hx][hy] = New;
	Create_Food();                                  /* 随机产生食物 */
	for ( i = 0; i < H; i++ )                       /* 地图显示 */
	{
		for ( j = 0; j < L; j++ )
			printf( "%d", GameMap[i][j] );
		printf( "\n" );
	}

	printf( "\nMY 2048\n" );
	printf( "Press any key to start game\n" );

	getch();        /* 先接受一个按键,使蛇开始往该方向走 */
	Button();       /* 取出按键,并判断方向 */
}

void Create_Food()      /* 在地图上随机产生食物 */
{
	int fx, fy;
	while ( 1 )
	{
		fx	= rand() % H;
		fy	= rand() % L;

		if ( GameMap[fx][fy] == 0 ) /*不能出现在蛇所占有的位置 */
		{
			GameMap[fx][fy] = 1;
			break;
		}
	}
}

void Show()                             /* 刷新显示地图 */
{
	int i, j;
	while ( 1 )
	{
		_sleep( 500 );          /* 延迟半秒(1000为1s),即每半秒刷新一次地图 */
		Button();               /* 先判断按键在移动 */
		Move();
        system( "cls" );        /* 清空地图再显示刷新吼的地图 */
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


void Button()                           /* 取出按键,并判断方向 */
{
	if ( kbhit() != 0 )             /* 检查当前是否有键盘输入，若有则返回一个非0值，否则返回0 */
	{
		while ( kbhit() != 0 )  /* 可能存在多个按键,要全部取完,以最后一个为主 */
			key = getch();  /* 将按键从控制台中取出并保存到key中 */
		switch ( key )
		{ /* 左 */
		case 75:  Direct = 0;
			break;
		/* 右 */
		case 77:  Direct= 1;
			break;
		/*上 */
		case 72:  Direct = 2;
			break;
		/*下 */
		case 80:  Direct = 3;
			break;
		}
	}
}


void Move()                                                     /* 蛇的移动 */
{
	int	i, j, x, y;
	/* 记录当前蛇头的位置,并设置为空,蛇头先移动 */
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
