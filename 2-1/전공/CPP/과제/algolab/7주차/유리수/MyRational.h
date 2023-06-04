#ifndef _MYRATIONAL_H_ 
#define _MYRATIONAL_H_ 
#include <iostream> 
using namespace std;
class myRational
{
public:
    myRational(long num = 0, long den = 1);//������
    myRational(const myRational& r);
    long getNumerator() const;//������
    long getDenominator() const;

    myRational irreducible(long num, long den);//���м�
    myRational reciprocal(const myRational& r) const;//����
    //��Ģ����
    myRational operator +(const myRational& r) const;
    myRational operator +(int n) const;
    friend myRational operator +(int n, const myRational& r);
    myRational& operator +=(const myRational& r);
    myRational& operator +=(int n);

    myRational operator -(const myRational& r) const;
    myRational operator -(int n) const;
    friend myRational operator -(int n, const myRational& r);
    myRational& operator -=(const myRational& r);
    myRational& operator -=(int n);

    myRational operator *(const myRational& r) const;
    myRational operator *(int n) const;
    friend myRational operator *(int n, const myRational& r);
    myRational& operator *=(const myRational& r);
    myRational& operator *=(int n);

    myRational operator /(const myRational& r) const;
    myRational operator /(int n) const;
    friend myRational operator /(int n, const myRational& r);
    myRational& operator /=(const myRational& r);
    myRational& operator /=(int n);

    ///////////////////////////////////////////////pre, post
    myRational& operator ++(); // post++
    myRational operator ++(int); // ++pre
    myRational& operator --(); // post--
    myRational operator --(int); // pre--
    myRational operator -();

    /////////////////////////////////////////////////compare
    bool operator ==(const myRational& r) const;
    bool operator !=(const myRational& r) const;
    bool operator >(const myRational& r) const;
    bool operator <(const myRational& r) const;
    bool operator >=(const myRational& r) const;
    bool operator <=(const myRational& r) const;
private:
    // �м��� �׻� ���������� ���м��� ǥ���ϸ�, ���� �׻� _den>0 �̴�. long _num; // numerator 
    long _num;
    long _den; // denominator 
    long gcd(long m, long n); // �ִ�����
    void reduce();


    friend ostream& operator <<(ostream& outStream, const myRational& r);
    friend istream& operator >>(istream& inStream, myRational& r);
};
#endif