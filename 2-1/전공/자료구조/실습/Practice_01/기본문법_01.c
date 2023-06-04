#include <stdio.h>
#include <stdlib.h>

int main()
{
    int price, cnt, money, total;
    scanf_s("%d %d %d", &price, &cnt, &money);
    total = price * cnt;
    if (total > money){
        printf("not enough money");
    }
    else {
        printf("change is $%d", money - total);
    }

    return 0;
}
