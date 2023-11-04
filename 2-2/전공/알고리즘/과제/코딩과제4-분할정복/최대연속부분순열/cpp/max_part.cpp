/***********************
20203152 최정민 최대연속부분순열 10/11 시간초과 ? 어디서??
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;
int max(int a, int b, int c)
{
    int r;
    (a > b) ? r = a : r = b;
    (r > c) ? r = r : r = c;
    return r;
}
int max_part(int arr[], int start, int end)
{
    if (start == end)
        return arr[start];
    else
    {
        int mid = (start + end) / 2;
        int L = max_part(arr, start, mid);
        int R = max_part(arr, mid + 1, end);
        int mid_L = 0;//중간 + 왼쪽
        int mid_R = 0;//중간 + 오른쪽
        int tmp = 0;
        for (int i = mid + 1; i <= end; i++)
        {
            tmp += arr[i];
            if (tmp > mid_R)
                mid_R = tmp;
        }
        tmp = 0;
        for (int i = mid; i >= start; i--)
        {
            tmp += arr[i];
            if (tmp > mid_L)
                mid_L = tmp;
        }
        int M = mid_L + mid_R;
        return max(L, R, M);
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int len;
        cin >> len;
        int arr[100];
        for (int i = 0; i < len; i++)
        {
            int m;
            cin >> m;
            arr[i] = m;
        }
        int M = max_part(arr, 0, len - 1);
        if (M < 0)
            cout << 0;
        else
            cout << M;
        cout << "\n";
    }
    return 0;
}
