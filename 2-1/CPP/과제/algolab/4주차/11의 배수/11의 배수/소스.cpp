/*********************************************
* 11�� ��� by 20203152������ 23.05.03
***********************************************/
//�ݷ� 111
#include<iostream>
using namespace std;
#define N 101
void Minus(char *n, int len, char a) //���� ���� �Լ�
{
    if (len > 0)
    {
        if (n[len - 1] >= a)
        {
            n[len - 1] -= a;
            n[len - 1] += 48;
        }

        else// ���� 0������ ���� ���ڸ��� 1�� ����
        {
            n[len - 1] = n[len - 1] + 10 - a;
            n[len - 1] += 48;
            Minus(n, len - 1, 49);
        }
        if (n[len - 1] == 58)
            n[len - 1] -= 10;
    }
    
}
void cal()
{
    int len =0;
    char n[N];
    char temp[N];
    
    cin >> n;
    while (n[len] != '\0')
        len++;
    temp[len] = '\0';
    while (len--)
    {
        temp[len] = n[len];
        Minus(n,len,n[len]);
    }
    if(n[0] == 48 || n[0] == 58)//0���� ���
    {
        int i = 1;
        while (temp[i] == '0')
            i++;
        while (temp[i] != '\0')
                cout << temp[i++];
    }
    else//������ �������� �ʴ� ���
        cout << 0;
    cout << endl;
}

int main()
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        cal();
    }

    return 0;
}
