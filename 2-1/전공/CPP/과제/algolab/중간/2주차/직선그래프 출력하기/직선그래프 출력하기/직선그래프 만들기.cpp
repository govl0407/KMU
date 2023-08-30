/*
직선 그래프 만들기 by 20203152 최정민 -23.04.05 
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
    for (int i = 0; i < n; i++)//Y가 양수일때
    {
        for (int j = 0; j < n; j++)//2사분면
        {
            cout << empty_space;
        }

        cout << Y;//Y축 출력

        for (int k = 0; k < n; k++) //1사분면
        {
            if (k == n - i - 1)
                cout << dot;
            else
                cout << empty_space;
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)//X축 출력
        cout << X;
    cout << ZERO;
    for (int i = 0; i < n; i++)
        cout << X;
    cout << endl;

    for (int i = 0; i < n; i++) //Y가 음수일때
    {
        for (int k = 0; k < n; k++)//3사분면
        {
            if (k == n - i - 1)
                cout << dot;
            else
                cout << empty_space;
        }

        cout << Y;//Y축 출력

        for (int j = 0; j < n; j++)//4사분면
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
