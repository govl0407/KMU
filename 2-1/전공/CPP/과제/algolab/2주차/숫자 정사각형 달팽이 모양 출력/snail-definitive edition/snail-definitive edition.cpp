/*
���� ���簢�� ������ ��� ����ϱ�[��� �Լ� �̿�]  90�� ¥�� by 20203152 ������ 0423.04.06*** a���� ���° ������ �ڽ��� �ִ��� ����ϰ� �ű⼭ ���� �׸��°� �õ�
*/
#include<iostream>
using namespace std;

int z;
int start;
int starting(int n,int a)
{
    int N = n;
    int k = 0;
    while (4*N - 3 >= a || N ==0)
    {
        N -= 2;
        start += n + 1;
    }
    return N;
}


void snail(int n, int key, int N, int A, int B) // �迭�� �� �ٱ� �׸���
{
    if (n == 1 || n==0) {
        key += 1;
        if (A - 1 <= z && z < B)
            cout << key << " ";
        cout << endl;
    }
    else
    {

        for (int i = 0; i < n; i++)//1�ܰ� 
        {
            key += 1;
            z++;

            if (A - 1 <= z && z < B)
                cout << key << " ";
        }

        for (int i = 0; i < n - 1; i++) //2�ܰ�
        {
            key += N;
            if (A - 1 <= z && z < B)
                cout << key << " ";
            z++;
        }
        for (int i = 0; i < n - 1; i++)//3�ܰ�
        {
            key -= 1;
            if (A - 1 <= z && z < B)
                cout << key << " ";
            z++;
        }
        for (int i = 0; i < n - 2; i++)//4�ܰ�
        {
            key -= N;

            if (A - 1 <= z && z < B)
                cout << key << " ";
            z++;
        }
    }
}




int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        z = 0;
        int num;
        cin >> num;

        int a, b;
        cin >> a >> b;

        start = 0;
        int N =starting(num , a);


        snail(N, 0, num , a, b);
    }
    return 0;

}