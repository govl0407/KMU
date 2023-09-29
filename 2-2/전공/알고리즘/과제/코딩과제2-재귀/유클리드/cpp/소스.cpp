/***********************
20203152 최정민 유클리드 09/20
***********************************/
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) { return a; }
    else
    {
        return gcd(b, a % b);
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int a,b;
        cin >> a>> b;
        cout << gcd(a, b);
        cout << "\n";
    }
    return 0;
}