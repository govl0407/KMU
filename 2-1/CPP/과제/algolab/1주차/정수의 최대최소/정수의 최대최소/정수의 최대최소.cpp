/*20203152������// 1���� ���� - ������ �ִ� �ּ�*/

#include<iostream>
#include<climits>
using namespace std;

int main() {

    

    int cases;
    cin >> cases;
    for (int j = 0; j < cases; j++)
    {
        int N;
        cin >> N;

        int Max = INT_MIN;
        int Min = INT_MAX;

        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            if (num > Max)
            {
                Max = num;
            }
            if (num < Min)
            {
                Min = num;
            }
        }

        cout << Max << ' ' << Min << endl;
    }

    return 0;
}