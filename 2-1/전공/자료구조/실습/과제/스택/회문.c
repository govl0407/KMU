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
int Stack_length(StackType* S)
{
    return S->top;
}

//ȸ�� �Ǵ�
void palindrome(char k[])
{
    StackType A;
    init(&A);
    StackType B;
    init(&B);
    int n = strlen(k);
    for (int i = 0; i < n; i++)//���ڿ��� �ǵ��ؼ� ���� �ҹ��ڷ� ���� ���ÿ� ����
    {
        if (k[i] != ' ')//���� ����
        {
            if ('A' <= k[i] && k[i] <= 'Z')//�빮�ڸ� �ҹ��ڷ� ����� push
            {
                char c = k[i] + 32;
                push(&A, c);
            }
            else if ('a' <= k[i] && k[i] <= 'z')//�ҹ��ڸ� push
            {
                char c = k[i];
                push(&A, c);
            }
        }

    }
    int leng = Stack_length(&A)+1;//�� ������ ����
    int mid = leng / 2;
    for (int i = 0; i < mid; i++)
    {
        push(&B, pop(&A));//B���ÿ� �� ������ ä������
    }

    if (leng % 2 == 1)
        char trash = pop(&A);//���̰� Ȧ���� �߰��� ����

    for (int i = 0; i < mid; i++)//A,B�� ���ؼ� ���� �ٸ����̸� not palindrome ���
    {
        char a = pop(&A);
        char b = pop(&B);
        if (a != b)
        {
            printf("not Palindrome");
            break;
        }
        if (i == mid - 1)//������ �����ϸ� ȸ��
            printf("palindrome");
    }
    //������ ���� B�� �ְ� ������ ������ Ȧ����� �߰����� ������ A,B������ pop �ϸ鼭 ��
}

int main()
{
    char Str[N];
    gets(Str);
    palindrome(Str);
    return 0;
}