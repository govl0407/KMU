#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
///////////////////header
#include <iostream>
using namespace std;
class myComplex {
public:
    ///////////////////////////////////////////// Constructor (생성자)
    myComplex(int real = 0, int imag = 0);
    // Copy constructor (복사 생성자)
    myComplex(const myComplex& number);

    //////////////////////////////////////////////// Accessor functions (접근자)
    int getRealPart() const;
    int getImaginaryPart() const;
    //////////////////////////////////////////////// Mutator functions (변경자)
    void setRealPart(int real);
    void setImaginaryPart(int imag);
    void set(int real, int imag);

    ////////////////////////////////////////////////////// Overloaded binary operators
    myComplex operator +(const myComplex& number) const;// complex + complex
    myComplex operator +(int value) const; //complex + int
    friend myComplex operator +(int value, const myComplex& number); //int + complex
    myComplex& operator +=(const myComplex& number); // complex += complex
    myComplex& operator +=(int value); // complex += int

    myComplex operator -(const myComplex& number) const; //complex - complex
    myComplex operator -(int value) const;//complex - int
    friend myComplex operator -(int value, const myComplex& number);//int - complex
    myComplex& operator -=(const myComplex& number); //complex -=complex
    myComplex& operator -=(int value);//complex -=int

    myComplex operator *(const myComplex& number) const; //complex*complex
    myComplex operator *(int value) const;//complex * int
    friend myComplex operator*(int value, const myComplex& number); //int * complex
    myComplex& operator *=(const myComplex& number); // complex*=complex
    myComplex& operator *=(int value); // complex *= int

    ////////////////////////////////////////// Overloaded assignment operators
    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);


    ///////////////////////////////////////////////pre, post
    myComplex& operator ++(); // complex++
    myComplex operator ++(int); // ++complex
    myComplex& operator --(); // complex--
    myComplex operator --(int); // --complex
    ///////////////////////////////////////////// Overloading relational operators
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator >(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;

    ///////////////////////////////////////////////// Overloaded unary operators
    myComplex operator -(); // unary minus

    myComplex operator ~() const;
private:
    int realPart;
    int imaginaryPart;
    int norm() const;

    friend ostream& operator <<(ostream& outStream, const myComplex& number);
    friend istream& operator >>(istream& inStream, myComplex& number);
};

#endif