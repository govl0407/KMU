/**************
20203152 최정민 bfs_cc
**************/
#include <iostream>
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
        return a;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
struct stack
{
    int data[1000][2];
    int top = -1;
};
void pop(stack& s)
{
    if (s.top >= 0)
    {
        s.top--;
        //return s.data[s.top + 1];
    }
    return;

}
void push(stack& s, int a, int b)
{
    s.top++;
    s.data[s.top][0] = a;
    s.data[s.top][1] = b;

}
int empty(stack& s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

struct node
{
    int data = NULL;
    node* next = NULL;
    int traversed = 0;
};
void insert(node* n, int s)
{
    if (n->data == NULL)
    {
        n->data = s;
        n->next = NULL;
    }
    else
    {
        while (n->next != NULL)
        {
            n = n->next;
        }
        node* p = new node;
        p->data = s;
        p->next = NULL;
        n->next = p;
    }
}



struct queue
{
    int data[1000];
    int head = 0;
    int tail = 0;
};
int emptyq(queue& q)
{
    if (q.head == q.tail % 1000)
        return 1;
    else
        return 0;
}
int popq(queue& q)
{
    if (emptyq(q))
        return -1;
    else
    {
        int k = q.data[q.head];
        q.head++;
        q.head %= 1000;
        return k;
    }
}

void pushq(queue& q, int n)
{
    q.tail %= 1000;
    q.data[q.tail++] = n;
}
void bfs(queue& q, int visit[], node* arr[], int i)//bfs
{
    pushq(q, i);
    do
    {
        int k = popq(q);
        if (k == 1)
            continue;
        node* p = arr[k];
        if (visit[k] == -1)
            visit[k] = i;
        while (p != NULL)
        {
            int t = p->data;
            if (visit[t] == -1)
            {
                pushq(q, t);
                visit[t] = i;
            }
            p = p->next;
        }
    } while (!emptyq(q));
}



int articul[1000];
void bicompDFS(node* arr[], int v, int dfn, stack edgestack, int dfsnumber[], int back[], int articul[])
{
    dfn++;
    dfsnumber[v] = dfn;
    back[v] = dfn;
    node* ptr = arr[v];
    while (ptr != NULL)
    {
        int w = ptr->data;
        if (dfsnumber[w] < dfsnumber[v])
            push(edgestack, v, w);

        if (dfsnumber[w] == 0)
        {
            bicompDFS(arr, w, dfn, edgestack, dfsnumber, back, articul);
            if (back[w] >= dfsnumber[v])//이때 articulation
            {
                int t = edgestack.top;
                int k[2];
                k[0] = edgestack.data[t][0];
                k[1] = edgestack.data[t][1];
                articul[v] = 1;
                pop(edgestack);
                while (k[0] == v && k[1] == w)
                {
                    t = edgestack.top;
                    k[0] = edgestack.data[t][0];
                    k[1] = edgestack.data[t][1];
                    pop(edgestack);
                }

            }
            else
                back[v] = min(back[v], back[w]);

        }
        else
            back[v] = min(dfsnumber[w], back[v]);
        ptr = ptr->next;
    }

}
int chk(queue q,int t)
{
    for (int i = q.head; i < q.tail; i++)
    {
        if (q.data[i] == t)
            return 0;
    }
    return 1;
}
void bicnt(node* arr[], int visit3[], int root)
{

    node* p = arr[root];
    queue q;
    int i = 1;
    queue artq;
    int arm = p->data;
    pushq(q, arr[arm]->data);
    do
    {
        int k = popq(q);
        node* p = arr[k];
        if (visit3[k] == -1&&k!=root)
            visit3[k] = i;
        if (articul[k] != 0 && chk(artq, k))
        {
            pushq(artq, k);
        }
        while (p != NULL)
        {
            int t = p->data;
            
            if (visit3[t] == -1&&k!=root)
            {
                pushq(q, t);
                visit3[t] = i;
            }
            if (articul[t] != 0 &&chk(artq,t))
            {
                pushq(artq, t);
            }
            p = p->next;
        }
    } while (!emptyq(q));

    if(!emptyq(artq))
        bicnt(arr, visit3, popq(artq));

}
void bc()
{
    node* arr[301];
    int N;
    cin >> N;
    //연결리스트 생성
    for (int i = 1; i < N + 1; i++)
    {
        int ind;
        cin >> ind;
        node* p = new node;
        p->data = NULL;
        p->next = NULL;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int n;
            cin >> n;
            insert(p, n);
        }
        arr[ind] = p;


    }

    int dfsnumber[100];
    int back[100];
    stack edgestack;
    int dfn = 0;
    for (int i = 0; i < N + 1; i++)
    {
        articul[i] = 0;
        dfsnumber[i] = 0;
    }
    //articulation point 찾기
    bicompDFS(arr, 1, dfn, edgestack, dfsnumber, back, articul);
    int visit1[101];
    for (int i = 0; i < N + 1; i++)
        visit1[i] = -1;
    queue q;
    bfs(q, visit1, arr, 2);
    //루트가 articulation point 인지 검사
    for (int i = 2; i < N + 1; i++)
    {
        if (visit1[i] == -1)
        {
            articul[1] = 1;
            break;
        }
        if (i == N)
            articul[1] = 0;
    }
    //루트부터 bfs 돌려서 connected 갯수 세기
    //가다가 만난 articulation을 큐에 넣고 다시 bfs 시작, 이미 방문한 articulation이면 그 팔은 카운트 x
    //반복
    
    int visit3[101];
    for (int i = 0; i < 102; i++)
        visit3[i] = -1;
    bicnt(arr, visit3, 1);

    //articulation point 출력
    int cnt2 = 0;
    for (int i = 0; i < N + 1; i++)
    {
        if (articul[i] != 0)
            cnt2++;
    }

    cout << cnt2 << " ";
    for (int i = 0; i < N + 1; i++)
    {
        if (articul[i] != 0)
            cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    int N;
    cin >> N;
    while (N--)
        bc();
    return 0;
}