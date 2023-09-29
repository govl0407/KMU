/***********************
20203152 최정민 하노이 09/27
***********************************/
#include<iostream>
using namespace std; 

unsigned long long int fast_power(int x, int n)
{
    if (n == 0) { return 1; }
    else if (n % 2 == 0)
    {
        unsigned long long int k = fast_power(x, n / 2);
        return (k * k);
    }
    else
    {
        unsigned long long int k = fast_power(x, (n - 1) / 2);
        k = (k * k);
        return (x * k);
    }
}

unsigned long long int k;
void hanoi_cnt(int n, int source, int target, int tmp);
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n >> k;
        hanoi_cnt(n, 1, 3, 2);
        cout << "\n";
    }
    return 0;
}

void hanoi_cnt(int n, int source, int target, int tmp)
{
    //하노이 전단계 -> 이동 -> 후처리,
    //k<=전단계 수행횟수 => 전단계 하노이 실행
    //k>전단계 수행횟수 => k-전단계 수행횟수, k=1 이동 출력
    //k>전단계 수행횟수 +1 => 후처리 하노이 실행
    if (n > 0)
    {
        unsigned long long int t = fast_power(2, n - 1) - 1;
        if (k <= t)
        {
            hanoi_cnt(n - 1, source, tmp, target);
        }
        else
        {
            k -= t;
            if(k==1){ cout << source << " " << target; }
            else {
                k--;
                hanoi_cnt(n - 1, tmp, target, source);
            }
        }
    }
}