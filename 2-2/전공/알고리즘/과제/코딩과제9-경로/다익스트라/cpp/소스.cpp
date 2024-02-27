/**************
20203152 최정민 djikstra
**************/
#include <iostream>
#include <climits>
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}
struct node
{
    int target = NULL;
    int weight = NULL;
    node* next = NULL;
};
void insert(node* n, int s, int w)
{
    if (n->target == NULL)
    {
        n->target = s;
        n->weight = w;
        n->next = NULL;
    }
    else
    {
        while (n->next != NULL)
        {
            n = n->next;
        }
        node* p = new node;
        p->target = s;
        p->weight = w;
        p->next = NULL;
        n->next = p;
    }
}
int calculate(int n, node* W[], int F[][2])
{
    int c = 0;
    int vnear;
    int touch[1001];
    int length[1001];
    for (int i = 2; i <= n; i++)//루트 노드에서 걸리는 거리 초기화
    {
        touch[i] = 1;
        length[i] = INT_MAX;
    }
    node* p = W[1];
    while (p != NULL)
    {
        length[p->target] = p->weight;
        p = p->next;
    }

    for (int t = 0; t < n - 1; t++)
    {
        int min = INT_MAX;
        for (int i = 2; i <= n; i++)
        {
            if (0 <= length[i] && length[i] < min)
            {
                min = length[i];
                vnear = i;
            }
        }
        F[c][0] = touch[vnear];
        F[c][1] = vnear;
        c++;
        for (int i = 2; i <= n; i++)
        {
            int wiv = INT_MAX;//연결 안되면 거리 무한
            node* p = W[vnear];
            while (p != NULL && p->target != i)
                p = p->next;
            if (p != NULL)//연결된 target의 가중치
                wiv = p->weight;
            if (length[vnear] + wiv < length[i])
            {
                length[i] = length[vnear] + wiv;
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
    }
    return c;
}

void dijkstra()
{
    node* arr[1001];
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int ind;
        cin >> ind;
        node* p = new node;
        p->target = NULL;
        p->next = NULL;
        int num;
        cin >> num;

        for (int j = 0; j < num; j++)
        {
            int n;
            cin >> n;
            int w;
            cin >> w;
            insert(p, n, w);
        }
        arr[ind] = p;
    }

    int F[1001][2];
    int sum = 0;
    int k = calculate(N, arr, F);
    for (int i = 0; i < k; i++)//F에 담긴 간선의 가중치 합
    {
        int t = F[i][0];
        node* p = arr[t];
        while (p != NULL && p->target != F[i][1])
            p = p->next;
        sum += p->weight;
    }
    cout << sum << "\n";
}

int main()
{
    int N;
    cin >> N;
    while (N--)
        dijkstra();
    return 0;
}