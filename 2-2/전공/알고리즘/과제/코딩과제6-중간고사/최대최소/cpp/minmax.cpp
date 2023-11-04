/************
20203152 최정민 최대최소
************/
#include <iostream>
#define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int cnt = 0;
int MIN(int a, int b)
{
    int r;
    (a > b) ? r = b : r = a;
    return r;
}
int MAX(int a, int b)
{
    int r;
    (a < b) ? r = b : r = a;
    return r;
}
void find_min_max(int arr[], int low, int high, int& min, int& max)
{
    cnt++;
    int min1, min2, max1, max2;
    int mid = (high + low) / 2;
    if (high == low) {
        min = arr[low];
        max = arr[high];
    }
    else if (high - low == 1)
    {
        max = MAX(arr[low], arr[high]);
        min = MIN(arr[low], arr[high]);
    }
    else
    {
        int mid = (low + high) / 2;
        find_min_max(arr, low, mid, min1, max1);
        find_min_max(arr, mid + 1, high, min2, max2);
        max = MAX(max1, max2);
        min = MIN(min1, min2);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[100];
    while (n--)
    {
        int num;
        cin >> num;
        cnt = 0;
        for (int i = 0; i < num; i++)
        {
            int k;
            cin >> k;
            arr[i] = k;
        }
        int min, max;
        max = 0;
        min = 100;
        find_min_max(arr, 0, num - 1, min, max);
        cout << max << " " << min << " " << cnt << "\n";
    }
}
