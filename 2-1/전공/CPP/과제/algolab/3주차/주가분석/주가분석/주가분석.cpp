/*//////////////////////////////////
3주차 주가분석 by 20203152 최정민 2023.04.11
*////////////////////////////

#include<iostream>
using namespace std;


void pricing()
{
    int cnt = 0;
    int cases;
    cin >> cases;
    int a, b;
    b = 0;
    cin >> a;
    cases--;
    while(cases--)
    //for(int i=0;i<cases;i++)
    {
        int input;
        cin >> input;
            if (b == 0)//a만 들어있을때 
            {
                if (a < input)
                    b = input;
                else if (a > input)
                    a = input;
            }
            else//중간고점 후보가 있을때
            {
                if (b < input)//중간고점 후보 < 입력값 이면 중간고점 후보가 a가 되고 입력값이 새로운 중간고점 후보 
                {
                    a = b;
                    b = input;
                }
                else if(b > input)//중간고점 후보>입력값이면 중간고점 후보 당선, 입력값이 새로운 a가 됨, b초기화
                {
                    a = input;
                    b = 0;
                    cnt++;
                }
            }
            
    }
    cout << cnt << endl;
}

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    //for(int i=0;i<cases;i++)
        pricing();

    return 0;
}