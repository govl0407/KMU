/**************************************************
* 요일 계산하기 by 20203152 최정민 23.05.02
*************************************************/
#include<iostream>
using namespace std;
bool yoon(int Y)
{
    if (Y % 4 == 0)//4로 나누어지면
        if (Y % 100 == 0)//100으로 나누어지면
            if (Y % 400 == 0)//400으로 나누어지면
                return true;
            else
                return false;
        else
            return true;
    else // 4로 나누어지지 않으면 
        return false;
}
void cal()
{
    int first_day = 4;//1582 1월 0일 부터 시작
    int Y = 1582;
    int year, month, day;
    cin >> year >> month >> day;
    

    while (Y != year)//1월 1일의 요일 결정
    {
        if (yoon(Y))
            first_day += 2;//윤년이면 다음해 1월 1일이 다다음 요일
        else
            first_day += 1;//평년이면 다음해 1월 1일이 다음 요일
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
            if (yoon(year))//윤년이면 29일 추가 아니면 28일 추가
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