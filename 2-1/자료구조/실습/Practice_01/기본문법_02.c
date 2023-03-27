#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score;
    scanf_s("Score: %d", &score);
    printf("%d", score);
    if (100 >= score >= 90) {
        printf("Your grade is A");
    }
    else if (90 > score >= 80) {
        printf("Your grade is B");
    }
    else if (80 > score >= 70) {
        printf("Your grade is D");
    }
    else if (70 > score >= 60) {
        printf("Your grade is D or F");
    }
    else {
        printf("Wrong input");
    }

    return 0;
}