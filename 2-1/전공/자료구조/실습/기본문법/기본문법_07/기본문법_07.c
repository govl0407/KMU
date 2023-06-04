#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 
void makeArray(int A[]) {

}
void printArray(int A[]) {

}
void find_max(int A[]) {
    int MAX = A[0];
    for (int i = 1; i < N; i++)
    {
        printf("%d ", A[i]);
        if (A[i] > MAX) { MAX = A[i]; }
    }
    printf("\n%d", MAX);
}
int main()
{
    int A[N];
    int MAX = 0;
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        A[i] = rand() % 100 + 1;
    }
    print_max(A[]);

    return 0;
}