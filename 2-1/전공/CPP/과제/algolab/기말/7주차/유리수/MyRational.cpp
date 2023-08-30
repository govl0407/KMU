#include "MyRational.h"
myRational::myRational(long num, long den)//생성자
{
    _num = num;
    _den = den;
    this->reduce();
}
myRational::myRational(const myRational& r)
{
    myRational tmp(r._num, r._den);
    tmp.reduce();
    _num = tmp._num;
    _den = tmp._den;
}

long myRational::getNumerator() const//접근자
{
    return _num;
}
long myRational::getDenominator() const
{
    return _den;
}

//durtn
myRational myRational::reciprocal(const myRational& r) const
{
    myRational tmp = r;
    tmp.reduce();
    return tmp;
}
//사칙연산
myRational myRational::operator +(const myRational& r) const
{
    long new_num = _num * r._den + r._num * _den;
    long new_den = _den * r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator +(int n) const
{
    long new_num = _num + n * _den;
    long new_den = _den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational operator +(int n, const myRational& r)
{
    long new_num = r._num + n * r._den;
    long new_den = r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational& myRational::operator +=(const myRational& r)
{
    long new_num = this->_num * r._den + r._num * this->_den;
    long new_den = this->_den * r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}
myRational& myRational::operator +=(int n)
{
    long new_num = this->_num + n * this->_den;
    long new_den = this->_den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}

myRational myRational::operator -(const myRational& r) const
{
    long new_num = _num * r._den - r._num * _den;
    long new_den = _den * r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator -(int n) const
{
    long new_num = _num - n * _den;
    long new_den = _den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational operator -(int n, const myRational& r)
{
    long new_num = n * r._den - r._num;
    long new_den = r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational& myRational::operator -=(const myRational& r)
{
    long new_num = this->_num * r._den - r._num * this->_den;
    long new_den = this->_den * r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}
myRational& myRational::operator -=(int n)
{
    long new_num = this->_num - n * this->_den;
    long new_den = this->_den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}

myRational myRational::operator *(const myRational& r) const
{
    long new_num = _num * r._num;
    long new_den = _den * r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational myRational::operator *(int n) const
{
    long new_num = _num * n;
    myRational tmp = myRational(new_num, _den);
    tmp.reduce();
    return tmp;
}
myRational operator *(int n, const myRational& r)
{
    long new_num = r._num * n;
    long new_den = r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational& myRational::operator *=(const myRational& r)
{
    long new_num = this->_num * r._num;
    long new_den = this->_den * r._den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}
myRational& myRational::operator *=(int n)
{
    long new_num = this->_num * n;
    long new_den = this->_den;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}

myRational myRational::operator /(const myRational& r) const
{
    long new_num = _num * r._den;
    long new_den = _den * r._num;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}

myRational myRational::operator /(int n) const
{
    long new_den = _den * n;
    myRational tmp = myRational(_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational operator /(int n, const myRational& r)
{
    long new_num = r._den * n;
    long new_den = r._num;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    return tmp;
}
myRational& myRational::operator /=(const myRational& r)
{
    long new_num = this->_num * r._den;
    long new_den = this->_den * r._num;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}
myRational& myRational::operator /=(int n)
{
    long new_num = this->_num;
    long new_den = this->_den * n;
    myRational tmp = myRational(new_num, new_den);
    tmp.reduce();
    this->_num = tmp._num;
    this->_den = tmp._den;
    return *this;
}


//pre post
myRational& myRational::operator++()
{
    *this += 1;
    return *this;
}

myRational myRational::operator++(int) 
{
    myRational temp = *this;
    *this += 1;
    return temp;
}

myRational& myRational::operator--()
{
    *this -= 1;
    return *this;
}

myRational myRational::operator--(int)
{
    myRational temp = *this;
    *this = *this - 1;
    return temp;
}
// unary minus
myRational myRational::operator -()
{
    return myRational(-_num, _den);
}

bool myRational::operator ==(const myRational& r) const
{
    return (_num * r._den == r._num * _den);
}
bool myRational::operator !=(const myRational& r) const
{
    return !(*this == r);
}
bool myRational::operator >(const myRational& r) const
{
    return (_num * r._den > r._num * _den);
}
bool myRational::operator <(const myRational& r) const
{
    return (_num * r._den < r._num * _den);
}

bool myRational::operator >=(const myRational& r) const
{
    return (_num * r._den >= r._num * _den);
}
bool myRational::operator <=(const myRational& r) const
{
    return (_num * r._den <= r._num * _den);
}


ostream& operator <<(ostream& outStream, const myRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;//<<endl;
    return outStream;
}
istream& operator >>(istream& inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}

long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n - m);
    else
        return gcd(m - n, n);
}

void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
}