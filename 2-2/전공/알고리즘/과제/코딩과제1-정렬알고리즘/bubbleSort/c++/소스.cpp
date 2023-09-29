#include <iostream> 
using namespace std;

#define swap(a, b) {int t = a; a = b; b = t;}

void bubbleSort(int A[], int m);
void bubbleSort_imp1(int A[], int n);
void bubbleSort_imp2(int A[], int n);
void random_num(int A[],int B[],int C[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int s = rand() % 9+1;
        A[i] = s;
        B[i] = s;
        C[i] = s;
    }
}
void chk(int A[], int n, int a)
{
    int ch = 0;
    int tmp[1000];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = A[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        if (A[i] > A[i + 1])
        {
            ch = 1;
            cout <<"\n" << a << "wrong\n";
            break;
        }
    }
    if (ch) {
        for (int i = 0; i < n; i++)
        {
            cout << tmp[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
    }
}


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
        //random_num(arr1,arr2,arr3, M);
        bubbleSort(arr1, M);
        bubbleSort_imp1(arr2, M);
        bubbleSort_imp2(arr3, M);
        
        cout << "\n";
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
    //chk(arr, m,1);
    cout << compare_cnt << " " << swap_cnt << " ";
}
void bubbleSort_imp1(int arr[], int n)// 3 3 2 일 경우 정렬 안함
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
        }
        if (swapped == false)
            break;
    }
    cout << compare_cnt << " " << swap_cnt << " ";

    //chk(arr, n,2);
}


void bubbleSort_imp2(int arr[], int n)
{
    int swap_cnt = 0;
    int compare_cnt = 0;
    int lastSwappedPos = n;
    for (; lastSwappedPos > 0;)
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
    cout << compare_cnt << " " << swap_cnt << " ";

    //chk(arr, n,3);
}