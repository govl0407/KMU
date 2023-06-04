#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 30

typedef struct
{
    char data[N];
    int top;

}StackType;

int isEmpty(StackType* S)
{
    return (S->top == -1);
}
int isFull(StackType* S)
{
    return (S->top == N - 1);
}

void push(StackType* S, char c)
{
    if (isFull(S))
        printf("Full\n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType* S)
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
char peek(StackType* S)
{

    if (isEmpty(S))
    {
        printf("empty\n");
        return -1;
    }
    return S->data[S->top];
}
void init(StackType* S)
{
    S->top = -1;

}
void print(StackType* S)
{
    for (int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}


int check(StackType* S, char str[])
{

    char c, t;
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        c = str[i];

        if (c == '(' || c == '{' || c == '[')
        {
            push(S, c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (isEmpty(S))
                return 0;
            else
                t = pop(S);
            if ((t == '{' && c != '}') || (t == '(' && c != ')') || (t == '[' && c != ']'))
                return 0;
        }
    }
    return isEmpty(S);
}

int main()
{
    StackType S;
    init(&S);
    char str[N];
    scanf("%s", &str);
    if (check(&S, str))
        printf("ok");
    else
        printf("NO");
    return 0;
}