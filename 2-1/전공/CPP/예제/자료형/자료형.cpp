#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    short year = SHRT_MAX;
    int sale = INT_MAX;
    long total_sale = LONG_MAX;
    cout << "short����ũ��=" << sizeof(short) << endl;
    cout << "int����ũ��=" << sizeof(int) << endl;
    cout << "long����ũ��=" << sizeof(long) << endl << endl;
    cout << "short�����ִ밪=" << year << endl;
    cout << "int�����ִ밪=" << sale << endl;
    cout << "long�����ִ밪=" << total_sale << endl << endl;
    cout << "short�����ּҰ�=" << SHRT_MIN << endl;
    cout << "int�����ִ밪=" << INT_MIN << endl;
    cout << "long�����ִ밪=" << LONG_MIN << endl << endl;
    return 0;


}