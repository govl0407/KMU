#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef char element;

typedef struct
{
    element data[N];
    int front, rear;

}QueueType;

void init(QueueType* Q)
{
    Q->front = Q->rear = 0;
}

int isFull(QueueType* Q)
{
    return  Q->front % N == (Q->rear + 1) % N;
}

int isEmpty(QueueType* Q)
{
    return Q->front == Q->rear;
}




void add_rear(QueueType* Q, element e)
{
    if (isFull(Q))
        printf("FULL\n");
    else
    {
        Q->rear = (Q->rear + 1) % N;
        Q->data[Q->rear] = e;
    }
}
void add_front(QueueType* Q, element e)
{
    if (isFull(Q))
        printf("FULL\n");
    else if(Q->front ==0)
    {
        Q->front = N-1;
        Q->data[Q->front] = e;
    }
    else
    {
        Q->front = (Q->front - 1) % N;
        Q->data[Q->front] = e;
    }
}


element delete_front(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("EMPFTY\n");
        return 0;
    }
    Q->front = (Q->front + 1) % N;
    return Q->data[Q->front];
}
element delete_rear(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("EMPFTY\n");
        return 0;
    }
    Q->front = (Q->rear - 1) % N;
    return Q->data[Q->rear];
}



element get_front(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("EMPFTY\n");
        return 0;
    }
    return Q->data[(Q->front + 1) % N];
}
element get_rear(QueueType* Q)
{
    if (isEmpty(Q))
    {
        printf("EMPFTY\n");
        return 0;
    }
    return Q->data[(Q->rear + 1) % N];
}




void print(QueueType* Q)
{
    int i = Q->front;
    while (i != Q->rear)
    {
        i = (i + 1) % N;
        printf("[%c] ", Q->data[i]);

    }
    printf("front : %d / rear : %d", Q->front, Q->rear);
    printf("\n");
}
int main()
{
    QueueType Q;
    init(&Q);

    srand(time(NULL));

    for (int i = 0; i < 7; i++)
    {
        enqueue(&Q, rand() % 26 + 65);
    }
    

    return 0;
}