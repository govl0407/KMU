#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define FALSE 0
#define TRUE 1

#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))


void printPass(int A[], int i)
{
    printf(" %d Pass>> ", i);
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void insertionSort(int A[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap)
    {
        key = A[i];
        for (j = i - gap; j >= first && key < A[j]; j = j - gap)
            A[j + gap] = A[j];
        A[j + gap] = key;
    }
    printPass(A,gap);
}
void shellSort(int A[])
{
    int i, gap;
    for (gap = N / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++)
            insertionSort(A, i,N-1,gap);
    }
}

int main()
{
    int A[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        A[i] = rand() % 100;
    printPass(A, 0);
    shellSort(A);
}