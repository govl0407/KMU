#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n == 1) printf("Disk %d: Move from %c to %c.\n", n, from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
        printf("Disk %d: Move from %c to %c.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}
int main(void)
{
    int a;
    scanf_s("%d", &a);
    hanoi_tower(a, 'A', 'B', 'C');
    printf("end");
    return 0;
}