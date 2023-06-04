/*
���� ���簢�� ������ ��� ��� by 20203152������ -23.04.06
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
    int nums[1000000];//���ڸ� ���� Ʋ
    int z = 1;
    for (int i = 0; i < s; i++)//matrix�� ����� ����
    {
        for (int j = 0; j < s; j++)
        {
            matrix[i][j] = z;
            z++;
        }
    }
    int x = 0, y = 0;//matrix���� ��ġ
    int go_X = 1, go_Y = 1;//�����̴� ����
    char go = 'x';//���� ����
    for (int i = 0; i < Size; i++)//25���� �� ���� ����
    {
        nums[i] = matrix[y][x];
        matrix[y][x] = 0;
        if (go == 'x')//x�� �������� �̵��Ҷ�
        {
            if (matrix[y][x + go_X] == 0)//���� ������ ���� ���� 0�̸� ���� ��ȯ
            {
                go = 'y';
                go_X = -go_X;
                y += go_Y;
            }
            else
                x += go_X;
        }
        else//y�� �������� �̵��Ҷ�
        {
            if (matrix[y+go_Y][x] == 0)//���� ������ ���� ���� 0�̸� ���� ��ȯ
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