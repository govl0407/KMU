/***********************
20203152 최정민 빠른 피보나치 09/23
***********************************/
#include<iostream>
using namespace std;
void mat(int A[], int B[], int C[])//행렬 곱 AxB = C
{
    int tmp[4];//결과를 저장할 임시 행렬
    tmp[0] = (A[0] * B[0] + A[1] * B[2])%1000;
    tmp[1] = (A[0] * B[1] + A[1] * B[3])%1000;
    tmp[2] = (A[0] * B[2] + A[2] * B[3])%1000;
    tmp[3] = (A[1] * B[2] + A[3] * B[3])%1000;    
    for (int i = 0; i < 4; i++) { C[i] = tmp[i]; }//C에 tmp를 덮어쓰기
}
void fast_mat(int x[], int re[], int n)//피보나치 빠른계산
{
    if (n == 1 || n==0) { for (int i = 0; i < 4; i++) { re[i] = x[i]; } }//1곱이면 그대로 리턴
    else if (n % 2 == 1)//홀수
    {
        int tmp[4];//임시 행렬
        fast_mat(x, tmp, (n - 1) / 2);//p(x,(n-1)/2)
        mat(tmp, tmp, tmp);//p(x,(n-1)/2) ^ 2
        mat(tmp , x, re); // x * p(x,(n-1)/2) ^ 2
    }
    else//짝수
    {
        int tmp[4];
        fast_mat(x, tmp, n / 2);//p(x,n/2)
        mat(tmp, tmp, re);//p(x,n/2) ^ 2
    }
}
int fast_fibo(int n)
{
    int A[4] = {1,1,1,0};
    int result[4];
    if (n == 0) { return n; }
    else
    {
        fast_mat(A, result ,n);
    }
    return result[1]%1000;
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        if (n == 0) { cout << 0; }
        else { cout << fast_fibo(n) % 1000; }
        cout << "\n";
    }
    return 0;
}
//2147483647