#include <iostream> 
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}

void random_num(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int s = rand() % 9 + 1;
        A[i] = s;
    }
}
void chk(int A[], int n)
{
    int ch = 0;
    int tmp[1000];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = A[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            ch = 1;
            cout << "\n" << "wrong\n";
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


void insertionSort(int A[], int n)
{
    int swap_cnt = 0;
    int compare_cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            compare_cnt++;
            if (A[j - 1] > A[j])
            {
                swap_cnt++;
                swap(A[j - 1], A[j]);
            }
            else { break; }
        }
    }

    cout << compare_cnt << " " << swap_cnt<<" ";
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
        insertionSort(A, n);
        cout <<"\n";
    }
    return 0;
}