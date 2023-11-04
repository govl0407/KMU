/***********************
20203152 √÷¡§πŒ hoare quicksort 10/14
***********************************/
#include<iostream>
#define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int hoare_swap = 0;
int hoare_compare = 0;
int lumoto_swap = 0;
int lumoto_compare = 0;
int partition_lumoto(int arr[], int low, int high)
{
    int pivot = arr[low];
    int j = low;
    for (int i = low + 1; i <= high; i++)
    {
        lumoto_compare++;
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[i], arr[j]);
            lumoto_swap++;
        }
    }
    int pivot_pos = j;
    swap(arr[pivot_pos], arr[low]);
    lumoto_swap++;
    return pivot_pos;
}
void lumoto(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int p = partition_lumoto(arr, low, high);
    lumoto(arr, low, p - 1);
    lumoto(arr, p + 1, high);
}
int partition_hoare(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do {
            i++;
            hoare_compare++;
        } while (arr[i] < pivot);
        do {
            j--;
            hoare_compare++;
        } while (arr[j] > pivot);
        if (i < j){ 
            swap(arr[i], arr[j]); 
            hoare_swap++;
        }
        else{ return j; }
    }
}
void hoare(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int p = partition_hoare(arr, low, high);
    hoare(arr, low, p);
    hoare(arr, p + 1, high);
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int len;
        cin >> len;
        int arr1[1000];
        int arr2[1000];
        for (int i = 0; i < len; i++)
        {
            int n;
            cin >> n;
            arr1[i] = n;
            arr2[i] = n;
        }

        hoare_swap = 0;
        hoare_compare = 0;
        lumoto_swap = 0;
        lumoto_compare = 0;
        lumoto(arr1, 0, len - 1);
        hoare(arr2, 0, len - 1);
        cout << hoare_swap << " " << lumoto_swap<<" ";
        cout << hoare_compare << " " << lumoto_compare << "\n";

    }
    return 0;
}
