/******************************
두 사각형 면적둘레 구하기 by 20203152 최정민 23.04.12
********************************/

#include<iostream>
using namespace std;

int length(int x1, int y1, int x2, int y2)
{
    return (x2 - x1 + y2 - y1)*2;
}
int area(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (y2 - y1);
}
void cal()
{
    int A_x[2];
    int A_y[2];
    int B_x[2];
    int B_y[2];
    for (int i = 0; i < 2; i++)//a에 입력
    {
        int a;
        cin >> a;
        A_x[i] = a;
        cin >> a;
        A_y[i] = a;
    }
    for (int i = 0; i < 2; i++)//b에 입력
    {
        int a;
        cin >> a;
        B_x[i] = a;
        cin >> a;
        B_y[i] = a;
    }
    if (A_x[0] > B_x[1] || A_x[1]<B_x[0] || A_y[0]>B_y[1] || A_y[1] < B_y[0]) // 두 사각형이 겹치지 않을때 
    {
        cout << area(A_x[0], A_y[0], A_x[1], A_y[1]) + area(B_x[0], B_y[0], B_x[1], B_y[1]) << " ";
        cout << length(A_x[0], A_y[0], A_x[1], A_y[1]) + length(B_x[0], B_y[0], B_x[1], B_y[1]) << endl;
    }
    else//사각형이 겹칠때
    {
        int C_x[2];
        int C_y[2];
        if (A_x[0] < B_x[0])//겹치는 사각형의 x위치 결정
            C_x[0] = B_x[0];
        else
            C_x[0] = A_x[0];
        if (A_x[1] > B_x[1])
            C_x[1] = B_x[1];
        else
            C_x[1] = A_x[1];

        if (A_y[0] < B_y[0])//겹치는 사각형의 y위치 결정
            C_y[0] = B_y[0];
        else
            C_y[0] = A_y[0];
        if (A_y[1] > B_y[1])
            C_y[1] = B_y[1];
        else
            C_y[1] = A_y[1];



        cout << area(A_x[0], A_y[0], A_x[1], A_y[1]) + area(B_x[0], B_y[0], B_x[1], B_y[1]) - area(C_x[0], C_y[0], C_x[1], C_y[1]) << " ";//넓이
        cout << length(A_x[0], A_y[0], A_x[1], A_y[1]) + length(B_x[0], B_y[0], B_x[1], B_y[1]) - length(C_x[0], C_y[0], C_x[1], C_y[1]) << endl;//둘레
    }
}


int main()
{
    int cases;
    cin >> cases;
    while (cases--)
        cal();
    return 0;
}