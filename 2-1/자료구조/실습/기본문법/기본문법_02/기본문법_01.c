#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score;
    scanf_s("%d", &score);
    if (score < 0 || score>100) { printf("wrong input/n"); }
    else
    {
        if (score >= 90 && score <= 100)
            printf("A\n");
        else if (score >= 70 && score < 90)
            printf("B\n");
        else if (score >= 60 && score < 70)
            printf("C\n");
        else
            printf("D or F\n");
    }
    return 0;
}