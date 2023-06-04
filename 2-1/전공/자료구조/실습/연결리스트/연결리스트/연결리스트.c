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
element deleteLast(ListType* L)//수정 필요
{
    element e;
    if (L->size == 0)
    {
        printf("Empty");
        e = -1;
    }
       
    else if (L->size == 1)
    {

        ListNode* p = L->head;
        e = p->next->data;
        L->head = NULL;

        L->size--;
    }
    else
    {
        ListNode* p = L->head;

        for (int i = 1; i < L->size - 1; i++)
            p = p->next;
        e = p->next->data;
        p->next = NULL;
        L->size--;
    }
    return e;
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
///////////////////////////////리스트 자르기
ListType slice(ListType* L, int f, int l)
{
    ListType NL;
    init(&NL);
    for (int i = f; i <= l; i++)
        insertLast(&NL, delete(L, f));//pos가 왜 맘대로 4로 바뀌는가
    return NL;
}







//////////////////////////////////두개의 리스트 연결
ListType combine(ListType* L, ListType* M)
{
    ListType NL;
    init(&NL);
    ListNode* p = L->head;
    for(int i=0;i<L->size;i++)
    {
        insertLast(&NL,p->data);
        p = p->next;
    }

    p = M->head;
    for (int i = 0; i < M->size; i++)
    {
        insertLast(&NL, p->data);
        p = p->next;
    }

    return NL;


}






///////////////메인
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
    insertLast(&L, 'H'); print(&L);
    insertLast(&L, 'I'); print(&L);
    insertLast(&L, 'J'); print(&L);

    printf("[%c] is deleted \n", deleteFirst(&L)); print(&L);
    printf("[%c] is deleted \n", delete(&L, 3)); print(&L);
    printf("[%c] is deleted \n", deleteLast(&L)); print(&L);
    /*
    ListType M;
    init(&M);

    insertLast(&M, 'A'); 
    insertLast(&M, 'B');
    insertLast(&M, 'C'); 
    
    printf("\n M : \n");
    print(&M);
    */
    ListType NL;
    init(&NL);
    printf("\n \n NL : ");

    NL = slice(&L, 2, 3);
    print(&NL);
    print(&L)

    
    
    return 0;
}


