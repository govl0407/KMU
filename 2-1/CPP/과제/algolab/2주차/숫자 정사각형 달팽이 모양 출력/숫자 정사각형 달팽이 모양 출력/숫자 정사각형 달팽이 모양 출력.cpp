/*
숫자 정사각형 달팽이 모양 출력 by 20203152최정민 -23.04.06
*/
#include<iostream>
using namespace std;

void snail(int s)
{
    int matrix[1000][1000];
    for (int i = 0; i < s; i++)
    {
        matrix[i][s] = 0;
    }
    for (int i = 0; i < s; i++)
    {
        matrix[s][i] = 0;
    }
    const int Size = s * s;
    int nums[1000000];//숫자를 넣을 틀
    int z = 1;
    for (int i = 0; i < s; i++)//matrix에 행렬을 넣음
    {
        for (int j = 0; j < s; j++)
        {
            matrix[i][j] = z;
            z++;
        }
    }
    int x = 0, y = 0;//matrix내의 위치
    int go_X = 1, go_Y = 1;//움직이는 정도
    char go = 'x';//가는 방향
    for (int i = 0; i < Size; i++)//25개를 다 읽을 동안
    {
        nums[i] = matrix[y][x];
        matrix[y][x] = 0;
        if (go == 'x')//x축 방향으로 이동할때
        {
            if (matrix[y][x + go_X] == 0)//가능 방향의 다음 값이 0이면 방향 전환
            {
                go = 'y';
                go_X = -go_X;
                y += go_Y;
            }
            else
                x += go_X;
        }
        else//y축 방향으로 이동할때
        {
            if (matrix[y+go_Y][x] == 0)//가능 방향의 다음 값이 0이면 방향 전환
            {
                go = 'x';
                go_Y = -go_Y;
                x += go_X;
            }
            else
                y += go_Y;
        }
    }
    int a, b;
    cin >> a;
    cin >> b;
    for (int i = a-1; i < b; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int num;
        cin >> num;
        snail(num);
    }
    return 0;
}