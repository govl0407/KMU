/******************************
k번째 숫자 by 20203152 최정민 23.04.12
********************************/

#include<iostream>
using namespace std;
int pointing(int N)
{
    int key;
    int n = N;
    if (n < 10)//한자리수 범위에서 찾을때
    {
        return n;
    }
    n -= 9;

    if (n <= 180)// 두자리수 범위에서 찾을때
    {
        if (n % 2 == 1)// 십의 자리 를 찾을때
            return (n / 20) + 1;
        else// 일의 자리를 찾을때
        {
            int a = (n % 20) / 2 - 1;
            if (a == -1)
                return 9;
            else
                return a;
        }

    }
    n -= 180;

    if (n <= 2700)//세자리수 범위에서 찾을때 
    {
        if (n % 3 == 1)//백의 자리를 찾을때
            return (n / 300) + 1;

        else if (n % 3 == 2)//십의자리를 찾을때
            return (n %300)/30;

        else
        {
            int a = (n % 30) / 3 - 1;//1의 자리를 찾을때
            if (a == -1)
                return 9;
            else
                return a;
        }
    }
    n -= 2700;

    if (n <= 36000)//네자리수 범위에서 찾을때
    {
        if (n % 4 == 1)//천의 자리를 찾을때
            return (n / 4000) + 1;

        else if (n % 4 == 2)//백의 자리를 찾을때
            return (n / 400)%10;

        else if (n % 4 == 3)//십의 자리를 찾을때
            return (n / 40)%10;

        else //1의 자리를 찾을때
        {
            int a = ((n % 4000) / 4)%10 - 1; //1의 자리를 찾을때
            if (a == -1)
                return 9;
            else
                return a;
        }
    }
    n -= 36000;

    if (n <= 450000)//네자리수 범위에서 찾을때
    {
        if (n % 5 == 1)//만의 자리를 찾을때
            return (n / 50000) + 1;

        else if (n % 5 == 2)//천의 자리를 찾을때
            return (n / 5000)%10;

        else if (n % 5 == 3)//백의 자리를 찾을때
            return (n / 500)%10;

        else if (n % 5 == 4)//십의 자리를 찾을때
            return (n / 50)%10;

        else
        {
            int a = ((n % 50000) / 5)%10 - 1; //1의 자리를 찾을때
            if (a == -1)
                return 9;
            else
                return a;
        }
         
    }
    n -= 450000;

    if (n <= 5400000)//다섯자리수 범위에서 찾을때
    {

        if (n % 6 == 1)//십만의 자리를 찾을때
            return (n / 600000) + 1;

        else if (n % 6 == 2)//만의 자리를 찾을때
            return (n / 60000)%10;

        else if (n % 6 == 3)//천의 자리를 찾을때
            return (n / 6000)%10;

        else if (n % 6 == 4)//백의 자리를 찾을때
            return (n / 600)%10;

        else if (n % 6 == 5)//십의 자리를 찾을때
            return (n / 60)%10;

        else
        {
            int a = ((n % 600000) / 6)%10 - 1;; //1의 자리를 찾을때
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
