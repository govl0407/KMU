/************
20203152 √÷¡§πŒ rec_LCS
3
abcbdab bdcaba
a a
abcd zyxw
************/
#include <iostream>
#define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int cnt = 0;
int MIN(int a, int b)
{
    int r;
    (a > b) ? r = b : r = a;
    return r;
}
int MAX(int a, int b)
{
    int r;
    (a < b) ? r = b : r = a;
    return r;
}
int L[101][101];
int LCS( char s[], char t[], int m, int n)
{
    if (L[m][n] != -1)
        return L[m][n];
    else
    {
        if (m == 0 || n == 0)
        {
            L[m][n] = 0;
            return 0;
        }
        else if (m > 0 and n > 0 and s[m - 1] == t[n - 1])
        {
            int k= LCS(s, t, m - 1, n - 1) + 1;
            L[m][n] = k;
            return k;
        }
        else
        {
            int k = MAX(LCS(s, t, m - 1, n), LCS(s, t, m, n - 1));
            L[m][n] = k;
            return k;
        }
            

    }
}
int main() {
    int n;
    cin >> n;
    char str1[100];
    char str2[100];
    while (n--)
    {
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                L[i][j] = -1;
        int m, n;
        cin >> str1;
        cin >> str2;
        int i;
        for (i = 0; i < 100; i++)
        {
            if (str1[i] == 0)
                break;
        }
        m = i;
        for (i = 0; i < 100; i++)
        {
            if (str2[i] == 0)
                break;
        }
        n = i;
        cout << LCS(str1, str2, m, n) << "\n";
    }
}
