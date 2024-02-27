/**************
20203152 ������ prim
**************/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define swap(a, b) {int t = a; a = b; b = t;}
struct node//���Ḯ��Ʈ ���
{
    int target = NULL;
    int weight = NULL;
    node* next = NULL;
};
void insert(node* n, int s, int w)//���Ḯ��Ʈ �� ��� ����
{
    if (n->target == NULL)//�� ����϶�
    {
        n->target = s;
        n->weight = w;
        n->next = NULL;
    }
    else//��� �ڿ� ����
    {
        while (n->next != NULL)
        {
            n = n->next;
        }
        node* p = new node;
        p->target = s;
        p->weight = w;
        p->next = NULL;
        n->next = p;
    }
}
int prim(int n, node* W[], int F[][2])
{
    int vnear;
    int nearest[2002];
    int distance[2002];
    int f_index = 0;
    for (int i = 2; i <= n; i++)//��Ʈ ��忡�� �ɸ��� �Ÿ� �ʱ�ȭ
    {
        nearest[i] = 1;
        distance[i] = INT_MAX;
    }
    node* p = W[1];
    while (p != NULL)
    {
        distance[p->target] = p->weight;
        p = p->next;
    }
    for (int t = 0; t < n - 1; t++)
    {
        int min = INT_MAX;
        for (int i = 2; i <= n; i++)
        {
            if (distance[i] >= 0 && distance[i] < min)
            {
                min = distance[i];
                vnear = i;
            }
        }
        F[f_index][0] = vnear;//v -> vnear ����
        F[f_index][1] = nearest[vnear];
        f_index++;
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++)
        {
            int wiv = INT_MAX;//���� �ȵǸ� �Ÿ� ����
            node* p = W[i];
            while (p != NULL && p->target != vnear)
                p = p->next;
            if (p != NULL)//����� target�� ����ġ
                wiv = p->weight;

            if (wiv < distance[i])
            {
                distance[i] = wiv;
                nearest[i] = vnear;
            }
        }
    }
    return f_index;//== n-1
}

void MST()
{
    node* arr[1001];//���Ḯ��Ʈ
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)//���Ḯ��Ʈ �����
    {
        int ind;
        cin >> ind;
        node* p = new node;
        p->target = NULL;
        p->next = NULL;
        int num;
        cin >> num;
        insert(p, ind, 0);
        for (int j = 0; j < num; j++)
        {
            int n;
            cin >> n;
            int w;
            cin >> w;
            insert(p, n, w);
        }
        arr[ind] = p;
    }

    int F[1001][2];

    int sum = 0;
    int k = prim(N, arr, F);//prim ����
    for (int i = 0; i < k; i++)//F�� ��� ������ ����ġ ��
    {
        int t = F[i][0];
        node* p = arr[t];
        while (p != NULL && p->target != F[i][1])
            p = p->next;
        sum += p->weight;
    }
    cout << sum << "\n";
}

int main()
{  
    int N;
    cin >> N;
    while (N--)
        MST();
    return 0;
}