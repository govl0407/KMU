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

int prec(char op)//우선순위 검사
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

void convert_print(char exp[])//중위표기식을 후기표기식으로 변환
{
    StackType S;
    init(&S);
    char c, t;
    int n = strlen(exp);

    for (int i = 0; i < n; i++)
    {
        c = exp[i];
        switch (c)
        {
        case '+':
        case '-':
        case '/':
        case '*':
            while (!isEmpty(&S) && prec(c) <= prec(peek(&S)))
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

        default:
            push(&S, c);
            break;
        }
    }

    while (!isEmpty(&S))
        printf("%c", pop(&S));
    printf("\n");
}

void convert(char infix[],char postfix[])//infix를 변환해서 postfix에 저장
{
    StackType S;
    init(&S);
    char c, t;
    int n = strlen(infix);
    
    int z = 0;

    for (int i = 0; i < n; i++)
    {
        c = infix[i];
        switch (c)
        {
        case '+':
        case '-':
        case '/':
        case '*':
            while (!isEmpty(&S) && prec(c) <= prec(peek(&S)))
            {
                postfix[z] = pop(&S);
                printf("%c ", postfix[z]);
                z++;
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
                postfix[z] = t;
                printf("%c ", postfix[z]);
                z++;
                t = pop(&S);
            }
            break;

        default:
            push(&S, c);
            break;
        }
    }

    while (!isEmpty(&S))
        char k = pop(&S);
        postfix[z] = k;
        printf("%c ", postfix[z]);
        z++;
    printf("\n");
}
void printfix(char fix[],int leng)
{
    for (int i = 0; i < leng; i++)
        printf("%c ", fix[i]);
}

int main()
{
    //char exp[N];
    //scanf("%s", exp);
    //convert_print(exp);



    char infix[N], postfix[N];
    scanf("%s", infix);
    int lengthes = strlen(infix);
    convert(infix, postfix);
    printfix(postfix, lengthes);
    
    //printf("%d\n", evaluate(postfix));

    return 0;
}