/************
20203152 √÷¡§πŒ DP_LCS
4
abcbdab bdcaba
abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz
a b
abcdefghijklmnopqrstuvwxyz zyxwvutsrqponmlkjihgfedcba
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

int L[101][101], S[101][101];

int LCS(char s[], char t[], int m, int n)
{
    int i, j;
    for (i = 0; i <= m; i++)
        L[i][0] = 0;
    for (i = 0; i <= n; i++)
        L[0][i] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 0;
            }
            else
            {
                L[i][j] = MAX(L[i][j - 1], L[i - 1][j]);
                if (L[i][j] == L[i][j - 1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }
    return L[m][n];
}

void printLCS(char s[], char t[], int m, int n)
{
    if (m == 0 || n == 0)
        return;
    if (S[m][n] == 0)
    {
        printLCS(s, t, m - 1, n - 1);
        cout << s[m - 1];
    }
    else if (S[m][n] == 1)
        printLCS(s, t, m, n - 1);
    else if (S[m][n] == 2)
        printLCS(s, t, m - 1, n);
}

int main() {
    int n;
    cin >> n;
    char str1[100];
    char str2[100];
    while (n--)
    {
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
        cout << LCS(str1, str2, m, n) << " ";
        printLCS(str1, str2, m, n);
        cout <<"\n";
    }
}
