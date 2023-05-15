/*************************
오셀로게임 by20203152 최정민 21.05.11
*************************/
#include<iostream>
using namespace std;

void cal()
{
    //초기화
    char arr[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            arr[i][j] = '+';
    arr[3][3] = 'O';
    arr[3][4] = 'X';
    arr[4][3] = 'X';
    arr[4][4] = 'O';

    int n;
    cin >> n;
    char c = 'X'; //돌 색
    while (n--)
    {

        int a, b;
        cin >> a >> b;
        a--;
        b--;// 좌표는 1부터 시작해서 1 빼줌
        arr[a][b] = c;
        int originpos_a =a;
        int originpos_b =b;


        //체크
        for (int i = a + 1; i < 8; i++)//아래 체크
        {
            if (arr[i][b] == c)
            {
                for (int j = a + 1; j < i; j++)
                    arr[j][b] = c;
                break;
            }
            else if (arr[i][b] == '+')
                break;
        }

        for (int i = a - 1; i >=0; i--)//위 체크
        {
            if (arr[i][b] == c)
            {
                for (int j = a - 1; j > i; j--)
                    arr[j][b] = c;
                break;
            }
            else if (arr[i][b] == '+')
                break;
        }


        for (int i = b - 1; i >= 0; i--)//왼쪽 체크
        {
            if (arr[a][i] == c)
            {
                for (int j = b - 1; j > i; j--)
                    arr[a][j] = c;
                break;
            }
            else if (arr[a][i] == '+')
                break;
        }

        for (int i = b + 1; i < 8; i++)//오른쪽 체크
        {
            if (arr[a][i] == c)
            {
                for (int j = b + 1; j < i; j++)
                    arr[a][j] = c;
                break;
            }
            else if (arr[a][i] == '+')
                break;
        }
        
        //오른쪽 위
        a = originpos_a;
        b = originpos_b;
        while ((a-- > 0) && (b++ < 7))
        {
            if (arr[a][b] == c)
            {
                while (a != originpos_a)
                    arr[a++][b--] = c;
                break;
            }
            else if (arr[a][b] == '+')
                break;
        }
               
        //오른쪽 아래
        a = originpos_a;
        b = originpos_b;
        while ((a++ < 7) && (b++ < 7))
        {
            if (arr[a][b] == c)
            {
                while (a != originpos_a)
                    arr[a--][b--] = c;
                break;
            }
            else if (arr[a][b] == '+')
                break;
        }
                
        
        //왼쪽 위
        a = originpos_a;
        b = originpos_b;
        while ((a-- > 0) && (b --> 0))
        {
            if (arr[a][b] == c)
            {
                while (a != originpos_a)
                    arr[a++][b++] = c;
                break;
            }
            else if (arr[a][b] == '+')
                break;
        }

        //왼쪽 아래
        a = originpos_a;
        b = originpos_b;
        while ((a++ < 7) && (b-- >0))
        {
            if (arr[a][b] == c)
            {
                while (a != originpos_a)
                    arr[a--][b++] = c;
                break;
            }
            else if (arr[a][b] == '+')
                break;
        }
        if (c == 'X')
            c = 'O';
        else
            c = 'X';

       

    }
    int b = 0;
    int w = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (arr[i][j] == 'O')
                w++;
            else if (arr[i][j] == 'X')
                b++;
        }
    //출력
    cout << b << " " << w << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << arr[i][j];
        cout << endl;
    }
 
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
        cal();
    return 0;
}