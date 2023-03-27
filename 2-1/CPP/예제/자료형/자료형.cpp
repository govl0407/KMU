#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    short year = SHRT_MAX;
    int sale = INT_MAX;
    long total_sale = LONG_MAX;
    cout << "short형의크기=" << sizeof(short) << endl;
    cout << "int형의크기=" << sizeof(int) << endl;
    cout << "long형의크기=" << sizeof(long) << endl << endl;
    cout << "short형의최대값=" << year << endl;
    cout << "int형의최대값=" << sale << endl;
    cout << "long형의최대값=" << total_sale << endl << endl;
    cout << "short형의최소값=" << SHRT_MIN << endl;
    cout << "int형의최대값=" << INT_MIN << endl;
    cout << "long형의최대값=" << LONG_MIN << endl << endl;
    return 0;


}