/***********************
20203152 ������ ��Ʈ�� ������ 09/21
***********************************/
#include<iostream>
using namespace std;

void rev(char a[], int i)
{
    if (a[i] == 0) {}
    else {
        rev(a, i + 1);//��� -> �� �� ���� ����ϰ� ����
        cout << a[i];
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        char a[100];
        cin >> a;
        rev(a, 0);
        cout << "\n";
    }
    return 0;
}