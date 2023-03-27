#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score;
    scanf_s("%d", &score);
    if (score < 0 || score>100) { printf("wrong input/n"); }
    switch (score / 10)
    {
    case 10: 
        printf("A\n");
        break;
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    default:
        printf("D or F\n");
    }
    return 0;
}