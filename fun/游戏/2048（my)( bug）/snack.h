#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

                 /* ��Ϸ��ͼ */
int	key;                            /*�������� */

int	dx[4]	= { 0, 0, -1, 1 };      /* ���ҡ��ϡ��µķ��� */
int	dy[4] = { -1, 1, 0, 0 };
                   /* '0'�ڵ�ͼ�ϱ�ʾΪ�� */
void Initial();                         /* ��ͼ�ĳ�ʼ�� */
void Create_Food();                     /* �ڵ�ͼ���������ʳ�� */
void Show();                            /* ˢ����ʾ��ͼ */
void Button();                          /* ȡ������,���жϷ��� */
void Move();                            /* �ߵ��ƶ� */
void Check_Border();                    /* �����ͷ�Ƿ�Խ�� */
void Check_Head( int x, int y );        /* �����ͷ�ƶ����λ����� */
