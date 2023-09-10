#include <iostream> 
#include <list>
using namespace std;
int n = 8;
int A[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
void ShellSort(int A[])
{
    int shrinkRatio = 2;
    int gap = n / shrinkRatio;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = A[i];
            int j;
            for ( j = i; (j >= gap) && (A[j - gap] > tmp); j -= gap)
                A[j] = A[j - gap];
            A[j] = tmp;
        }
        gap /= shrinkRatio;
    }
}
int main()
{
    ShellSort(A);
    for (int i = 0; i < 8; i++)
    {
        cout << (A[i])<< " ";
    }
}