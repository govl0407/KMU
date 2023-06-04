#include <stdio.h>
#include <stdlib.h>

typedef struct account
{
    int id;
    int money;
    
}account;

void add(account *T, int amount)
{
    T->money += amount;
    printf("%d : %d\n", T->id, T->money);
}

int main()
{
    struct account a;


    scanf_s("%d %d", &a.id, &a.money);
    printf("%d: %d\n", a.id, a.money);
    int amount;
    scanf_s("%d", &amount);
    add(&a, amount);
    return 0;
}