#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct
{
    char data[N];
    int top;

}StackType;

int isEmpty(StackType *S)
{
    return (S->top == -1);
}
int isFull(StackType* S)
{
    return S->top == N - 1;
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
char peek(StackType *S)
{

    if (isEmpty(S))
    {
        printf("empty\n");
        return -1;
    }
    return S->data[S->top];
}
void init(StackType *S)
{
    S->top = -1;

}
void print(StackType* S)
{
    for (int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

int main()
{
    StackType S;
    init(&S);
    push(&S, 'C'); push(&S, 'A'); push(&S, 'T');
    print(&S);
    printf("pop : %c\n" ,pop(&S));
    return 0;
}