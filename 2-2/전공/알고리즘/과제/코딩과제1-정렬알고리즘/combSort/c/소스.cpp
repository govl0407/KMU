#include <iostream> 
using namespace std;

#define swap(a, b) {int t = a; a = b; b = t;}


void random_num(int A[],int n)
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
void combSort(int A[], int n)
{
    int swap_cnt = 0;
    int compare_cnt = 0;
    int gap = n;
    float shrink = 1.3;
    bool sorted = false;

    while (sorted == false)
    {
        gap = int(gap / shrink);
        if (gap <= 1)
        {
            gap = 1;
            sorted = true;
        }
        int i = 0;
        while (i + gap < n)
        {
            compare_cnt++;
            if (A[i] > A[i + gap])
            {
                swap_cnt++;
                swap(A[i], A[i + gap]);
                sorted = false;
            }
            i++;
        }
    }
    cout << compare_cnt << " " << swap_cnt<< " ";

    //chk(A, n);//
}

int main()
{
    int N;
    cin >> N;
    //int N = 1000;//
    while (N--)
    {
        int M;
        cin >> M;
        //int M = 100;//
        int arr[1000] = { 0 };

        
        for (int i = 0; i < M; i++) {
            int n;
            cin >> n;
            arr[i] = n;
        }
        
        //random_num(arr, M);//
        combSort(arr, M);
        cout << "\n";
    }

}
