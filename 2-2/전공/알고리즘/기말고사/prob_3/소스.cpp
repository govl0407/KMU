#include <iostream>
using namespace std;
int M[101];
int bag()
{
    M[0] = 0;
    int n;
    int resource;
    cin >> n >> resource;
    int amount[100], price[100];
    for (int i = 1; i <= n; i++)
        cin >> amount[i] >> price[i];

    //dp« ø‰
    for (int i = 1; i <= resource; i++)
    {
        int max_price = 0;
        M[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i >= amount[j])
            {
                if (max_price < M[i - amount[j]] + price[j])
                {
                    max_price = M[i - amount[j]] + price[j];
                }
            }
        }
        M[i] = max_price;
    }
    return M[resource];

}
int main()
{
    int N;
    cin >> N;
    while(N--)
        cout << bag()<<"\n";

    return 0;
}