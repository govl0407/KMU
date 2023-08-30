#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0

typedef int element;
/* --------------------------------���� */
typedef struct
{
    element data[N];
    int top;
}StackType;

void initStack(StackType* S)
{
    S->top = -1;
}

int isStackEmpty(StackType* S)
{
    return S->top == -1;
}

int isStackFull(StackType* S)
{
    return S->top == N - 1;
}

void push(StackType* S, element d)
{
    if (isStackFull(S))
        printf("Overflow!!\n");
    else
    {
        S->top++;
        S->data[S->top] = d;
    }
}

element pop(StackType* S)
{
    if (isStackEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }

    element d = S->data[S->top];
    S->top--;
    return d;
}

element peek(StackType* S)
{
    if (isStackEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    return S->data[S->top];
}

/* --------------------------------ť */
typedef struct
{
    element data[N];
    int front, rear;
}QueueType;


void initQueue(QueueType* Q)
{
    Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q)
{
    return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q)
{
    return (Q->rear + 1) % N == Q->front;
}

void enqueue(QueueType* Q, element d)
{
    if (isQueueFull(Q))
        printf("Overflow!!\n");
    else
    {
        Q->rear = (Q->rear + 1) % N;
        Q->data[Q->rear] = d;
    }
}

element dequeue(QueueType* Q)
{
    if (isQueueEmpty(Q))
    {
        printf("Empty!!\n");
        return -1;
    }
    Q->front = (Q->front + 1) % N;
    return Q->data[Q->front];
}

/* -------------------------------- */

typedef struct IncidentEdge//����
{
    char aName;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex//����
{
    char vName;//�̸�
    int isVisit;//�湮����
    IncidentEdge* iHead; //���ᰣ��
    struct Vertex* next;//���� ����
}Vertex;

typedef struct//�׷���
{
    Vertex* vHead;//ù ����
}GraphType;

void init(GraphType* G)//�ʱ�ȭ
{
    G->vHead = NULL;
}

void makeVertex(GraphType* G, char vName)//���������
{
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));//����������
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;

    Vertex* p = G->vHead;//Ž���� ����

    if (p == NULL)//�� �׷����� �� �տ� �߰�
        G->vHead = v;
    else
    {
        while (p->next != NULL)//�׷��� �� ������ �̵�
            p = p->next;

        p->next = v;
    }
}

void makeIncidentEdge(Vertex* v, char aName)//���������
{
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));//���� �Ҵ�
    p->aName = aName;
    p->next = NULL;

    IncidentEdge* q = v->iHead;//Ž����
    if (q == NULL)
        v->iHead = p;

    else//�� ���� �߰�
    {
        while (q->next != NULL)
            q = q->next;

        q->next = p;
    }
}

Vertex* findVertex(GraphType* G, char vName)//���� ã��
{
    Vertex* v = G->vHead;
    while (v->vName != vName)//vname�� ��ġ�ϸ� ����
        v = v->next;

    return v;
}

void insertEdge(GraphType* G, char v1, char v2)//���� ����
{
    Vertex* v = findVertex(G, v1);//v1���� �̵�
    makeIncidentEdge(v, v2);//v1->v2

    v = findVertex(G, v2); //v2�� �̵�
    makeIncidentEdge(v, v1); // v2->v1
}

void rDFS(GraphType* G, char vName)
{
    Vertex* v = findVertex(G, vName);//vname�� ���� �������� �̵�
    IncidentEdge* p;//����

    if (v->isVisit == FALSE)//�湮���� ���� �����̸�
    {
        v->isVisit = TRUE; //�湮 ������ ����
        printf("[%c] ", v->vName);  //���  
    }

    for (p = v->iHead; p != NULL; p = p->next) //������ ���� ������
    {
        v = findVertex(G, p->aName);//���������ؼ� �� ����
        if (v->isVisit == FALSE)//�湮���� ���� �����̸�
            rDFS(G, v->vName);//�� �������� ����� Ž��
    }
}

void iDFS(GraphType* G, char vName)//�ݺ��� dfs
{
    Vertex* v = findVertex(G, vName);//���� ����
    IncidentEdge* p;//����

    StackType S;
    initStack(&S);
    push(&S, v->vName);//���ÿ� ���� ������ ����

    while (!isStackEmpty(&S))//���ÿ� ���̻� ���Ұ� ������ ����(���̻� ���� push ���Ҷ� ����)
    {
        v = findVertex(G, peek(&S));//���ÿ��� ���� ���Ҹ� v��
        if (v->isVisit == FALSE)//v�� �湮���� �ʾҴٸ�
        {
            v->isVisit = TRUE;//�湮 ǥ��
            printf("[%c] ", v->vName);//���
        }

        for (p = v->iHead; p != NULL; p = p->next)//p�� ����� ����Ž��
        {
            v = findVertex(G, p->aName);//p�� ����� ����
            if (v->isVisit == FALSE)//�湮���� ���� �����̸�
            {
                push(&S, v->vName);//���ÿ� �߰�
                break;
            }
        }
        if (p == NULL)//������ p�� ������ ã�ư��ٸ� pop
            pop(&S);
    }
}

void BFS(GraphType* G, char vName)//bfs �ʺ�켱Ž��
{
    Vertex* v = findVertex(G, vName);//Ž�� ���� ����
    IncidentEdge* p;//����

    QueueType Q;
    initQueue(&Q);

    v->isVisit = TRUE;//�������� �湮
    printf("[%c] ", v->vName);//���
    enqueue(&Q, v->vName);//�������� ť�� ����

    while (!isQueueEmpty(&Q))//ť�� ��������(�� ���� ���� �� ����)
    {
        v = findVertex(G, dequeue(&Q));//��� �湮�� ������ ����������
        for (p = v->iHead; p != NULL; p = p->next)//����� ���� Ž��
        {
            v = findVertex(G, p->aName);//������ ����� ����
            if (v->isVisit == FALSE)//�湮���� �ʾ�����
            {
                v->isVisit = TRUE;//�湮, ���, ť�� ����
                printf("[%c] ", v->vName);
                enqueue(&Q, v->vName);
            }
        }
    }
}

void print(GraphType* G)
{
    Vertex* p = G->vHead;
    IncidentEdge* q;

    for (; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for (q = p->iHead; q != NULL; q = q->next)
            printf("[%c] ", q->aName);
        printf("\n");
    }
}

int main()
{
    GraphType G;
    init(&G);

    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c');
    makeVertex(&G, 'd'); makeVertex(&G, 'e'); makeVertex(&G, 'f');
    makeVertex(&G, 'g');

    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'f');
    insertEdge(&G, 'b', 'c'); insertEdge(&G, 'b', 'g');
    insertEdge(&G, 'c', 'd');

    insertEdge(&G, 'd', 'e'); insertEdge(&G, 'd', 'g');
    insertEdge(&G, 'e', 'f'); insertEdge(&G, 'e', 'g');


    // insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c');

    // insertEdge(&G, 'a', 'd'); insertEdge(&G, 'b', 'c');

    // insertEdge(&G, 'b', 'e'); insertEdge(&G, 'd', 'e');

    print(&G); printf("\n");

    //printf("rDFS : "); rDFS(&G, 'e');

    printf("iDFS : "); iDFS(&G, 'f');

    //printf("BFS : "); BFS(&G, 'g');

    return 0;
}