#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y)
{
    printf("x : %d, y: %d\n", x, y);

    int t = x;
    x = y;
    y = t;
    printf("x : %d, y: %d\n", x, y);


}

void swap2(int *x, int *y)
{
    printf("x : %d, y: %d\n", *x, *y);

    int t = *x;
    *x = *y;
    *y = t;
    printf("x : %d, y: %d\n", *x, *y);


}


int main()
{
    int a, b;
    scanf_s("%d %d", &a, &b);

    swap(a, b);
    printf("a : %d, b: %d\n", a, b);

    swap2(&a, &b);
    printf("a : %d, b: %d\n", a, b);

    return 0;
}