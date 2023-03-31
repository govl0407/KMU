#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct //���� ����ü
{
    char data[N];
    int top;

}StackType;

int isEmpty(StackType* S)//������ ������� �˻�
{
    return (S->top == -1);
}
int isFull(StackType* S)//������ �� á���� �˻�
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
void init(StackType* S)//�ʱ�ȭ
{
    S->top = -1;

}
void print(StackType* S)//���
{
    for (int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

//ȸ�� �Ǵ�
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
    if (n % 2 == 1)//str�� Ȧ����
    {

    }
    else //str�� ¦����
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