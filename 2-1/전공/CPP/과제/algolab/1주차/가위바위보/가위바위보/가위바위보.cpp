/*20203152������// 1���� ���� - ���������� ����*/
/*����s =1 ����r =2 ��p =3*/
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
        /*���� ���� �� �� ���� �����ų� �Ѱ����� ������ ���º�*/
    int chk = 0;
    if (s != 0)
        chk++;
    if (r != 0)
        chk++;
    if (p != 0)
        chk++;

    if (chk == 3 || chk == 1)/*���º�*/
    {
        cout << 0 << endl;
    }
    else/*�¸�*/
    {
        if (s != 0)/*����*/
        {
            if (r != 0)/*���� vs ����*/
            {
                cout << r << endl;/*���� ��*/
            }
            else/*���� vs ��*/
            {
                cout << s << endl;/*���� ��*/
            }
        }

        else if (r != 0)/*����*/
        {/*���� vs ��*/
            cout << p << endl;/*�� ��*/
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