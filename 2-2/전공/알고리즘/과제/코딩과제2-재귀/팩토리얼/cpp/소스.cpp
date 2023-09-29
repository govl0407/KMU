/***********************
20203152 √÷¡§πŒ ∆—≈‰∏ÆæÛ 09/20
***********************************/

#include<iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0) { return 1; }
    else
    {
        int r = n * factorial(n - 1);
        while (r % 10 == 0)
        {
            r /= 10;
        }
        r = r % 10000;
        return r;
    }
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        int m = factorial(n);
        cout << m % 1000;
        cout << "\n";
    }
    return 0;
}