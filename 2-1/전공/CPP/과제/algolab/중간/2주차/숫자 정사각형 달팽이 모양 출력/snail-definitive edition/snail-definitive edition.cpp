/*
숫자 정사각형 달팽이 모양 출력하기[재귀 함수 이용]  90점 짜리 by 20203152 최정민 0423.04.06*** a값이 몇번째 안쪽의 박스에 있는지 계산하고 거기서 부터 그리는거 시도
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


void snail(int n, int key, int N, int A, int B) // 배열의 맨 바깥 그리기
{
    if (n == 1 || n==0) {
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