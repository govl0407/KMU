/***********************
20203152 ÃÖÁ¤¹Î ºü¸¥°ÅµìÁ¦°ö 09/22
***********************************/
#include<iostream>
using namespace std;

int fast_power(int x, int n)
{
    if (n == 0) { return 1; }
    else if (n % 2 == 0)
    {
        int k = fast_power(x, n / 2) % 1000;
        return (k * k) % 1000;
    }
    else
    {
        int k = fast_power(x, (n - 1) / 2) % 1000;
        k = (k * k) % 1000;
        return (x * k) % 1000;
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int x;
        int n;
        cin >> x >> n;
        cout << fast_power(x, n) % 1000;
        cout << "\n";
    }
    return 0;
}
//2147483647