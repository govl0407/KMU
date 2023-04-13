#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 100

typedef char element;

typedef struct {
    element data[N];
    int size;
}ListType;

void init(ListType* L)
{
    L->size = 0;
}


int isEmpty(ListType* L)
{
    return L->size == 0;
}
int isFull(ListType* L)
{
    return L->size == N;
}
///////////////////////////////////////////////////////////// 데이터 삽입

void insert(ListType* L, int pos, element e)
{
    if (!isFull(L) && pos >= 0 && pos <= L->size)
    {
        for (int i = L->size - 1; i > pos; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos] = e;
        L->size++;
    }
}

void insertLast(ListType* L, element e)
{
    if (isFull(L))
        printf("Full\n");
    else
    {
        L->data[L->size] = e;
        L->size++;
    }
}

////////////////////////////// 데이터 제거
element delete(ListType* L, int pos)
{
    if (isEmpty(L) || pos < 0 || pos >= L->size)
    {
        printf("Error\n");
        return -1;
    }
    element data = L->data[pos];

    for (int i = pos; i < (L->size - 1); i++)
        L->data[i] = L->data[i + 1];
    L->size--;
    return data;

}

//////////////////////////////////// 출력
void print(ListType* L)
{
    for (int i = 0; i < L->size; i++)
        printf("%d ",L->data[i]);
    printf("\n");
}

///////////////////////////////////
int main()
{
    ListType L;

    insertLast(&L, 'A');
    print(&L);
    insertLast(&L, 'B');
    print(&L);
    insertLast(&L, 'C');
    print(&L);

    insert(&L, 0, 'D');
    print(&L);
    insert(&L, 2, 'E');
    print(&L);


    printf("%d is deleted", delete(&L, 'B'));
    return 0;
}