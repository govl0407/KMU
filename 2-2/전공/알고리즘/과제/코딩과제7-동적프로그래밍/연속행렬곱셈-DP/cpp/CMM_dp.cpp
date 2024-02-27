/************
20203152 √÷¡§πŒ CMM_dp
3
4
20 2 30 12 8
2
2 3 4
25
4 5 4 4 3 8 10 7 9 8 3 10 11 4 9 11 7 6 5 3 4 5 5 6 3 3
************/
#include <iostream>
#include <climits>
#define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int MIN(int a, int b)
{
    int r;
    (a > b) ? r = b : r = a;
    return r;
}
int CMM(int n, const int d[], int P[101][101])
{
    int i, j, k, dig;
    int M[101][101];

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            M[i][j] = 0;

    for (i = 1; i <= n; i++)
        M[i][i] = 0;

    for (dig = 1; dig <= n - 1; dig++)
    {
        for (i = 1; i <= n - dig; i++)
        {
            j = i + dig;
            int min_num = INT_MAX;
            int key;
            for (k = i; k <= j - 1; k++)
            {
                int a = min_num;
                int b = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                min_num = MIN(a, b);
                if (min_num == b)
                    key = k;
            }
            M[i][j] = min_num;
            P[i][j] = key;
        }
    }
    return M[1][n];
}
void order(int i, int j, int P[101][101])
{
    if (i == j)
        cout << "M" << i;
    else
    {
        int k = P[i][j];
        cout << "(";
        order(i, k,P);
        order(k + 1, j,P);
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--)
    {
        int arr[101];
        int len;
        cin >> len;
        int i;

        for (i = 0; i <= len; i++)
        {
            cin >> arr[i];
        }
        int P[101][101];
        int result = CMM(len, arr, P);
        order(1, len, P);
        cout << "\n" << result << "\n";
    }
}
