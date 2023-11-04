/***********************
20203152 ÃÖÁ¤¹Î BINARY_SEARCH 10/10
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;
int BS(int arr[], int start ,int end, int k)
{
    if (start > end)
    {
        return -1;
    }
    else
    {
        int mid = (end + start) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            return BS(arr, mid + 1, end, k);
        else if (arr[mid] > k)
            return BS(arr, start, mid - 1, k);
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
        cin >> len >> k;
        int arr[100];
        for (int i = 0; i < len; i++)
        {
            int m;
            cin >> m;
            arr[i] = m;
        }
        cout << BS(arr, 0, len-1, k) << "\n";
    }
    return 0;
}
