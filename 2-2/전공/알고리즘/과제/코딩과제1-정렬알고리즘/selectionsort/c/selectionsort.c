#include <stdio.h>
#define MAX_SIZE 1000
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void selectionSort(int a[], int n);
int main()
{
    int numTestCases;
    scanf_s("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];
        scanf_s("%d", &num);
        for (int j = 0; j < num; j++)
            scanf_s("%d", &a[j]);
        selectionSort(a, num);
    }
    return 0;
}
/* Selection Sort 함수 */
void selectionSort(int A[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // selection sort 알고리즘 구현
    for (int i = 0; i < n - 1; i++)
    {
        int jMin = i; 
        int j = i;
        for (j = i + 1; j < n; j++) // select the min. of A[i+1], …, A[n-1] 
        {
            countCmpOps++;
            if (A[j] < A[jMin]) // 비교 연산
            {
                jMin = j;
            }
        }
        if (jMin != i)
        {
            countSwaps++;
            swap(A[jMin], A[j]);
        }
    }
            
    printf("%d %d ", countCmpOps, countSwaps);
    return 0;
}