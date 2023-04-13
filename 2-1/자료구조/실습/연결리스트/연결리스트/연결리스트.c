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
    ListNode* head;
    int size;

}ListType;

void init(ListType* L)
{
    L->head = NULL;
    L->size = 0;
}

////////////////////////////////insert
void insertFirst(ListType *L , element e)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));//
    node->data = e;
    node->next = L->head; 
    L->head = node;
    L->size++;
}


void insertLast(ListType *L, element e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = NULL;
    if (L->size == 0)
    {
        L->head = node;
    }
    else {
        ListNode* p;
        for (p = L->head; p->next != NULL; p = p->next);
        p->next = node;
    }
    L->size++;
}

void insert(ListType* L, int pos, element e)
{
    if (pos == 1)
        insertFirst(L, e);
    else if(pos == L->size + 1)
        insertLast(L, e);
    else
    {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        ListNode* p = L->head;

        for (int i = 1; i<pos-1; i++)
            p = p->next;

        node->data = e;
        node->next = p->next;
        p->next = node;
        L->size++;
    }
}


////////////////////delete
void deleteFirst(ListType* L)
{
    if (L->size == 0)
        printf("Empty");
    else if(L->size == 1)
    {

        ListNode* p = L->head;
        L->head = NULL;

        L->size--;
    }
    else
    {
        ListNode* p = L->head;
        L->head = p->next;

        L->size--;
    }
}
void deleteLast(ListType* L)
{
    if (L->size == 0)
        printf("Empty");
    else if (L->size == 1)
    {

        ListNode* p = L->head;
        L->head = NULL;

        L->size--;
    }
    else
    {
        ListNode* p = L->head;

        for (int i = 1; i < L->size - 1; i++)
            p = p->next;

        p->next = NULL;
        L->size--;
    }
}

void delete(ListType* L, int pos)
{
    if (pos > L->size)
        printf("wrong pos");
    else if(pos == L->size && L->size ==1)
    {
        ListNode* p = L->head;
        L->head = NULL;
        L->size--;
    }
    else if (pos == 1)
    {
        ListNode* p = L->head;
        L->head = p->next;

        L->size--;

    }
    else
    {
        ListNode* p = L->head;

        for (int i = 1; i<pos-1; i++)
            p = p->next;

        
       
        p->next = p->next->next;
        L->size--;
    }
}

////////////////////print
void print(ListType* L)
{
    ListNode* p;
    for (p = L->head; p != NULL; p = p->next)
    {
        printf("%c => ", p->data);
    }
    printf("\n");
}

int main()
{
    ListType L;
    init(&L);

    insertLast(&L, 'A'); print(&L);
    insertLast(&L, 'B'); print(&L);
    insertLast(&L, 'C'); print(&L);
    insertLast(&L, 'D'); print(&L);
    insertLast(&L, 'E'); print(&L);
    insertLast(&L, 'F'); print(&L);
    insertLast(&L, 'G'); print(&L);

    
    deleteFirst(&L); print(&L);
    deleteLast(&L); print(&L);
    delete(&L,3); print(&L);

    return 0;
}


