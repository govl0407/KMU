/******************************
�� �簢�� �����ѷ� ���ϱ� by 20203152 ������ 23.04.12
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
    for (int i = 0; i < 2; i++)//a�� �Է�
    {
        int a;
        cin >> a;
        A_x[i] = a;
        cin >> a;
        A_y[i] = a;
    }
    for (int i = 0; i < 2; i++)//b�� �Է�
    {
        int a;
        cin >> a;
        B_x[i] = a;
        cin >> a;
        B_y[i] = a;
    }
    if (A_x[0] > B_x[1] || A_x[1]<B_x[0] || A_y[0]>B_y[1] || A_y[1] < B_y[0]) // �� �簢���� ��ġ�� ������ 
    {
        cout << area(A_x[0], A_y[0], A_x[1], A_y[1]) + area(B_x[0], B_y[0], B_x[1], B_y[1]) << " ";
        cout << length(A_x[0], A_y[0], A_x[1], A_y[1]) + length(B_x[0], B_y[0], B_x[1], B_y[1]) << endl;
    }
    else//�簢���� ��ĥ��
    {
        int C_x[2];
        int C_y[2];
        if (A_x[0] < B_x[0])//��ġ�� �簢���� x��ġ ����
            C_x[0] = B_x[0];
        else
            C_x[0] = A_x[0];
        if (A_x[1] > B_x[1])
            C_x[1] = B_x[1];
        else
            C_x[1] = A_x[1];

        if (A_y[0] < B_y[0])//��ġ�� �簢���� y��ġ ����
            C_y[0] = B_y[0];
        else
            C_y[0] = A_y[0];
        if (A_y[1] > B_y[1])
            C_y[1] = B_y[1];
        else
            C_y[1] = A_y[1];



        cout << area(A_x[0], A_y[0], A_x[1], A_y[1]) + area(B_x[0], B_y[0], B_x[1], B_y[1]) - area(C_x[0], C_y[0], C_x[1], C_y[1]) << " ";//����
        cout << length(A_x[0], A_y[0], A_x[1], A_y[1]) + length(B_x[0], B_y[0], B_x[1], B_y[1]) - length(C_x[0], C_y[0], C_x[1], C_y[1]) << endl;//�ѷ�
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