/***********************
20203152 최정민 스트링 순열 09/27
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;

int permutation_cnt(char str[])
{
    int t = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int k;
        if(i%2==0){ k = int(str[i] - 'a');}
        else { k = int(str[i] - 'a')*-1; }
        t += k;
        cout << k << " ";
    }
    return t;
}
void permutation(char str[], int begin, int end)
{
    int i;
    int range = end - begin;
    if (range == 1)
    {
        cout << permutation_cnt(str) << " : ";
        for (int j = 0; str[j] != '\0'; j++)
        {
            cout << str[j];
        }
        cout << "\n";
    }

    else 
    {
        for (i = 0; i < range; i++) 
        { 
            swap(str[begin], str[begin + i]);
            permutation(str, begin + 1, end);
            swap(str[begin], str[begin + i]);
        } 
    }
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        char str[10];
        cin >> str;
        int len = 0;
        for (int i = 0; str[i]!='\0'; i++){len++;}
        //permutation(str,0,len);
        cout << permutation_cnt(str);
        cout << "\n";
    }
    return 0;
}
