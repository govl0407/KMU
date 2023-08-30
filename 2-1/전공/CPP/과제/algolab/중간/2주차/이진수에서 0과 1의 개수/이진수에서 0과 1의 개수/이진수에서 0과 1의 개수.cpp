/*
이진수에서 0과 1의 개수 by 20203152 최정민 - 23.04.05
*/

#include<iostream>
#include<fstream>
using namespace std;

void many_bit(unsigned int n)
{
    int bit_0 = 0; //0bit
    int bit_1 = 1; //1bit
    while (n != 1)
    {
        if (n % 2 == 0)
            bit_0++;
        else
            bit_1++;

        n /= 2;
    }
    cout << bit_0 << ' ' << bit_1 << endl; 
}

int main()
{
    
    ifstream fin;
    fin.open("input.txt");//파일 열기

    int cases;
    fin >> cases; //case 개수 받기
    
    for (int i = 0; i < cases; i++)
    {
        unsigned int n;
        fin >> n; //한줄씩 받기
        
        many_bit(n);//함수 실행
    }

    return 0;
}
