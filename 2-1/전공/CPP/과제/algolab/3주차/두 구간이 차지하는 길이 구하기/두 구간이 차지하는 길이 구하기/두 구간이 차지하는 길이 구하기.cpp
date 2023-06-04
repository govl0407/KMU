/******************************
두 구간이 차지하는 길이 구하기 by 20203152 최정민 23.04.12
********************************/

#include<iostream>
using namespace std;

void length()
{
    int A[2];
    int B[2];
    int C[2];
    C[0] = 100;
    C[1] = 0;
    for (int i = 0; i < 2; i++)
        cin >> A[i];
    for (int i = 0; i < 2; i++)
        cin >> B[i];
    
    if (A[0] > B[1] || A[1] < B[0])// 두 구간이 겹치지 않을때
    {
        cout << "0 ";
        cout << (A[1] - A[0] + B[1] - B[0]);
        cout << endl;
    }
    else
    {
        if (C[0] > A[0])//C는 두 길이를 포함한 길이
            C[0] = A[0];

        if (C[0] > B[0])
            C[0] = B[0];


        if (C[1] < A[1])
            C[1] = A[1];

        if (C[1] < B[1])
            C[1] = B[1];

        int D[2]; // 겹치는 구간
        if (A[0] > B[0])
        {
            D[0] = A[0];
            if (A[1] > B[1])
                D[1] = B[1];
            else
                D[1] = A[1];
        }
        else
        {
            D[0] = B[0];
            if (A[1] > B[1])
                D[1] = B[1];
            else
                D[1] = A[1];
        }
        cout << D[1] - D[0] << " " << C[1] - C[0] << endl;

    }


}



int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        length();
    }
    return 0;
}