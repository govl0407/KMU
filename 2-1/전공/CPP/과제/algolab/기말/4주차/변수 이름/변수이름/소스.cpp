/*********************************************
* 변수이름 by 20203152최정민 23.05.02
***********************************************/
#include<iostream>
using namespace std;
#define N 256
int cal()
{
    char str[N];
    cin >> str;
    int i = 0;
    if ((str[0] >= 97 && str[0] <= 122) || (str[0] >= 65 && str[0] <= 90))
    {
    }
    else {
        if (str[0] == '_')
        { }
        else
            return 0;
    }
    while (1)
    {
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
        {
        }
        else if (str[i] >= 48 && str[i] <= 57)
        {
        }
        else if (str[i] == '_')
        {
        }
        else if (str[i] == '\0')
            return 1;
        else return 0;
        
        i++;
    }
}

int main()
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        cout << cal() << endl;
    }

    return 0;
}
