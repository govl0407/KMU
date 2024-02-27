/************
20203152 √÷¡§πŒ CMM_mem
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
int M[101][101] = { 0 };
int MIN(int a, int b)
{
    int r;
    (a > b) ? r = b : r = a;
    return r;
}

int CMM(int arr[], int i, int j)
{
    if (M[i][j] != 0)
        return M[i][j];
    else
    {
        int min_num = INT_MAX;
        if (i == j)
            return 0;
        else
        {
            for (int k = i; k < j; ++k)
            {
                int temp = CMM(arr, i, k) + CMM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
                min_num = MIN(temp, min_num);
            }
            M[i][j] = min_num;
            return min_num;
        }

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
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                M[i][j] = 0;
        cout << CMM(arr, 1, len) << "\n";
    }
}
