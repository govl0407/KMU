/**************************************************
* ���� ����ϱ� by 20203152 ������ 23.05.02
*************************************************/
#include<iostream>
using namespace std;
bool yoon(int Y)
{
    if (Y % 4 == 0)//4�� ����������
        if (Y % 100 == 0)//100���� ����������
            if (Y % 400 == 0)//400���� ����������
                return true;
            else
                return false;
        else
            return true;
    else // 4�� ���������� ������ 
        return false;
}
void cal()
{
    int first_day = 4;//1582 1�� 0�� ���� ����
    int Y = 1582;
    int year, month, day;
    cin >> year >> month >> day;
    

    while (Y != year)//1�� 1���� ���� ����
    {
        if (yoon(Y))
            first_day += 2;//�����̸� ������ 1�� 1���� �ٴ��� ����
        else
            first_day += 1;//����̸� ������ 1�� 1���� ���� ����
        first_day %= 7;
        Y++;
    }

    switch (month)
    {
        case 12:
            first_day += 30;
        case 11:
            first_day += 31;
        case 10:
            first_day += 30;
        case 9:
            first_day += 31;
        case 8:
            first_day += 31;
        case 7:
            first_day += 30;
        case 6:
            first_day += 31;
        case 5:
            first_day += 30;
        case 4:
            first_day += 31;
        case 3:
            if (yoon(year))//�����̸� 29�� �߰� �ƴϸ� 28�� �߰�
                first_day += 29;
            else
                first_day += 28;
        case 2:
            first_day += 31;
        case 1:
            first_day += day;
    }
    cout << first_day % 7 << endl;
}    
int main()
{
    int cases;
    cin >> cases;
    while (cases--)
        cal();
    return 0;
}