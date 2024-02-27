/**************
20203152 최정민 djikstra 벡터 구조로 만들기

3
10
1 3 2 9 3 8 4 5
2 3 1 9 5 7 6 9
3 5 1 8 4 3 5 2 7 3 8 5
4 3 1 5 3 3 8 7
5 4 2 7 3 2 6 5 7 4
6 5 2 9 5 5 7 6 9 9 10 8
7 5 3 3 5 4 6 6 8 4 9 7
8 4 3 5 4 7 7 4 9 4
9 4 6 9 7 7 8 4 10 3
10 2 6 8 9 3
5
1 3 2 1 4 8 5 5
2 2 1 1 3 6
3 1 2 6
4 1 1 8
5 1 1 5
5
1 4 2 20 3 12 4 12 5 8
2 3 1 20 3 17 4 5
3 3 1 12 2 17 5 6
4 3 1 12 2 5 5 5
5 3 1 8 3 6 4 5



**************/
#include <iostream>
#include <climits>
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}
struct edge
{
    int weight = INT_MAX;
};

int calculate(int n, edge W[][1001], int F[][2])
{
    int c = 0;
    int vnear;
    int touch[2002];
    int length[2002];
    length[1] = 0;
    for (int i = 2; i <= n; i++)//루트 노드에서 걸리는 거리 초기화
    {
        touch[i] = 1;
        length[i] = W[1][i].weight;
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
            if (W[vnear][i].weight == INT_MAX)
                continue;
            if (length[vnear] + W[vnear][i].weight < length[i])
            {
                length[i] = length[vnear] + W[vnear][i].weight;
                touch[i] = vnear;
            }
        }
        length[vnear] = -1;
    }


    return c;
}

void dijkstra()
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
        arr[ind][ind].weight = 0;
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
    int k = calculate(N, arr, F);//prim 실행
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
        dijkstra();
    return 0;
}