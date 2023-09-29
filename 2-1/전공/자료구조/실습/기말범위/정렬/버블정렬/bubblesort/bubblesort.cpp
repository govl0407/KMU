#include <iostream> 
using namespace std;

#define swap(a, b) {int t = a; a = b; b = t;}

void bubbleSort(int A[], int m);
void bubbleSort_imp1(int A[], int n);
void bubbleSort_imp2(int A[], int n);

int a[] = { 0,0 };
int b[] = { 0,0 };
int c[] = { 0,0 };
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int M;
        cin >> M;
        int arr1[1000] = { 0 };
        int arr2[1000] = { 0 };
        int arr3[1000] = { 0 };
        for (int i = 0; i < M; i++) {
            int n;
            cin >> n;
            arr1[i] = n;
            arr2[i] = n;
            arr3[i] = n;
        }
        bubbleSort(arr1, M);
        bubbleSort_imp1(arr2, M);
        bubbleSort_imp2(arr3, M);
        cout << a[0] << " " << a[1] << " " << b[0] << " " << b[1] << " " << c[0] << " " << c[1]<<"\n";
    }


}
void bubbleSort(int arr[], int m)
{
    int compare_cnt = 0;
    int swap_cnt = 0;
    for (int pass = 1; pass < m; pass++)
    {
        for (int i = 1; i <= m - pass; i++)
        {
            compare_cnt++;
            if (arr[i - 1] > arr[i])
            {
                swap_cnt++;
                swap(arr[i - 1], arr[i]);
            }
        }
    }
    a[0] = compare_cnt;
    a[1] = swap_cnt;
}

void bubbleSort_imp1(int arr[], int n)
{
    int compare_cnt = 0;
    int swap_cnt = 0;

    for (int pass = 1; pass < n; pass++)
    {
        bool swapped = false;
        for (int i = 1; i <= n - pass; i++)
        {
            compare_cnt++;
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swap_cnt++;
                swapped = true;
            }
            if (swapped == false)
                break;
        }
    }
    b[0] = compare_cnt;
    b[1] = swap_cnt;
}


void bubbleSort_imp2(int arr[], int n)
{
    int swap_cnt = 0;
    int compare_cnt = 0;
    int lastSwappedPos = n;
    for (;lastSwappedPos > 0;)
    {
        int swappedPos = 0;
        for (int i = 1; i < lastSwappedPos; i++)
        {
            compare_cnt++;
            if (arr[i - 1] > arr[i])
            {
                swap_cnt++;
                swap(arr[i - 1], arr[i]);
                swappedPos = i;
            }
        }
        lastSwappedPos = swappedPos;
    }
    c[0] = compare_cnt;
    c[1] = swap_cnt;
}