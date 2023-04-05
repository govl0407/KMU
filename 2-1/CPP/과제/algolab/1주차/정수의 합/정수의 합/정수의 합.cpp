#include<iostream>

using namespace std;
int main()
{
    int cases;
    cin >> cases;
    for (int j=0; j < cases; j++) 
    {
        int ans = 0;
        int N;
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            ans += num;
        }
        cout << ans << endl;
    }
       

    return 0;
}