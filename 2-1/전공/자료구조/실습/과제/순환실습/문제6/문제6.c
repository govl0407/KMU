#include<stdio.h>
#include<stdlib.h>

int euclid(int A, int B)
{
    int r = A % B;
    if (r == 0){
        return B;
    }
    else{
        euclid(B, r);
    }
}
int main() {
    int a, b;
    scanf_s("%d", &a);
    scanf_s("%d", &b);
    printf("%d",euclid(a, b));
    return 0;
}