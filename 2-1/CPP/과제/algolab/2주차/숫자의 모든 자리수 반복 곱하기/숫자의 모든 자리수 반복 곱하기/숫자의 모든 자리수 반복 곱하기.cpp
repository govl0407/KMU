/*
숫자의 모든 자리수 반복 곱하기 by 20203152 최정민 -23.04.05 doing
곱한 값이 int 범위를 벗어나는 문제
*/
#include<iostream>
using namespace std;
void multiple(int n)
{
    int num = n;
    unsigned long long int k = 1;
    if(num%10!=0)
        k = num%10;
    num /= 10;
    while (num > 10)
    {
        int z = num % 10;
        if (z != 0)
            k *= z;
        num /= 10;
    }
    int z = num % 10;
    if (z != 0)
        k *= z;
    if (k > 10)
        multiple(k);
    else
        cout << k << endl;
}
int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int num;
        cin >> num;
        multiple(num);
    }
    return 0;
}