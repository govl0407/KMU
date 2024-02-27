/**************
20203152 최정민 prim
**************/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}
struct node//연결리스트 노드
{
    int target = NULL;
    int weight = NULL;
    node* next = NULL;
};
void insert(node* n, int s, int w)//연결리스트 새 노드 연결
{
    if (n->target == NULL)//빈 노드일때
    {
        n->target = s;
        n->weight = w;
        n->next = NULL;
    }
    else//노드 뒤에 연결
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
int prim(int n, node* W[], int F[][2])
{
    int vnear;
    int nearest[2002];
    int distance[2002];
    int f_index = 0;
    for (int i = 2; i <= n; i++)//루트 노드에서 걸리는 거리 초기화
    {
        nearest[i] = 1;
        distance[i] = INT_MAX;
    }
    node* p = W[1];
    while (p != NULL)
    {
        distance[p->target] = p->weight;
        p = p->next;
    }
    for (int t = 0; t < n - 1; t++)
    {
        int min = INT_MAX;
        for (int i = 2; i <= n; i++)
        {
            if (distance[i] >= 0 && distance[i] < min)
            {
                min = distance[i];
                vnear = i;
            }
        }
        F[f_index][0] = vnear;//v -> vnear 엣지
        F[f_index][1] = nearest[vnear];
        f_index++;
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++)
        {
            int wiv = INT_MAX;//연결 안되면 거리 무한
            node* p = W[i];
            while (p != NULL && p->target != vnear)
                p = p->next;
            if (p != NULL)//연결된 target의 가중치
                wiv = p->weight;

            if (wiv < distance[i])
            {
                distance[i] = wiv;
                nearest[i] = vnear;
            }
        }
    }
    return f_index;//== n-1
}

void MST()
{
    node* arr[1001];//연결리스트
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)//연결리스트 만들기
    {
        int ind;
        cin >> ind;
        node* p = new node;
        p->target = NULL;
        p->next = NULL;
        int num;
        cin >> num;
        insert(p, ind, 0);
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
    int k = prim(N, arr, F);//prim 실행
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
        MST();
    return 0;
}