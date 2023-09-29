#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1) { return n; }
    else { return fibonacci(n - 1) + fibonacci(n - 2); }
    
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        cout << fibonacci(n);
        cout << "\n";
    }
    return 0;
}