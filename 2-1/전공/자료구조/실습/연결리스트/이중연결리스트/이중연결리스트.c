#include<stdio.h>
#include<stdlib.h>

typedef char element;
///////////////////////////////////////////////////////init
typedef struct DListNode
{
    element data;
    struct DListNode* prev;
    struct DListNode* next;
}DListNode;

typedef struct
{
    DListNode* H;
    DListNode* T;
    int N;
}DListType;

DListNode* getNode()
{
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->next = node->prev = NULL;
    return node;
}

void init(DListType* DL)
{
    DL->H = getNode();
    DL->T = getNode();
    DL->H->next = DL->T;
    DL->T->prev = DL->H;
    DL->N = 0;
}

/////////////////////////////////////////////////////////////////////////insert
void insertFirst(DListType* DL, element e)
{
    DListNode* node = getNode();
    DListNode* p = DL->H;
    node->data = e;
    node->prev = p;
    node->next = p->next;
    
    p->next->prev = node;
    p->next = node;
    DL->N++;
}

void insertLast(DListType* DL, element e)
{
    DListNode* node = getNode();
    DListNode* p = DL->T;
    node->data = e;
    node->next = p;
    node->prev = p->prev;

    p->prev->next = node;
    p->prev = node;

    DL->N++;
}

void insertPos(DListType* DL, int pos, element e)
{
    if (pos<1 || pos > DL->N + 1)
    {
        printf("invalide pos");
    }
    else
    {
        DListNode* node = getNode();
        DListNode* p = DL->H;
        for (int i = 1; i < pos; i++)
            p = p->next;
        node->data = e;

        node->prev = p;
        node->next = p->next;

        p->next->prev = node;
        p->next = node;

        DL->N++;

    }
  
}

//////////////////////////////////////////////////////////////////////delete
element delete(DListType* DL, int pos)
{
    element e = -1;
    if (pos <1 || pos>DL->N)
        printf("invalid pos");
    else
    {
        DListNode* p = DL->H;
        for (int i = 0; i < pos; i++)
            p = p->next;
        e = p->data;

        p->prev->next = p->next;
        p->next->prev = p->prev;

        free(p);
        DL->N--;
    }
    return e;
}


//////////////////////////////////////////////////////////////////print
void print(DListType* DL)
{
    DListNode* H = DL->H;
    DListNode* T = DL->T;
    while (H->next != T)
    {
        printf("<< [%c] >> ",H->next->data);
        H = H->next;
    }
    printf("\n");

}
//////////////////////////////////////////////main
int main()
{
    DListType DL;
    init(&DL);
    
    insertFirst(&DL, 'c'); print(&DL);
    insertFirst(&DL, 'b'); print(&DL);
    insertFirst(&DL, 'a'); print(&DL);

    insertLast(&DL, 'D'); print(&DL);

    printf("%c : delted \n", delete(&DL, 3)); print(&DL);

    print(&DL);
    return 0;
}