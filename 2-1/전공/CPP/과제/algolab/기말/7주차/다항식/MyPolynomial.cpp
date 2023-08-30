#include "MyPolynomial.h"
/********************* add your code here ********************************/
myPolynomial::myPolynomial(int c, unsigned e)
{
    degree = e;
    terms.push_back({myTerm(c,e)});
    reduce();
}
myPolynomial::myPolynomial(int nTerms, int mono[])
{
    degree = 0;
    for (int i = 0; i < nTerms; i++)
    {
        int a = mono[2*i];
        int b = mono[2*i + 1];
        if (b > degree)
            degree = b;
        terms.push_back(myTerm(a, b)); //����
    }
    reduce();
}
// copy constructor 
myPolynomial::myPolynomial(const myPolynomial& poly)
{
    degree = poly.degree;
    for (int i = 0; i < poly.terms.size(); i++)
    {
        terms.push_back(poly.terms[i]); //����
    }
    reduce();
}
// overloaded operators 
bool myPolynomial::operator == (const myPolynomial& poly) const
{
    for (int i = 0; i < terms.size(); i++)//�� ���Ҹ� ó������ ������ üũ
    {
        for (int j = 0; j < poly.terms.size(); j++)//poly�� ó������ ������ üũ
        {
            if (terms[i].exp == poly.terms[j].exp)//���� �¼��϶�
            {
                if (terms[i].coeff != poly.terms[j].coeff)// ����� �ٸ��� false
                    return 0;
                else//������ ���� �� ���� üũ
                    break;
            }
            if (j == poly.terms.size()-1) //������ ���Ƶ� ���� �¼��� ���� �� false
            {
                return 0;
            }
        }
    }
    return 1;// ���� ���Ƶ� false�� ���� �������� true
}
bool myPolynomial::operator != (const myPolynomial& poly) const
{
    return !(*this == poly);
}
myPolynomial myPolynomial::operator +(const myPolynomial& poly) const
{
    myPolynomial tmp;
    for (int i = 0; i < terms.size(); i++)//�� ���ҿ� ���ؼ�
    {
        bool found = false;
        for (int j = 0; j < poly.terms.size(); j++)//poly�� ���ҿ� ��
        {

            if (terms[i].exp == poly.terms[j].exp)//���� �¼��� ã����
            {
                tmp.terms.push_back({ terms[i].coeff + poly.terms[j].coeff, terms[i].exp });
                found = true;
                break;
            }
        }
        if (!found)
        {
            tmp.terms.push_back(terms[i]);
        }
    }//poly�� ���ҿ� ���ؼ�
    for (int j = 0; j < poly.terms.size(); j++)
    {
        bool found = false;
        for (int i = 0; i < terms.size(); i++)//�� ���� ��
        {
            if (terms[i].exp == poly.terms[j].exp)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            myTerm t = poly.terms[j];
            tmp.terms.push_back(t);
        }
    }
    tmp.reduce();
    return tmp;
}

myPolynomial myPolynomial::operator +(int a) const
{
    myPolynomial tmp = *this;//������ ���׽�
    tmp += a * (myPolynomial::ONE);
    return tmp;
}
myPolynomial operator +(int a, const myPolynomial& poly)
{
    myPolynomial tmp = poly + a;
    tmp.reduce();
    return tmp;
}
myPolynomial myPolynomial::operator -(const myPolynomial& poly) const
{
    myPolynomial tmp;
    for (int i = 0; i < terms.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < poly.terms.size(); j++)
        {   
            
            if (terms[i].exp == poly.terms[j].exp)
            {
                tmp.terms.push_back({ terms[i].coeff -poly.terms[j].coeff, terms[i].exp });
                found = true;
                break;
            }
        }
        if (!found)
        {
            tmp.terms.push_back(terms[i]);
        }
    }
    for (int j = 0; j < poly.terms.size(); j++)
    {
        bool found = false;
        for (int i = 0; i < terms.size(); i++)
        {
            if (terms[i].exp == poly.terms[j].exp)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            myTerm t = poly.terms[j];
            t.coeff *= -1;
            tmp.terms.push_back(t);
        }
    }
    tmp.reduce();
    return tmp;
}

myPolynomial myPolynomial::operator -(int a) const
{
    myPolynomial tmp = *this;//������ ���׽�
    tmp -= a * (myPolynomial::ONE);
    return tmp;
}
myPolynomial operator -(int a, const myPolynomial& poly)
{
    myPolynomial tmp = (poly - a);
    tmp.reduce();
    return tmp;
}
myPolynomial myPolynomial::operator *(const myPolynomial& poly) const
{
    myPolynomial tmp;
    for (int i = 0; i < terms.size(); i++)
    {
        for (int j = 0; j < poly.terms.size(); j++)
        {
            myTerm t(terms[i].coeff * poly.terms[j].coeff, terms[i].exp + poly.terms[j].exp);
            bool chk = true;
            for (int n = 0; n < tmp.terms.size(); n++)
            {
                if (tmp.terms[n].exp == t.exp)
                {
                    chk = false;
                    tmp.terms[n].coeff += t.coeff;
                    break;
                }
            }
            if (chk)
            {
                tmp.terms.push_back(t);
            }
        }
    }
    tmp.reduce();
    return tmp;
}

