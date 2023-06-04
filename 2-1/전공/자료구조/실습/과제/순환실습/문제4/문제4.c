#include<stdio.h>
#include<stdlib.h>

int Max(int *arr,int N)
{
    if(N == 0){
        return arr[0];
    }
    else {
        int k = Max(arr, N - 1);
        if (k >= arr[N]) {
            return k;
        }
        else {
            return arr[N];
        }
    }
}

int main()
{

    int nums[20];
    int leng;
    scanf_s("%d", &leng);
    for (int i = 0; i < leng; i++) {
        scanf_s("%d", &nums[i]);
    }

    printf("%d", Max(nums, leng));
    return 0;
}