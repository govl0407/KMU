/***********************
20203152 √÷¡§πŒ merge_iterative 10/14
***********************************/
#include<iostream>
#define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int cnt = 0;

int MIN(int a, int b)
{
    int r;
    (a > b) ? r = b : r = a;
    return r;
}
void merge(int* arr, int low, int mid, int high)
{
    int i, j, k;
    int tmp[100];
    for (i = low; i <= high; i++)
        tmp[i] = arr[i];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        cnt++;
        if (tmp[i] <= tmp[j])
            arr[k++] = tmp[i++];
        else
            arr[k++] = tmp[j++];
    }
    while (i <= mid)
        arr[k++] = tmp[i++];
    while (j <= high)
        arr[k++] = tmp[j++];
}
void mergesort(int* arr, int n)
{
    int size = 1;
    while (size < n)
    {
        for (int i = 0; i < n; i += 2 * size)
        {
            int low = i;
            int mid = low + size - 1;
            int high = MIN(i + 2 * size - 1, n - 1);
            if (mid >= n - 1)
                break;
            merge(arr, low, mid, high);
        }
        size *= 2;
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
            int n;
            cin >> n;
            arr[i] = n;
        }
        cnt = 0;
        mergesort(arr, len);
        cout << cnt << "\n";
    }
    return 0;
}
