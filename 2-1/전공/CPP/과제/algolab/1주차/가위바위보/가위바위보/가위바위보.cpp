/*20203152최정민// 1주차 과제 - 가위바위보 게임*/
/*가위s =1 바위r =2 보p =3*/
#include<iostream>
using namespace std;
void rsp()
{
    int s= 0 , r= 0, p=0;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        switch (temp)
        {
        case 1: 
            s++;
            break;
        case 2: 
            r++;
            break;
        case 3:
            p++;
            break;
        }
        
    }
        /*가위 바위 보 가 전부 나오거나 한가지만 나오면 무승부*/
    int chk = 0;
    if (s != 0)
        chk++;
    if (r != 0)
        chk++;
    if (p != 0)
        chk++;

    if (chk == 3 || chk == 1)/*무승부*/
    {
        cout << 0 << endl;
    }
    else/*승리*/
    {
        if (s != 0)/*가위*/
        {
            if (r != 0)/*가위 vs 바위*/
            {
                cout << r << endl;/*바위 승*/
            }
            else/*가위 vs 보*/
            {
                cout << s << endl;/*가위 승*/
            }
        }

        else if (r != 0)/*바위*/
        {/*바위 vs 보*/
            cout << p << endl;/*보 승*/
        }
    }
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        rsp();
    }
    return 0;
}