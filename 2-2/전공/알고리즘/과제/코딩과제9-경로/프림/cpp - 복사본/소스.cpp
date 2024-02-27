/**************
20203152 최정민 prim by struct
**************/
#include <iostream>
#include <climits>
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}
struct edge
{
    int weight = INT_MAX;
};
int prim(int n, edge W[][1001], int F[][2])
{
    int vnear;
    int nearest[2002];
    int distance[2002];
    int f_index = 0;
    for (int i = 2; i <= n; i++)//루트 노드에서 걸리는 거리 초기화
    {
        nearest[i] = 1;
        distance[i] = W[1][i].weight;
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
            if (W[i][vnear].weight < distance[i])
            {
                distance[i] = W[i][vnear].weight;
                nearest[i] = vnear;
            }
        }
    }
    return f_index;//== n-1
}

void MST()
{
    edge arr[1001][1001];
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)//그래프 만들기
    {
        int ind;
        cin >> ind;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int n;
            cin >> n;
            int w;
            cin >> w;
            edge e;
            e.weight = w;
            arr[ind][n] = e;
        }
    }

    int F[1001][2];

    int sum = 0;
    int k = prim(N, arr, F);//prim 실행
    for (int i = 0; i < k; i++)//F에 담긴 간선의 가중치 합
    {
        sum += arr[F[i][0]][F[i][1]].weight;
        
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