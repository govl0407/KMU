/*************
Çà·Ä°ö¼À by20203152 ÃÖÁ¤¹Î 23.05.09
********************/
#include<iostream>
using namespace std;
void cal()
{
    int r, s, t;
    cin >> r;
    cin >> s;
    cin >> t;
    int A[100][100];
    int B[100][100];
    int result[100][100];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            int n;
            cin >> n;
            A[i][j] = n;
        }
    }
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < t; j++)
        {
            int n;
            cin >> n;
            B[i][j] = n;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < t; j++)
        {
            int n =0;
            for (int k = 0; k < s; k++)
            {
                n += A[i][k] * B[k][j];
            }
            result[i][j] = n;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cout << result[i][j]<< " ";
        }
        cout << endl;
    }
    
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        cal();
    }
}