#include "MyComplex.h"
// 생성자
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
// 복사 생성자
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}

// 접근자
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}
// 변경자
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}


// Overloaded binary operators
// +
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex operator+(int value, const myComplex& number)
{
    return myComplex(value + number.realPart, number.imaginaryPart);
}

myComplex& myComplex::operator +=(const myComplex& number)
{
    realPart += number.realPart;
    imaginaryPart += number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator +=(int value)
{
    realPart += value;
    return *this;
}

//-
myComplex myComplex::operator -(const myComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
    return myComplex(value) - (*this);
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    realPart -= number.realPart;
    imaginaryPart -= number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(int value)
{
    realPart -= value;
    return *this;
}

//*
myComplex myComplex::operator *(const myComplex& number) const
{
    int newReal = realPart * number.realPart;
    int newImag = imaginaryPart * number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
    return myComplex(value) * (*this);
}
myComplex myComplex::operator *=(const myComplex& number)
{
    realPart *= number.realPart;
    imaginaryPart *= number.imaginaryPart;
    return *this;
}
myComplex myComplex::operator *=(int value)
{
    realPart *= value;
    return *this;
}

//++--
myComplex& myComplex::operator ++()
{
    realPart++;
    return *this;
}
myComplex myComplex::operator ++(int)
{
    myComplex t(*this);
    operator++();
    return t;
}
myComplex& myComplex::operator --()
{
    realPart--;
    return *this;
}
myComplex myComplex::operator --(int)
{
    myComplex t(*this);
    operator--();
    return t;
}
// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
// Overloading comparison operators
//=
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
    return (realPart != number.realPart) && (imaginaryPart != number.imaginaryPart);
}
//<
bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}

// Overloaded unary operators
myComplex myComplex::operator -()// unary minus
{
    return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ~()
{
    return myComplex(realPart, -imaginaryPart);
}
// private function
int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream& operator <<(ostream& outStream, const myComplex& number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}
istream& operator >>(istream& inStream, myComplex& number)
{
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}