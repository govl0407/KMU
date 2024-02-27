/**************************
20203152 ������ kruskal ��Ÿ�� ����
***************************/
#include <iostream>
#include <climits>
using namespace std;
void swap(int a[], int b[])
{
    for (int i = 0; i < 4; i++)
    {
        int t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
}
int partition(int arr[][4], int low, int high) {
    int pivot = arr[high][2];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j][2] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[][4], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void init(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
        arr[i] = i;
}
int find(int arr[], int i)
{
    while (arr[i] != i)
        i = arr[i];
    return i;
}
void unite(int arr[], int p, int q)
{
    int i = find(arr, p);
    int j = find(arr, q);
    if (i != j)
        arr[i] = j;

}

int kruskal(int n, int arr[][4], int ind)
{
    int sum = 0;
    int uni[5000000];
    init(uni, n);
    int f_index = 0;
    while (f_index != n - 1)
    {
        for (int i = 0; i < ind; i++)
        {
            if (arr[i][3] == 1)//�湮�� �����̸� ��ŵ
                continue;
            int a, b;//�Ÿ��� �ּ��� ���� ����
            a = arr[i][0];
            b = arr[i][1];
            int p = find(uni, a);
            int q = find(uni, b);
            if (p != q)
            {
                unite(uni, p, q);//union
                arr[i][3] = 1;//�湮�� ������ ǥ��
                f_index++;//����� ���� �� ++
                sum += arr[i][2];//�Ÿ��� �� ����
                break;
            }
        }
    }
    return sum;
}

void MST()
{
    int arr[5000000][4];//����Ʈ [0] to [1], weight = [2], visit [3]
    int N;
    cin >> N;

    int ind = 0;
    for (int i = 0; i < N; i++)
    {
        int from, to, w;
        cin >> from;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> to >> w;
            w++;
            arr[ind][0] = from;
            arr[ind][1] = to;
            arr[ind][2] = w;
            arr[ind][3] = 0;
            ind++;
        }
    }
    ind--;
    quickSort(arr, 0, ind);//�������� ����

    int k = kruskal(N, arr, ind);//kruskal ����

    cout << k << "\n";
}

int main()
{
    int N;
    cin >> N;
    while (N--)
        MST();
    return 0;
}