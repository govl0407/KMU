/******************************
k��° ���� by 20203152 ������ 23.04.12
********************************/

#include<iostream>
using namespace std;
int pointing(int N)
{
    int key;
    int n = N;
    if (n < 10)//���ڸ��� �������� ã����
    {
        return n;
    }
    n -= 9;

    if (n <= 180)// ���ڸ��� �������� ã����
    {
        if (n % 2 == 1)// ���� �ڸ� �� ã����
            return (n / 20) + 1;
        else// ���� �ڸ��� ã����
        {
            int a = (n % 20) / 2 - 1;
            if (a == -1)
                return 9;
            else
                return a;
        }

    }
    n -= 180;

    if (n <= 2700)//���ڸ��� �������� ã���� 
    {
        if (n % 3 == 1)//���� �ڸ��� ã����
            return (n / 300) + 1;

        else if (n % 3 == 2)//�����ڸ��� ã����
            return (n %300)/30;

        else
        {
            int a = (n % 30) / 3 - 1;//1�� �ڸ��� ã����
            if (a == -1)
                return 9;
            else
                return a;
        }
    }
    n -= 2700;

    if (n <= 36000)//���ڸ��� �������� ã����
    {
        if (n % 4 == 1)//õ�� �ڸ��� ã����
            return (n / 4000) + 1;

        else if (n % 4 == 2)//���� �ڸ��� ã����
            return (n / 400)%10;

        else if (n % 4 == 3)//���� �ڸ��� ã����
            return (n / 40)%10;

        else //1�� �ڸ��� ã����
        {
            int a = ((n % 4000) / 4)%10 - 1; //1�� �ڸ��� ã����
            if (a == -1)
                return 9;
            else
                return a;
        }
    }
    n -= 36000;

    if (n <= 450000)//���ڸ��� �������� ã����
    {
        if (n % 5 == 1)//���� �ڸ��� ã����
            return (n / 50000) + 1;

        else if (n % 5 == 2)//õ�� �ڸ��� ã����
            return (n / 5000)%10;

        else if (n % 5 == 3)//���� �ڸ��� ã����
            return (n / 500)%10;

        else if (n % 5 == 4)//���� �ڸ��� ã����
            return (n / 50)%10;

        else
        {
            int a = ((n % 50000) / 5)%10 - 1; //1�� �ڸ��� ã����
            if (a == -1)
                return 9;
            else
                return a;
        }
         
    }
    n -= 450000;

    if (n <= 5400000)//�ټ��ڸ��� �������� ã����
    {

        if (n % 6 == 1)//�ʸ��� �ڸ��� ã����
            return (n / 600000) + 1;

        else if (n % 6 == 2)//���� �ڸ��� ã����
            return (n / 60000)%10;

        else if (n % 6 == 3)//õ�� �ڸ��� ã����
            return (n / 6000)%10;

        else if (n % 6 == 4)//���� �ڸ��� ã����
            return (n / 600)%10;

        else if (n % 6 == 5)//���� �ڸ��� ã����
            return (n / 60)%10;

        else
        {
            int a = ((n % 600000) / 6)%10 - 1;; //1�� �ڸ��� ã����
            if (a == -1)
                return 9;
            else
                return a;
        }
    }
}


int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {   
        int n;
        cin >> n;
        cout << pointing(n) << endl;
    }
    return 0;
}
