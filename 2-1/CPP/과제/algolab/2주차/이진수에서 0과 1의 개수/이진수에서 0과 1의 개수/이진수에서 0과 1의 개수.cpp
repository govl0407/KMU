/*
���������� 0�� 1�� ���� by 20203152 ������ - 23.04.05
*/

#include<iostream>
#include<fstream>
using namespace std;

void many_bit(unsigned int n)
{
    int bit_0 = 0; //0bit
    int bit_1 = 1; //1bit
    while (n != 1)
    {
        if (n % 2 == 0)
            bit_0++;
        else
            bit_1++;

        n /= 2;
    }
    cout << bit_0 << ' ' << bit_1 << endl; 
}

int main()
{
    
    ifstream fin;
    fin.open("input.txt");//���� ����

    int cases;
    fin >> cases; //case ���� �ޱ�
    
    for (int i = 0; i < cases; i++)
    {
        unsigned int n;
        fin >> n; //���پ� �ޱ�
        
        many_bit(n);//�Լ� ����
    }

    return 0;
}
