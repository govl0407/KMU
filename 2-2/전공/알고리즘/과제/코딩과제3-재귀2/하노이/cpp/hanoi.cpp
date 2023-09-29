/***********************
20203152 ������ �ϳ��� 09/27
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
    //�ϳ��� ���ܰ� -> �̵� -> ��ó��,
    //k<=���ܰ� ����Ƚ�� => ���ܰ� �ϳ��� ����
    //k>���ܰ� ����Ƚ�� => k-���ܰ� ����Ƚ��, k=1 �̵� ���
    //k>���ܰ� ����Ƚ�� +1 => ��ó�� �ϳ��� ����
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