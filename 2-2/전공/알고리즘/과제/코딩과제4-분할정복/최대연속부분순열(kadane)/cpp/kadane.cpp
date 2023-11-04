/***********************
20203152 ������ �ִ뿬�Ӻκм��� 10/12 �ð��ʰ� ? ���??
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;
int Max(int a, int b)
{
    int r;
    (a > b) ? r = a : r = b;
    return r;
}
void kadane(int arr[], int len)
{
    int sum = 0;
    int max =0;
    int start = -1;
    int start_tmp = 0;
    int end = -1;
    for (int i = 0; i <= len; i++) {
        if (arr[i] == 0)//�ּұ����� ���� 0�� ��ŵ
            continue;

        if (arr[i] > sum + arr[i])
            start_tmp = i;//���ο� ������ ����
        sum = Max(arr[i], sum + arr[i]);//���� ������ ��
        if (sum > max)
        {
            end = i;
            start = start_tmp ;
        }
        max = Max(sum, max);
    }
    cout << max <<" "<< start << " "<< end << "\n";
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int len;
        cin >> len;
        int arr[100];
        for (int i = 0; i < len; i++)
        {
            int m;
            cin >> m;
            arr[i] = m;
        }
        kadane(arr, len - 1);
    }
    return 0;
}
