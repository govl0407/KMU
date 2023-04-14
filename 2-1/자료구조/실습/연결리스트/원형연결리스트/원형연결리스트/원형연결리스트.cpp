#include<stdio.h>
#include<stdlib.h>
///////////////////////////////// 구조체 init
typedef char element;
typedef struct ListNode
{ // 노드 타입을 구조체로 정의한다.
    element data;
    struct ListNode* next;
}ListNode;

typedef struct ListType
{
    ListNode* tail;
    int size;

}ListType;

void init(ListType* L)
{
    L->tail = NULL;
    L->size = 0;
}

/////////////////////////////insert
void insertlast(ListType* L, element e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    if (L->size == 0)
    {
        L->tail = node;
        node->next = L->tail;
        
    }
    else
    {
        node->next = L->tail->next;
        L->tail->next = node;
        L->tail = node;
    }
    L->size++;
}

void insertfirst(ListType* L, element e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    if (L->size == 0)
    {
        L->tail = node;
        node->next = L->tail;

    }
    else
    {
        node->next = L->tail->next;
        L->tail->next = node;
    }
    L->size++;

}

void insertpos(ListType* L, int pos, element e)//보완 필요
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = L->tail;
    node->data = e;
    if (L->size == 0 && pos ==1)
    {
        L->tail = node;
        node->next = L->tail;

    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            p = p->next;
        }
        
        node->next = p->next;
        p->next = node;
    }
    L->size++;

}

////////////////////delete
element deleteFirst(ListType* L) // 다시 해야함
{
   
    if (L->size == 0)
    {
        printf("Empty");
        return -1;
    }
    ListNode* p = L->tail;
    element e = p->data;
    L->head = p->next;
    free(p);
    L->size--;
    return e;
}
element deleteLast(ListType* L)
{
    ListNode* p = L->tail;
    ListNode* q = p->next;
    element e = p->data;
    
    if (p->next == L->tail)
        L->tail = NULL;
    else
    {
        while (q->next != p)
        {
            q = q->next;
        }
        q->next = p->next;
        L->tail = q;
    }
    free(q);
    L->size--;
}

element delete(ListType* L, int pos)
{
    if (L->size == 0)
    {
        printf("empty\n");
        return -1;
    }
    if (pos > L->size || pos < 1)
    {
        printf("wrong pos");
        return -1;
    }
    else
    {
        ListNode* p = L->head;
        ListNode* q = L->head;
        element e;
        if (pos == 1)
        {
            e = deleteFirst(L);
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                q = p;
                p = p->next;
            }
            e = p->data;
            q->next = p->next;
            free(p);
            L->size--;
            return e;
        }
    }
}


////////////////////print
void print(ListType* L)
{
    ListNode* p = L->tail;
    for (int i = L->size; i > 0; i--)
    {
        printf("%c =>", p->next->data);
        p = p->next;
    }
    printf("\n");
}
////////////////main
int main()
{
    ListType L;
    init(&L);

    insertlast(&L, 'A'); print(&L);
    insertlast(&L, 'B'); print(&L);
    insertlast(&L, 'C'); print(&L);
    insertfirst(&L, 'D'); print(&L);
    insertpos(&L, 3, 'E'); print(&L);


    return 0;
}