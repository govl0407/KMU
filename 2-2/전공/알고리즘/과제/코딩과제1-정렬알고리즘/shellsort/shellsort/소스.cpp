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

void shellSort(int A[], int n)
{
    int swap_cnt = 0;
    int compare_cnt = 0;
    int shrinkratio = 2;
    int gap = n / shrinkratio;
    while(gap>0)
    {
        for (int i = gap; i <n; i++)
        {
            int tmp = A[i];
            int j=i;
            while(j >= gap)
            {
                compare_cnt++;
                if (A[j - gap] > tmp)
                {   
                    swap_cnt++;
                    A[j] = A[j - gap];
                    j -= gap;
                }
                else { break; }
            }
            A[j] = tmp;

        }
        gap /= shrinkratio;
    } 

    cout << compare_cnt << " " << swap_cnt<<" ";
    //chk(A, n);//
}
int main()
{
    int t;
    cin >> t;
    //int t = 1000;//

    while (t--)
    {
        int n;
        cin >> n;
        //int n = 10;//
        int A[1000];
        //random_num(A, n);//
        
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            A[i] = a;
        }
        shellSort(A, n);
        cout << "\n";
    }
    return 0;
}