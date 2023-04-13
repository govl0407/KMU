/*
숫자 정사각형 달팽이 모양 출력하기[재귀 함수 이용]  90점 짜리 by 20203152 최정민 0423.04.06
*/
#include<iostream>
using namespace std;

int z;

void snail(int n, int key, int N, int A, int B) // 배열의 맨 바깥 그리기
{
    if (n == 1 or n == 0) {
        key += 1;
        if (A - 1 <= z && z < B)
            cout << key << " ";
        cout << endl;
    }
    else
    {

        for (int i = 0; i < n; i++)//1단계 
        {
            key += 1;
            z++;

            if (A - 1 <= z && z < B)
                cout << key << " ";
        }

        for (int i = 0; i < n - 1; i++) //2단계
        {
            key += N;
            if (A - 1 <= z && z < B)
                cout << key << " ";
            z++;
        }
        for (int i = 0; i < n - 1; i++)//3단계
        {
            key -= 1;
            if (A - 1 <= z && z < B)
                cout << key << " ";
            z++;
        }
        for (int i = 0; i < n - 2; i++)//4단계
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