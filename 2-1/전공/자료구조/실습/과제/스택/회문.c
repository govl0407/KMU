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
int Stack_length(StackType* S)
{
    return S->top;
}

//회문 판단
void palindrome(char k[])
{
    StackType A;
    init(&A);
    StackType B;
    init(&B);
    int n = strlen(k);
    for (int i = 0; i < n; i++)//문자열을 판독해서 전부 소문자로 만들어서 스택에 넣음
    {
        if (k[i] != ' ')//공백 예외
        {
            if ('A' <= k[i] && k[i] <= 'Z')//대문자면 소문자로 만들고 push
            {
                char c = k[i] + 32;
                push(&A, c);
            }
            else if ('a' <= k[i] && k[i] <= 'z')//소문자면 push
            {
                char c = k[i];
                push(&A, c);
            }
        }

    }
    int leng = Stack_length(&A)+1;//총 문자의 갯수
    int mid = leng / 2;
    for (int i = 0; i < mid; i++)
    {
        push(&B, pop(&A));//B스택에 뒤 절반을 채워넣음
    }

    if (leng % 2 == 1)
        char trash = pop(&A);//길이가 홀수면 중간값 버림

    for (int i = 0; i < mid; i++)//A,B를 비교해서 서로 다른값이면 not palindrome 출력
    {
        char a = pop(&A);
        char b = pop(&B);
        if (a != b)
        {
            printf("not Palindrome");
            break;
        }
        if (i == mid - 1)//끝까지 도착하면 회문
            printf("palindrome");
    }
    //절반을 스택 B에 넣고 문자의 갯수가 홀수라면 중간값은 버리고 A,B스택을 pop 하면서 비교
}

int main()
{
    char Str[N];
    gets(Str);
    palindrome(Str);
    return 0;
}