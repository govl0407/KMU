/************
20203152 ������ ������
3
11 4 5 6 11 10 9 2 8 3 7 1
5 1 2 3 4 5
7 5 7 2 6 3 1 4
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
void chk(int team[], int arr[], int pos)
{
    int next = arr[pos];
    if (next == pos)//������ ����ų�� ����
    {
        team[pos] = cnt;
        cnt++;
        return;
    }
    else if (team[next] == cnt)//������ �������϶� ����
    {
        team[pos] = cnt;
        cnt++;
        return;
    }
    else//����Ű�� ���� ���� �� �̸����� ����
    {
        team[pos] = cnt;
        chk(team, arr, next);
    }
}
void teaming(int arr[],int len)
{
    int result = 0;
    int team[100] = {0};
    for (int i = 0; i < len; i++)
    {
        chk(team, arr, i);
    }
    int teamlist[100] = {0};
    for (int i = 0; i < len; i++)//�� �� ����
    {
        teamlist[team[i]] = 1;
    }
    for (int i = 0; i < len; i++)
        if (teamlist[i] == 1)
            result++;
    cout << result << "\n";

}

int main() {
    int n;
    cin >> n;
    int arr[100];
    while (n--)
    {
        int num;
        cin >> num;
        cnt = 0;
        for (int i = 0; i < num; i++)
        {
            int k;
            cin >> k;
            arr[i] = --k;
        }
        teaming(arr, num);
        
    }
    
}
