/***********************
20203152 최정민 최대값 구하기 10/10
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;
int M(int a, int b)
{
    int r;
    (a > b) ? r = a : r = b;
    return r;
}
int find_MAX(int arr[], int start, int end)
{
    int mid;
    if (start == end)
        return arr[start];
    else
    {
        mid = (start + end) / 2;
        return M(find_MAX(arr, start, mid), find_MAX(arr, mid + 1, end));
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int len;
        int k;
        cin >> len;
        int arr[100];
        for (int i = 0; i < len; i++)
        {
            int m;
            cin >> m;
            arr[i] = m;
        }
        cout << find_MAX(arr, 0, len - 1) << "\n";
    }
    return 0;
}
