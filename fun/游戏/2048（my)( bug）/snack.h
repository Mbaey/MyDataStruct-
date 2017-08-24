#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

                 /* 游戏地图 */
int	key;                            /*按键保存 */

int	dx[4]	= { 0, 0, -1, 1 };      /* 左、右、上、下的方向 */
int	dy[4] = { -1, 1, 0, 0 };
                   /* '0'在地图上标示为空 */
void Initial();                         /* 地图的初始化 */
void Create_Food();                     /* 在地图上随机产生食物 */
void Show();                            /* 刷新显示地图 */
void Button();                          /* 取出按键,并判断方向 */
void Move();                            /* 蛇的移动 */
void Check_Border();                    /* 检查蛇头是否越界 */
void Check_Head( int x, int y );        /* 检查蛇头移动后的位置情况 */
