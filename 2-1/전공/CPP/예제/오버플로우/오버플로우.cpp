#include <iostream>
#include <climits>
using namespace std; // �̸���������
int main()
{
    short s_money = SHRT_MAX; // �ִ밪�����ʱ�ȭ�Ѵ�.
    unsigned short u_money = USHRT_MAX; // �ִ밪�����ʱ�ȭ�Ѵ�.
    s_money = s_money + 1;
    cout << "s_money = " << s_money << endl;
    u_money = u_money + 1;
    cout << "u_money = " << u_money << endl;
    return 0;
}