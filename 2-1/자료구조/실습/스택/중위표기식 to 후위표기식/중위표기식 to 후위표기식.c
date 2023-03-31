#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

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
int evaluate(char exp[]) //후위표기식 계산
{
    StackType S;
    init(&S);

    int op1, op2, value;
    char c;

    int n = strlen(exp);
    for (int i = 0; i < n; i++)
    {
        c = exp[i];
        if (c != '+' && c != '-' && c != '*' && c != '/')
        {
            value = c - '0';
            push(&S, value);
        }
        else
        {
            op2 = pop(&S);
            op1 = pop(&S);
            switch (c)
            {
            case '+':
                push(&S, op1 + op2);
                break;

            case '-':
                push(&S, op1 - op2);
                break;

            case '*':
                push(&S, op1 * op2);
                break;

            case '/':
                push(&S, op1 / op2);
                break;
            }
        }
    }
    return pop(&S);

}

int prec(char op)
{
    switch (op)
    {
        case '(': case')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
}

void convert(char exp[])
{
    StackType S;
    init(&S);
    char c, t;
    int n = strlen(exp);
    
    for (int i = 0; i < n; i++)
    {
        c = exp[i];
        switch(c)
        {
            case '+':
            case '-':
            case '/':
            case '*':
                while (!isEmpty(&S)&& prec(c) <=prec(peek(&S)))
                {
                    printf("%c", pop(&S));
                }
                push(&S, c);
                break;

            case '(':
                push(&S, c);
                break;

            case ')':
                t = pop(&S);
                while (t != '(')
                {
                    printf("%c", t);
                    t = pop(&S);
                }
                break;
               
            default :
                push(&S, c);
                break;
            }
    }

    while (!isEmpty(&S))
        printf("%c", pop(&S));
    printf("\n");
}



int main()
{
    char exp[N];
    scanf("%s", exp);
    
    convert(exp);
    convert(infix, postfix);
    printf("%d\n", evaluate(postfix));

    return 0;
}