/***********************
20203152 ÃÖÁ¤¹Î Ã¹¿ø¼Ò ¾îÂ¼±¸ 10/09
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;
void Part(short int arr[],int len)
{
    int l = arr[0];
    int cnt = 1;
    int tmp_cnt = 1;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < l)
        {
            l = arr[i];
            tmp_cnt = 1;
        }
        else
        {
            tmp_cnt++;
            if (cnt < tmp_cnt)
                cnt = tmp_cnt;
        }

    }
    cout << cnt << "\n";
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int len;
        cin >> len;
        short int arr[1000];
        for (int i = 0; i < len; i++)
        {
            int n;
            cin >> n;
            arr[i] = n;
        }
        Part(arr,len);
    }
    return 0;
}
