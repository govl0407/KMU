#include <iostream>
using namespace std;

int room()
{
    int n;
    cin >> n;
    int start[100];//시작시간
    int end[100];//끝나는 시간
    for (int i = 0; i < n; i++)
    {
        cin >> start[i] >> end[i];
    }
    int endtime = 1000;
    
    int dis_num = -1;
    int cnt = 1;      
    for (int i = 0; i < n; i++)
    {
        if (endtime > end[i])
        {
            endtime = end[i];
            dis_num = i;
        }
    }
    for(int j=0;j<n;j++)
    {
        int chk = 0;
  
        int endmin = 1000;
        for (int i = 0; i < n; i++)
        {
            if (start[i] > endtime && endmin>end[i])//앞 이후회의 중 가장 빨리 끝나는 거 선택
            {
                endmin = end[i];
                chk=1;
            }
        }
        if (chk==1)
        {
            endtime = endmin;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        cout << room() << "\n";
    }
    return 0;
}