myPolynomial myPolynomial::operator *(int k) const
{
    myPolynomial tmp = *this;
    for (int i = 0; i < tmp.terms.size(); i++)//��� �׿� k ����
    {
        tmp.terms[i].coeff *= k;
    }
    tmp.reduce();
    return tmp;
}
myPolynomial& myPolynomial::operator += (const myPolynomial& poly)
{
    myPolynomial tmp = *this + poly;
    tmp.reduce();
    *this = tmp;
    return *this;
}
myPolynomial& myPolynomial::operator -= (const myPolynomial& poly)
{
    myPolynomial tmp = *this - poly;
    tmp.reduce();
    *this = tmp;
    return *this;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial& poly)
{
    myPolynomial tmp = *this * poly;
    tmp.reduce();
    *this = tmp;
    return *this;
}
myPolynomial& myPolynomial::operator *= (int k)
{
    myPolynomial tmp = *this * k;
    tmp.reduce();
    *this = tmp;
    return *this;
}
myPolynomial myPolynomial::operator -() const
{
    myPolynomial tmp;
    myTerm t;
    for (int i = 0; i < terms.size(); i++)//����׿� -����
    {
        t.coeff = -tmp.terms[i].coeff;
        t.exp = tmp.terms[i].exp;
        tmp.terms.push_back(t);
    }
    tmp.reduce();
    return tmp;
}

long myPolynomial::operator() (int x) const // evaluate the polynomial 
{
    long ans = 0;
    for (int i = 0; i < terms.size(); i++)//�ƹ�ư ���
    {
        int k = 1;
        for (unsigned j = 0; j < terms[i].exp; j++)
            k *= x;
        ans += terms[i].coeff * k;
    }
    return ans;
}
int myPolynomial::getDegree() const // get a degree of the polynomial 
{
    return degree;
}
int myPolynomial::getNumTerms() const// number of terms in the polynomial 
{
    return (*this).terms.size();
}
myPolynomial myPolynomial::ddx() const// derivative of a polynomial 
{
    myPolynomial tmp = *this;
    for (int i = 0; i < tmp.terms.size(); i++)//�̺�
    {
        if (tmp.terms[i].exp != 0)
        {
            tmp.terms[i].coeff *= tmp.terms[i].exp;
            tmp.terms[i].exp--;
        }
        else//��� �̺��ϸ� coeff 0���� ����
            tmp.terms[i].coeff = 0;
    }
    tmp.reduce();
    return tmp;
}
// friend operators and functions 
myPolynomial operator *(int k, const myPolynomial& poly)
{
    myPolynomial tmp = poly * k;
    tmp.reduce();
    return tmp;
}

// output operator 
ostream& operator <<(ostream& outStream, const myPolynomial& poly)
{
    for (int i = 0; i < poly.terms.size(); i++)
    {
        
        if (poly.terms[i].exp > 0)//������ 1���� Ŭ��
        {
            if (poly.terms[i].coeff == 1)//����� 1�̸�
                outStream << "x";
            else if (poly.terms[i].coeff == -1)
                outStream << "-x";
            else // ����� 1�� �ƴҶ�
                outStream << poly.terms[i].coeff << "x";
            if(poly.terms[i].exp !=1 )
                outStream << "^" << poly.terms[i].exp; //x ���� �ٿ���
        }
        else
            outStream << poly.terms[i].coeff;
        if (i != poly.terms.size() - 1 && poly.terms[i+1].coeff>0)
            outStream << "+";
    }

    /********************* add your code here ********************************/
    return outStream;
}
myPolynomial myPolynomial::operator -()
{
    myPolynomial tmp;
    for (int i = 0; i < terms.size(); i++)
    {
        myTerm t(-1 * terms[i].coeff, terms[i].exp);
        tmp.terms.push_back(t);
    }
    tmp.reduce();
    return tmp;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0 
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1 
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x
void myPolynomial::reduce()
{
    vector<myTerm> tmp;
    for (int i = 0; i < terms.size(); i++)//����� 0�� �� ����
    {
        if (terms[i].coeff != 0)
        {
            myTerm t;
            t = terms[i];
            tmp.push_back(t);
        }
    }
    for (int i = 0; i < tmp.size(); i++)//��������
    {
        myTerm max = tmp[i];
        int k = i;
        for (int j = i; j < tmp.size(); j++)
        {
            if (tmp[j].exp > max.exp)
            {
                max = tmp[j];
                k = j;
            }
        }
        tmp[k] = tmp[i];
        tmp[i] = max;

    }
    terms = tmp;
    if (terms.size() == 0)
    {
        terms.push_back(myTerm(0, 0));
    }
    degree = terms[0].exp;
}