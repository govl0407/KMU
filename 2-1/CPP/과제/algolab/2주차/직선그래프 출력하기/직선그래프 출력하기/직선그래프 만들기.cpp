/*
���� �׷��� ����� by 20203152 ������ -23.04.05 
*/
#include<iostream>
using namespace std;

#define dot '*'
#define Y 'I'
#define X '+'
#define empty_space '.'
#define ZERO 'O'

void draw_graph(int n)
{
    n /= 2;
    for (int i = 0; i < n; i++)//Y�� ����϶�
    {
        for (int j = 0; j < n; j++)//2��и�
        {
            cout << empty_space;
        }

        cout << Y;//Y�� ���

        for (int k = 0; k < n; k++) //1��и�
        {
            if (k == n - i - 1)
                cout << dot;
            else
                cout << empty_space;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)//X�� ���
        cout << X;
    cout << ZERO;
    for (int i = 0; i < n; i++)
        cout << X;
    cout << endl;

    for (int i = 0; i < n; i++) //Y�� �����϶�
    {
        for (int k = 0; k < n; k++)//3��и�
        {
            if (k == n - i - 1)
                cout << dot;
            else
                cout << empty_space;
        }

        cout << Y;//Y�� ���

        for (int j = 0; j < n; j++)//4��и�
        {
            cout << empty_space;
        }
        cout << endl;
        
    }
        
}

int main() {

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int num;
        cin >> num;
        draw_graph(num);
    }
    return 0;
}
