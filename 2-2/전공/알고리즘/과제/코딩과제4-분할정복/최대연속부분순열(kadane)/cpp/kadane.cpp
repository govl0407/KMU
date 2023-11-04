/***********************
20203152 최정민 최대연속부분순열 10/12 시간초과 ? 어디서??
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
        if (arr[i] == 0)//최소구간을 위해 0은 스킵
            continue;

        if (arr[i] > sum + arr[i])
            start_tmp = i;//새로운 수열의 시작
        sum = Max(arr[i], sum + arr[i]);//현재 수열의 합
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
