#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define N 10

typedef char element;

typedef struct
{
    element data[N];
    int front, rear;
}DequeType;

void init(DequeType* D)
{
    D->front = D->rear = 0;
}
//////////////////////////////// 
int isFull(DequeType* D)
{
    return  D->front % N == (D->rear + 1) % N;
}

int isEmpty(DequeType* Q)
{
    return Q->front == Q->rear;
}



////////////////////////////// ���Կ���
void add_front(DequeType* D, element e)
{
    if (isFull(D))
        printf("FULL\n");
    else if(D->front!=0)
    {
        D->front = (D->front - 1) % N;
        D->data[D->front] = e;
    }
    else {

        D->front = N-1;
        D->data[D->front] = e;
    }
}
void add_rear(DequeType* D, element e)
{
    if (isFull(D))
        printf("FULL\n");
    else
    {
        D->data[D->rear] = e;
        D->rear = (D->rear + 1) % N;
    }
}



////////////////////////////////////// ��������
element delete_front(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("EMPTY\n");
        return 0;
    }
    element d = D->data[D->front];
    D->front = (D->front + 1) % N;
    return d;
}
element delete_rear(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("EMPTY\n");
        return 0;
    }
    
    int pos = D->rear-1;
    element d = D->data[pos];
    D->rear = (D->rear - 1 + N) % N;
    return d;

}


/////////////////////////////////////// GET
element get_front(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("EMPTY\n");
        return 0;
    }
    return D->data[(D->front + 1) % N];
}
element get_rear(DequeType* D)
{
    if (isEmpty(D))
    {
        printf("EMPTY\n");
        return 0;
    }
    return D->data[(D->rear)-1];
}




void print(DequeType* D)
{
    int i = D->front;
    while (i != D->rear)
    {
        
        printf("[%c] ", D->data[i]);
        i = (i + 1) % N;
    }
    printf("front : %d / rear : %d", D->front, D->rear);
    printf("\n");
}


int getCount(DequeType* D)
{
    int count = D->rear - D->front;
    if (count < 0)
        count += N;

    return count;
}

int main()
{
    DequeType D;
    init(&D);

    add_front(&D, 'c'); print(&D);
    add_front(&D, 'b'); print(&D);
    add_front(&D, 'a'); print(&D);
    add_rear(&D, 'A');  print(&D);
    add_rear(&D, 'B');  print(&D);
    add_rear(&D, 'C');  print(&D);

    printf("%c is deleted ", delete_front(&D)); print(&D);
    printf("%c is deleted ", delete_rear(&D)); print(&D);



    //////////////////// ȸ�� �ǵ�
    /*
    char str[N];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        addRear(&D, str[i]);
    }
    int equal = 1; //flag

    while (getCount(&D) > 1 && equal == 1)
    {
        char first = deleteFront(&D);
        char last = deleteRear(&D);
        if (first != last)
            equal = 0;
    }
    if (equal == 1)
        printf("yes");
    else
        printf("no");
    */
    return 0;
}