/************
20203152 √÷¡§πŒ CMM_REC
3
4 20 2 30 12 8
2 2 3 4
10 5 8 2 9 4 10 6 1 11 3 7
************/
#include <iostream>
#include <climits>
#define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int cnt = 0;
int MIN(int a, int b)
{
    int r;
    (a > b) ? r = b : r = a;
    return r;
}

int CMM(int arr[], int i, int j)
{
    int min_num = INT_MAX;
    if (i == j)
    {
        return 0;
    }
    else
    {
        for (int k = i; k < j; ++k)
        {
            int temp = CMM(arr, i, k) + CMM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            min_num = MIN(temp, min_num);
        }
        return min_num;
    }
}
int main() {
    int n;
    cin >> n;
    while (n--)
    {
        int arr[21];
        int len;
        cin >> len;
        int i;
        
        for (i = 0; i <= len;i++)
        {
            cin >> arr[i];
        }
        cout << CMM(arr, 1, len)<< "\n";
    }
}
