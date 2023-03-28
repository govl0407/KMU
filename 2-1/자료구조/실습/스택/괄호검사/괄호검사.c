#include <stdio.h>
#inlcude <stdlib.h>


#define N 30

int check(StackType *S, char str[])
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
        else if(c == ')' || c == '}' || c == ']')
        {
            if (isEmpty(S))
                return 0;
            eles
                t = pop(&S);
                if((t=='{'&&c!='}')|| (t == '(' && c != ')')|| (t == '[' && c != ']')
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
    scanf("%s", str);
    if (check(str))
        printf("ok");
    else
        printf('NO');
    return 0;
}