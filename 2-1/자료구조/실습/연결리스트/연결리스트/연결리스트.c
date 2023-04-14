#include<stdio.h>
#include<stdlib.h>
///////////////////////////////// ����ü init
typedef char element;
typedef struct ListNode
{ // ��� Ÿ���� ����ü�� �����Ѵ�.
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
element deleteFirst(ListType* L)
{
    if (L->size == 0)
    {
        printf("Empty");
        return -1;
    }
    ListNode* p = L->head;
    element e = p->data;
    L->head = p->next;
    free(p);
    L->size--;
    return e;
}
element deleteLast(ListType* L)//���� �ʿ�
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

element delete(ListType* L, int pos)
{
    if (L->size == 0)
    {
        printf("empty\n");
        return -1;
    }
    if (pos > L->size|| pos<1)
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
    ListNode* p;
    for (p = L->head; p != NULL; p = p->next)
    {
        printf("%c => ", p->data);
    }
    printf("\n");
}
///////////////////////////////����Ʈ �ڸ���








//////////////////////////////////�ΰ��� ����Ʈ ����







///////////////����
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

    printf("[%c] is deleted \n", deleteFirst(&L)); print(&L);
    printf("[%c] is deleted \n", delete(&L, 3)); print(&L);
    return 0;
}


