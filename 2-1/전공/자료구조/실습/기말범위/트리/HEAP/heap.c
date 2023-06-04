#include<stdlib.h>
#include<stdio.h>

//////////////////init
#define N 100

typedef int element;

typedef struct
{
    element heap[N];
    int heapSize;
}HeapType;

void init(HeapType* H)
{
    H->heapSize = 0;

}
/////////////////////up- down heap
void upHeap(HeapType* H)
{
    int i = H->heapSize;
    element key = H->heap[i];
    while ((i != 1) && (key > H->heap[i / 2]))
    {
        H->heap[i] = H->heap[i / 2];
        i /= 2;
    }
    H->heap[i] = key;
}
void downHeap(HeapType* H)
{
    element key = H->heap[1];
    int parent = 1, child = 2;
    while (child <= H->heapSize)
    {
        if ((child < H->heapSize) && (H->heap[child + 1] > H->heap[child]))
            child++;

        if (key >= H->heap[child])
            break;
        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }
    H->heap[parent] = key;
}
/////////////////print
void printHeap(HeapType* H)
{
    for (int i = 1; i <= H->heapSize; i++)
        printf("%d ", H->heap[i]);
    printf("\n");
}


//////////////////////insert
void insertItem(HeapType* H, element key)
{
    H->heapSize++;
    H->heap[H->heapSize] = key;
    upHeap(H);
}
////////////////////////delete
element deleteItem(HeapType* H)
{
    element key = H->heap[1];
    H->heap[1] = H->heap[H->heapSize];
    H->heapSize--;
    downHeap(H);
    return key;
}
/////////////////////////heapsort
void heapSort(HeapType* H)
{
    int n = H->heapSize;
    int A[N];

    for (int i = n - 1; i >= 0; i--)
        A[i] = deleteItem(H);

    for (int i = 0; i < n; i++)
        printf("(%d) ", A[i]);
    printf("\n");
}

void inPlaceHeapSort(HeapType* HT)//수정필요
{
    int n = HT->heapSize;
    int key;
    for (int i = 0; i < n; i++)
    {
        key = deleteItem(HT);
        HT->heap[HT->heapSize + 1] = key;
    }
}

int main()
{
    HeapType H;
    init(&H);
    insertItem(&H, 9);
    insertItem(&H, 7);
    insertItem(&H, 6);
    insertItem(&H, 5);
    insertItem(&H, 4);
    insertItem(&H, 3);
    insertItem(&H, 2);
    insertItem(&H, 2);
    insertItem(&H, 1);
    insertItem(&H, 3);
    //heapSort(&H);
    //printHeap(&H);
    //insertItem(&H, 7); printHeap(&H);

    //deleteItem(&H); printHeap(&H);
    //inPlaceHeapSort(&H);
    //printHeap(&H);

}

