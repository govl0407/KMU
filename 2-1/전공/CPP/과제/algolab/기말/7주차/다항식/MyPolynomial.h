#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_ 
#include <iostream> 
#include "MyTerm.h" 
#include <list> 
#include <vector>
using namespace std;
class myPolynomial
{
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    // copy constructor 
    myPolynomial(const myPolynomial& poly);
    // overloaded operators 
    bool operator == (const myPolynomial& poly) const;
    bool operator != (const myPolynomial& poly) const;
    myPolynomial& operator += (const myPolynomial& poly);
    myPolynomial& operator -= (const myPolynomial& poly);
    myPolynomial& operator *= (const myPolynomial& poly);
    myPolynomial& operator *= (int k);
    myPolynomial operator -() const;
    myPolynomial operator *(int k) const;
    myPolynomial operator +(const myPolynomial& poly) const;
    myPolynomial operator +(int a) const;
    friend myPolynomial operator +(int a, const myPolynomial& poly);
    myPolynomial operator -(const myPolynomial& poly) const;
    myPolynomial operator -(int a) const;
    friend myPolynomial operator -(int a, const myPolynomial& poly);
    myPolynomial operator *(const myPolynomial& poly) const;
    myPolynomial operator -(); // unary minus
  

    long operator() (int x) const; // evaluate the polynomial 
    int getDegree() const; // get a degree of the polynomial 
    int getNumTerms() const; // number of terms in the polynomial 
    myPolynomial ddx() const; // derivative of a polynomial 
    // friend operators and functions 
    friend myPolynomial operator *(int k, const myPolynomial& poly);
    static const myPolynomial ZERO; // P(x) = 0 
    static const myPolynomial ONE; // P(x) = 1 
    static const myPolynomial X; // P(x) = x 
private:
    int degree; // maximum expnent  
    vector<myTerm> terms;
    void reduce();

    friend ostream& operator <<(ostream& outStream, const myPolynomial& poly);
    /********************* add your code here ********************************/
};
#endif _MYPOLYNOMIAL_H_