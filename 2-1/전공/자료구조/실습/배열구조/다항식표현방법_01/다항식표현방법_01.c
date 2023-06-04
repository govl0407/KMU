#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef struct
{
    int degree;
    float coef[N];

}Poly;
void printPoly(Poly P)
{
    int i, j;
    for(i=0, j=P.degree; i<=P.degree; i++, j--)
    {
        printf("%2dx^%d + ", P.coef[i], j);
    }
    printf("\b\b  \n");
}
Poly addPoly(Poly A, Poly B)
{
    Poly C;

    int Apos = 0, Bpos = 0, Cpos = 0;
    int degA = A.degree;
    int degB = B.degree;

    C.degree = (degA >= degB) ? degA : degB;

    while (Apos < A.degree && Bpos <= B.degree)
    {
        if (degA > degB)
        {
            C.coef[Cpos] = A.coef[Apos];
            Apos++; Cpos++; degA--;
        }
        else if (degA == degB)
        {
            C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
            Apos++; Cpos++; degA--; degB--;
        }
        else
        {
            C.coef[Cpos] = B.coef[Bpos];
            Bpos++; Cpos++; degB--;
            
        }
    }
    return C;
}
int main() {
    Poly a, b, c;
    
    scanf_s("%d", &a.degree);

    for (int i = 0; i <= a.degree; i++)
        scanf_s("%d", &a.coef[i]);


    scanf_s("%d", &b.degree);
    for (int i = 0; i <= b.degree; i++)
        scanf_s("%d", &b.coef[i]);

    printPoly(a);
    printPoly(b); 

    c = addPoly(a, b);

    printPoly(c);
    //Poly a = { 5,{10,0,0,0,6,3} };

    return 0;
}
