#ifndef _MYRATIONAL_H_ 
#define _MYRATIONAL_H_ 
#include <iostream> 
using namespace std;
class myRational
{
public:
    myRational(long num = 0, long den = 1);//생성자
    myRational(const myRational& r);
    long getNumerator() const;//접근자
    long getDenominator() const;

    myRational irreducible(long num, long den);//기약분수
    myRational reciprocal(const myRational& r) const;//역수
    //사칙연산
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
    // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator 
    long _num;
    long _den; // denominator 
    long gcd(long m, long n); // 최대공약수
    void reduce();


    friend ostream& operator <<(ostream& outStream, const myRational& r);
    friend istream& operator >>(istream& inStream, myRational& r);
};
#endif