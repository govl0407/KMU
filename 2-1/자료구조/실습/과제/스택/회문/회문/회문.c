#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct //스택 구조체
{
    char data[N];
    int top;

}StackType;

int isEmpty(StackType* S)//스택이 비었는지 검사
{
    return (S->top == -1);
}
int isFull(StackType* S)//스택이 꽉 찼는지 검사
{
    return (S->top == N - 1);
}

void push(StackType* S, char c)//PUSH
{
    if (isFull(S))
        printf("Full\n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType* S)//POP
{
    if (isEmpty(S))
    {
        printf("empty\n");
        return -1;
    }
    else {
        char k;
        k = S->data[S->top];
        S->top--;
        return k;
    }
}
char peek(StackType* S)//PEEK
{

    if (isEmpty(S))
    {
        printf("empty\n");
        return -1;
    }
    return S->data[S->top];
}
void init(StackType* S)//초기화
{
    S->top = -1;

}
void print(StackType* S)//출력
{
    for (int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

//회문 판단
void palindrome(char k[])
{
    StackType S;
    init(&S);
    int n = strlen(k);
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        push(&S, k[i]);
    }
    if (n % 2 == 1)//str이 홀수개
    {

    }
    else //str이 짝수개
    {
        for (int j = mid; j < n; j++)
        {
            if (pop(&S) != k[j])
            {
                printf("NOT PALINDROME");
                break;
            }
        }
        printf("PALINDROME");
    }
}

int main()
{
    char Str[N];
    scanf("%s", Str);
    palindrome(Str);
    return 0;
}