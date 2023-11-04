/***********************
20203152 최정민 스트링 순열 10/03
***********************************/
#include<iostream>
#define swap(a, b) {char t = a; a = b; b = t;}
using namespace std;
int cnt;
int permutation_cnt(char str[])
{
    int t = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int k;
        if(i%2==0){ k = int(str[i] - 'a');}
        else { k = int(str[i] - 'a')*-1; }
        t += k;
    }
    return t;
}
void permutation(char str[], int begin, int end)
{
    int i;
    int range = end - begin;
    if (range == 1)
    {
        int k =permutation_cnt(str);
        if (k > 0) { cnt++; }
        
    }

    else 
    {
        for (i = 0; i < range; i++) 
        { 
            swap(str[begin], str[begin + i]); for (int i = 0; i < end; i++)
                cout << str[i];
            cout << "\n";
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
        cnt = 0;
        permutation(str,0,len);
        cout << cnt <<"\n";
    }
    return 0;
}
