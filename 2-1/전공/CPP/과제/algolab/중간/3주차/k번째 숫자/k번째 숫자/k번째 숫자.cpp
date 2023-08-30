#include<iostream>
using namespace std;

int pointing(int N)
{
    int n = N;
    int ans = 10;
    int count = 9;
    int digit = 1;

    while (n > digit * count)
    {
        n -= digit * count;
        digit++;
        count *= 10;
    }

    int a = n % digit;
    int div = digit;
    if (a == 0) a = digit;
    
    for (int i = 0; i < digit - a; i++)
        div *= 10;
    ans += (n / div) % 10;
    
    if (digit != 1)
    {
        if (a == 1)
            ans++;
        else if (a == digit)
            ans--;
    }
    return ans % 10;
}


int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n;
        cin >> n;
        cout << pointing(n) << endl;
    }
    return 0;
}