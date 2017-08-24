#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_QUEUE_LENGTH 10

typedef int elemtype;
typedef struct queue
{
    elemtype data[MAX_QUEUE_LENGTH];
    int front, rear;
}Queue;
//1.初始化一个循环队列
//2.入队列
//3.出队列
//ps(不用销毁)

//void InitQ(Queue *q)
//{
//    q->front = q->rear = 0;
//}
//
//void InQ(Queue *q, elemtype d)
//{
//    if((q->rear-q->front)==9 || (q->front-q->rear)==1)    /*傻X*/
//    if ((q->rear+1)%MAX_QUEUE_LENGTH == q->front)
//    {
//        printf("满了！\n");
//        return;
//    }
//    else
//    {
//        q->data[q->rear] =  d;
//        q->rear = (++q->rear) % MAX_QUEUE_LENGTH;
//    }
//}
//
//void OutQ(Queue *q, elemtype *e)
//{
//    if(q->rear == q->front)
//    {
//        printf("空的！\n");
//        return -1;
//    }
//    else
//    {
//        *e = q->data[q->front];
//        q->front = (q->front + 1) % MAX_QUEUE_LENGTH;
//    }
//}


//初始化
void InitQueue(Queue *Q)
{
    Q->front = Q->rear = 0;
}

//入队
void EnQueue(Queue *Q, int e)
{
    if ((Q->rear+1)%MAX_QUEUE_LENGTH == Q->front)
        return ;

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAX_QUEUE_LENGTH;
}

//判空
int QueueEmpty(Queue *Q)
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

//出队
void DeQueue(Queue *Q, int *e)
{
    if (Q->front == Q->rear)
        return ;

    *e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAX_QUEUE_LENGTH;
}

int main()
{
    elemtype d;
    Queue q;
    int i = 0;
    InitQueue(&q);
    for(i = 0; i < 11; i++)
    {
        EnQueue(&q, i);
    }

    for(i = 0; i < 3; i++)
    {
        DeQueue(&q, &d);
        printf("%d  ", d);
    }

    for(i = 3; i < 5; i++)
    {
        EnQueue(&q, i);
    }

    while(!QueueEmpty(&q))
    {
        DeQueue(&q, &d);
        printf("No.%d  ", d);
    }
//    InQ(&q, 16465446);
//    OutQ(&q, &d);

    return 0;
}
