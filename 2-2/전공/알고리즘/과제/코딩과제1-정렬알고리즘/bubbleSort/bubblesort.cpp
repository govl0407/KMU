#include <iostream> 
using namespace std;

#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void bubbleSort(A, m);
void bubbleSort_imp1(A, n);
void bubbleSort_imp2(A, n);
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int M;
        cin >> M;
        arr1[1000] = { 0 };
        arr2[1000] = { 0 };
        arr3[1000] = { 0 };
        A = { 0,0 };
        B = { 0,0 };
        C = { 0,0 };
        for (int i = 0; i < M; i++) {
            int n;
            cin >> n;
            arr1[i] = n;
            arr2[i] = n;
            arr3[i] = n;
        }
        bubbleSort(arr, M);
        bubbleSort_imp1(arr, M);
        bubbleSort_imp2(arr, M);
        cout << A[0] << " " << A[1] << " " << B[0] << " " << B[1] << " " << C[0] << " " << C[1]<<" "<<"\n";
    }
        
            
}
void bubbleSort(A, m)
{
    int compare_cnt = 0;
    int swap_cnt = 0;
    for (pass = 1; pass < m; pass++)
        for (i = 1; i <= m - pass; i++)
        {
            compare_cnt++;
            if (A[i - 1] > A[i]) 
            {
                swap_cnt++;
                swap(A[i - 1], A[i]);
            }
        }
    A[0] = compare_cnt;
    A[1] = swap_cnt;
}

void bubbleSort_imp1(A, n)
{
    int compare_cnt = 0;
    int swap_cnt = 0;

    for (pass = 1; pass < n; pass++) 
    {
        bool swapped = false; 
        for (i = 1; i <= n - pass; i++)
            compare_cnt++;
            if (a[i - 1] > a[i]) 
            {
                swap(a[i - 1], a[i]);
                swap_cnt++;
                swapped = true;
            }
        if (swapped == false) 
            break;
    }
    B[0] = compare_cnt;
    B[1] = swap_cnt;
}
    

void bubbleSort_imp2(A, n)
{
    int swap_cnt = 0;
    int compare_cnt = 0;
    int lastSwappedPos = n;
    for (lastSwappedPos > 0)
    {
        int swappedPos = 0;
        for (i = 1; i < lastSwappedPos; i++)
            compare_cnt++;
            if (a[i - 1] > a[i])
            {
                swap_cnt++;
                swap(a[i - 1], a[i]);
                swappedPos = i;
            }
        lastSwappedPos = swappedPos;
    }
    C[0] = compare_cnt;
    c[1] = swap_cnt;
}