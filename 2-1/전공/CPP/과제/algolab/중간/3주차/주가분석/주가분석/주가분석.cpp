/*//////////////////////////////////
3���� �ְ��м� by 20203152 ������ 2023.04.11
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
            if (b == 0)//a�� ��������� 
            {
                if (a < input)
                    b = input;
                else if (a > input)
                    a = input;
            }
            else//�߰����� �ĺ��� ������
            {
                if (b < input)//�߰����� �ĺ� < �Է°� �̸� �߰����� �ĺ��� a�� �ǰ� �Է°��� ���ο� �߰����� �ĺ� 
                {
                    a = b;
                    b = input;
                }
                else if(b > input)//�߰����� �ĺ�>�Է°��̸� �߰����� �ĺ� �缱, �Է°��� ���ο� a�� ��, b�ʱ�ȭ
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