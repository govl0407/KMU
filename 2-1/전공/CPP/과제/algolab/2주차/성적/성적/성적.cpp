/*
¼ºÀû by 20203152 ÃÖÁ¤¹Î - 23.04.05
*/
#include<iostream>
using namespace std;

void grading(int n)
{
    int A = 0, B = 0, C = 0, D=0, F = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        switch (k / 10)
        {

        case 10:
        case 9:
            A++;
            break;
        case 8:
            B++;
            break;
        case 7:
            C++;
            break;
        case 6:
            D++;
            break;
        default:
            F++;
        }
    }
    cout << A << ' ' << B << ' ' << C << ' ' << D << ' ' << F << ' ' << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int nums;
        cin >> nums;
        grading(nums);
    }

    return 0;
}