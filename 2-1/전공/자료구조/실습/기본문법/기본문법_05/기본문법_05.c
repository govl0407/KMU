#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf_s("%d", &num);
    int A, B;
    A = 0;
    B = 0;
    for(int i=1; i <=num; i++)
    {
        if (i % 2 == 0) {
            A += i;
        }
        else {
            B += i;
        }
    }
    printf("%d\n%d", A, B);
    return 0;
}