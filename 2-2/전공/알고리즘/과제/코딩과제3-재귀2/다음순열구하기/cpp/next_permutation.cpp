/***********************
20203152 ������ �����������ϱ� 10/07
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;
void find_next(char str[], int len)
{
    int i;
    for (i = len-1; i >=1; i--) //�������� ����ã��
    { 
        if (i == 0) { break; }
        if (str[i] >  str[i - 1]) { break; } 
    }
    if (i == 0)
    {
        //ù��° ����(�������� ����) ���
        char tmp[26];//������ ����
        int n = 0;
        for (int j = len - 1; j >= 0; j--)
        {
            tmp[n] = str[j];
            n++;
        }
        for (int i = 0; i < len; i++)
            cout << tmp[i];
    }
    else
    {
        char c = 'z';
        int p = i;
        for (int j = i; j < len; j++)//R���� �������� ���� ã��
        {
            if (str[j] > str[i-1] && c >= str[j])
            {
                c = str[j];
                p = j;
            }
        }
        swap(str[p], str[i - 1]);//��ȯ

        char tmp[26];//������ ����
        for (int j = 0; j < i; j++)
            tmp[j] = str[j];
        int n = i;
        for (int j = len-1; j >=i ; j--)
        {
            tmp[n] = str[j];
            n++;
        }
        for (int i = 0; i < len; i++)
            cout << tmp[i];
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int len;
        char str[27];
        cin >> len >> str;
        find_next(str, len);
        cout << "\n";
    }
    return 0;
}
