#include <iostream> 
using namespace std;
void SelectionSort(int A[], int n)
{
    int compare_cnt = 0;
    int swap_cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int jMin = i;
        for (int j = i + 1; j < n; j++)
        {
            compare_cnt++;
            if (A[j] < A[jMin])
                jMin = j;
        }
        if (jMin != i) {
            swap_cnt++;
            int tmp = A[jMin];
            A[jMin] = A[i];
            A[i] = tmp;
            //swap(A[jMin], A[i]);
        }           
    }
    //for (int i = 0; i < n; i++)
    //{
    //    cout << A[i] << " ";
    //}
    cout << compare_cnt << " " << swap_cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[1000];
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            A[i] = a;
        }
        SelectionSort(A, n);
        cout << "\n";
    }
    return 0;
}