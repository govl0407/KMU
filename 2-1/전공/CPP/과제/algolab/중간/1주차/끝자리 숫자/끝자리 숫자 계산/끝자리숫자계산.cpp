/*20203152최정민// 1주차 과제 - 끝자리 숫자 계산*/

#include<iostream>

using namespace std;
void last()
{
    int N;
    cin >> N;
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        temp = temp % 10;
        ans = ans * temp % 10;
    }
    cout << ans << endl;
}
int main()
{
    int cases;
    cin >> cases;
    for (int j = 0; j < cases; j++)
    {
        last();
    }
    return 0;
}