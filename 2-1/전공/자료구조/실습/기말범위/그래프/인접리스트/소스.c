#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0

typedef int element;
/* --------------------------------스택 */
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

/* --------------------------------큐 */
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

typedef struct IncidentEdge//간선
{
    char aName;
    struct IncidentEdge* next;
}IncidentEdge;

typedef struct Vertex//정점
{
    char vName;//이름
    int isVisit;//방문여부
    IncidentEdge* iHead; //연결간선
    struct Vertex* next;//다음 정점
}Vertex;

typedef struct//그래프
{
    Vertex* vHead;//첫 정점
}GraphType;

void init(GraphType* G)//초기화
{
    G->vHead = NULL;
}

void makeVertex(GraphType* G, char vName)//정점만들기
{
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));//동저갛ㄹ당
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;

    Vertex* p = G->vHead;//탐색용 정점

    if (p == NULL)//빈 그래프면 맨 앞에 추가
        G->vHead = v;
    else
    {
        while (p->next != NULL)//그래프 맨 끝으로 이동
            p = p->next;

        p->next = v;
    }
}

void makeIncidentEdge(Vertex* v, char aName)//간선만들기
{
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));//동적 할당
    p->aName = aName;
    p->next = NULL;

    IncidentEdge* q = v->iHead;//탐색용
    if (q == NULL)
        v->iHead = p;

    else//맨 끝에 추가
    {
        while (q->next != NULL)
            q = q->next;

        q->next = p;
    }
}

Vertex* findVertex(GraphType* G, char vName)//정점 찾기
{
    Vertex* v = G->vHead;
    while (v->vName != vName)//vname이 일치하면 리턴
        v = v->next;

    return v;
}

void insertEdge(GraphType* G, char v1, char v2)//간선 삽입
{
    Vertex* v = findVertex(G, v1);//v1으로 이동
    makeIncidentEdge(v, v2);//v1->v2

    v = findVertex(G, v2); //v2로 이동
    makeIncidentEdge(v, v1); // v2->v1
}

void rDFS(GraphType* G, char vName)
{
    Vertex* v = findVertex(G, vName);//vname을 가진 정점으로 이동
    IncidentEdge* p;//간선

    if (v->isVisit == FALSE)//방문되지 않은 정점이면
    {
        v->isVisit = TRUE; //방문 됨으로 수정
        printf("[%c] ", v->vName);  //출력  
    }

    for (p = v->iHead; p != NULL; p = p->next) //간선을 따라 끝까지
    {
        v = findVertex(G, p->aName);//간선을통해서 간 정점
        if (v->isVisit == FALSE)//방문되지 않은 정점이면
            rDFS(G, v->vName);//그 정점에서 재귀적 탐색
    }
}

void iDFS(GraphType* G, char vName)//반복적 dfs
{
    Vertex* v = findVertex(G, vName);//시작 정점
    IncidentEdge* p;//간선

    StackType S;
    initStack(&S);
    push(&S, v->vName);//스택에 시작 정점을 넣음

    while (!isStackEmpty(&S))//스택에 더이상 원소가 없을때 까지(더이상 새로 push 안할때 까지)
    {
        v = findVertex(G, peek(&S));//스택에서 꺼낸 원소를 v로
        if (v->isVisit == FALSE)//v가 방문하지 않았다면
        {
            v->isVisit = TRUE;//방문 표시
            printf("[%c] ", v->vName);//출력
        }

        for (p = v->iHead; p != NULL; p = p->next)//p에 연결된 간선탐색
        {
            v = findVertex(G, p->aName);//p에 연결된 정점
            if (v->isVisit == FALSE)//방문하지 않은 정점이면
            {
                push(&S, v->vName);//스택에 추가
                break;
            }
        }
        if (p == NULL)//끝까지 p의 끝까지 찾아갔다면 pop
            pop(&S);
    }
}

void BFS(GraphType* G, char vName)//bfs 너비우선탐색
{
    Vertex* v = findVertex(G, vName);//탐색 시작 정점
    IncidentEdge* p;//간선

    QueueType Q;
    initQueue(&Q);

    v->isVisit = TRUE;//시작점을 방문
    printf("[%c] ", v->vName);//출력
    enqueue(&Q, v->vName);//시작점을 큐에 넣음

    while (!isQueueEmpty(&Q))//큐가 빌때까지(더 넣지 않을 때 까지)
    {
        v = findVertex(G, dequeue(&Q));//방금 방문한 정점을 시작점으로
        for (p = v->iHead; p != NULL; p = p->next)//연결된 간선 탐색
        {
            v = findVertex(G, p->aName);//간선에 연결된 정점
            if (v->isVisit == FALSE)//방문하지 않았으면
            {
                v->isVisit = TRUE;//방문, 출력, 큐에 넣음
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