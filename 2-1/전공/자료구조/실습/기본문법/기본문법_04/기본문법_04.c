#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf_s("%d", &num);
    while (num > 0)
    {
        printf("%d\n", num % 10);
        num = num / 10;
    }
    return 0;
}