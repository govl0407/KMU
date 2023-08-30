#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void makeList(int list[])
{
    for (int i = 0; i < SIZE; i++)
        list[i] = rand() % 100 + 1;
}

void printList(int list[])
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
}

void merge(int list[], int sorted[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid)
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];

    for (l = left; l <= right; l++)
        list[l] = sorted[l];

}

void mergeSort(int list[], int sorted[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(list, sorted, left, mid);
        mergeSort(list, sorted, mid+1, right);
        merge(list, sorted, left, mid, right);
    }
}

int main()
{
    int list[SIZE], sorted[SIZE];
    srand(time(NULL));

    makeList(list);
    printList(list);

    mergeSort(list, sorted, 0, SIZE -1);

    printList(list);
}