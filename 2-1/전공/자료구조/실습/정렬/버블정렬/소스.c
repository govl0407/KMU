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

void bubbleSort(int A[])
{
    printf("before Sort: ");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("<<<<<<<<<<<<<<<<bubbleSort<<<<<<<<<<<<<<<<<\n");

    for (int i = 0; i < N - 1; i++)
    {
        int temp, flag = FALSE;
        for (int j = 1; j <= N - 1; j++)
        {
            if (A[j - 1] > A[j])
            {
                flag = TRUE;
                SWAP(A[j - 1], A[j], temp);
            }
        }
        if (flag == FALSE)
            break;
        printPass(A, i);
    }
}

int main()
{
    int A[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++)
        A[i] = rand() % 100;
    bubbleSort(A);
}