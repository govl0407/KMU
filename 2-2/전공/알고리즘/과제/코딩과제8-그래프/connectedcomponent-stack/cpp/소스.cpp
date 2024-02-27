/**************
20203152 최정민 dfs_cc
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
struct stack
{
    int data[1000];
    int top = -1;
};
int pop(stack &s)
{
    if (s.top >= 0)
    {
        s.top--;
        return s.data[s.top + 1];
    }
    else
        return -1;
}
void push(stack &s, int n)
{
    s.top++;
    s.data[s.top] = n;
}
int empty(stack &s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
void dfs(stack& s, int visit[], node* arr[], int i)
{
    push(s, i+1);
    do
    {
        int k = pop(s);
        node* p = arr[k - 1];
        if (visit[k - 1] == -1)
            visit[k - 1] = i + 1;
        while (p != NULL)
        {
            int t = p->data;
            if (visit[t - 1] == -1)
            {
                push(s, t);
                visit[t - 1] = i + 1;
            }
            p = p->next;
        }
    } while (!empty(s));
}
void cc()
{
    node* arr[1000];
    int visit[1000];
    stack s;
    for (int i = 0; i < 1000; i++)
        visit[i] = -1;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
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
        dfs(s, visit, arr, i);//각 원소를 루트로 dfs실행
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

    quickSort(cnt, 0, N - 1);
    
    for (int i = 0; i < N; i++)
    {
        if(cnt[i]!=0)
            cout << cnt[i] << " ";
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