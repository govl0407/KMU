#include <stdio.h>
#include <stdlib.h>
int slicing(N)
{
    if (N / 10 == 0) {
        printf("%d\n", N);
    }
    else {
        printf("%d\n", N % 10);
        slicing(N / 10);
    }
}
int main()
{
    int n;
    scanf_s("%d", &n);
    slicing(n);
    return 0;
}