/**************
20203152 최정민 recursive dfs_cc
**************/
#include <iostream>
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


struct node
{
    int data = NULL;
    node* next = NULL;
};
void insert(node* n, int s)
{
    if (n->data == NULL)
    {
        n->data = s;
        n->next = NULL;
    }
    else 
    {
        while (n->next != NULL)
        {
            n = n->next;
        }
        node* p = new node;
        p->data = s;
        p->next = NULL;
        n->next = p;
    }
}
void dfs( int visit[], node* arr[], int i,int j)//dfs
{
    if (visit[i] == -1)
    {
        visit[i] = j;
        node* p = arr[i];
        while (p != NULL)
        {
            int t = p->data-1;
            dfs(visit, arr, t, j);//방문한 정점에 연결된 정점에 대해 재귀
            p = p->next;
        }
    }
}
void cc()
{
    node* arr[1000];
    int visit[1000];
    for (int i = 0; i < 1000; i++)
        visit[i] = -1;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)//연결리스트 생성
    {
        int ind;
        cin >> ind;
        node* p = new node;
        p->data = NULL;
        p->next = NULL;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int n;
            cin >> n;
            insert(p, n);
        }
        arr[ind-1] = p;
    }
    for (int i = 0; i < N; i++)
    {
        dfs(visit, arr, i, i+1);//각 원소를 루트로 dfs실행
    }
    int cnt[1000];
    for (int i = 0; i < N; i++)
        cnt[i] = 0;
    for (int i = 0; i < N; i++)
        cnt[visit[i] - 1]++;//수 카운트
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        if (cnt[i] != 0)
            c++;
    }
    cout << c << " ";

    quickSort(cnt, 0, N - 1);//정렬
    
    for (int i = 0; i < N; i++)
    {
        if(cnt[i]!=0)
            cout << cnt[i] << " ";//0이 아닌 수 출력
    }
    cout << "\n";
}

int main()
{
    int N;
    cin >> N;
    while (N--)
        cc();
    return 0;
}