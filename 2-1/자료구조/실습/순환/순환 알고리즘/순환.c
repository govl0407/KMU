#include <stdio.h>
#include <stdlib.h>
int iPower(int x, int n) {
    int i;
    int result = 1;
    for (i = 0; i < n; i++) {
        result = result * x;
    }
    return result;
}
int rPower(int x, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return rPower(x * x, n / 2);
    }
    else
        return x * rPower(x * x, (n - 1) / 2);
}
int count = 0;
int rFib(int n) {
    count++;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return rFib(n - 1) + rFib(n - 2);
}
int fib_iter(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int pp = 0;
    int p = 1;
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = p + pp;
        pp = p;
        p = result;
    }
    return result;
}

int main() {
    int a;
    scanf_s("%d", &a);
    printf("%d - %d", count, rFib(a));

}