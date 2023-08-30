/*
���� ���簢�� ������ ��� ����ϱ�[��� �Լ� �̿�]  90�� ¥�� by 20203152 ������ 0423.04.06
*/
#include<iostream>
using namespace std;

int z;

void snail(int n, int key, int N, int A, int B) // �迭�� �� �ٱ� �׸���
{
    if (n == 1 or n == 0) {
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

        snail(n - 2, key, N, A, B);
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
        snail(num, 0, num, a, b);
    }
    return 0;

}