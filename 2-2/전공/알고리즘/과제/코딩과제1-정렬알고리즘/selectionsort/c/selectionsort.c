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
/* Selection Sort �Լ� */
void selectionSort(int A[], int n)
{
    int countCmpOps = 0; // �� ������ ���� Ƚ��
    int countSwaps = 0; // swap �Լ� ���� Ƚ��
    // selection sort �˰��� ����
    for (int i = 0; i < n - 1; i++)
    {
        int jMin = i; 
        int j = i;
        for (j = i + 1; j < n; j++) // select the min. of A[i+1], ��, A[n-1] 
        {
            countCmpOps++;
            if (A[j] < A[jMin]) // �� ����
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