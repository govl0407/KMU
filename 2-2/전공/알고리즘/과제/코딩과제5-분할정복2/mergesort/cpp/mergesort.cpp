/***********************
20203152 √÷¡§πŒ mergesort 10/14
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
void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[1000];
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
void mergesort(int arr[], int low, int high)
{
    int mid;
    if (low == high)
        return;
    mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);

}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int len;
        cin >> len;
        int arr[1000];
        for (int i = 0; i < len; i++)
        {
            int n;
            cin >> n;
            arr[i] = n;
        }
        cnt = 0;
        mergesort(arr, 0, len - 1);
        cout << cnt << "\n";
    }
    return 0;
}
