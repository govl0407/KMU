#include <stdio.h>
#include <stdlib.h>
void sumOfWeight(int g) {
    int cnt=0;
    for (int i=1; i <= 10; i++) {
        for (int j=1; j <= 10; j++) {
            for (int k=1; k <= 10; k++) {
                if (i * 2 + j * 3 + k * 5 == g) {
                    printf("%d %d %d\n", i, j, k);
                    cnt += 1;
                }
            }
        }
    }
    printf("%d",cnt);
}
int main()
{
    int g;
    scanf_s("%d", &g);
    sumOfWeight(g);
    return 0;
}