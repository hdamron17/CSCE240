/**
 * complex.h
 *
 * Created by Hunter Damron
 *     Copyright 2018
 */

#ifndef COMPLEX_H  // NOLINT(build/header_guard)
#define COMPLEX_H

#include <cmath>
// using fabs
// using abs
// using round

#include <string>
using std::string;
using std::stof;

#include <iostream>
using std::istream;
using std::ostream;

#include <sstream>
using std::stringstream;

class Complex {
 public:
    // Complex constructors setting real_ and imag_ to 0.0 or a specified value
    Complex() : real_(0.0), imag_(0.0) {}
    explicit Complex(double imag) : real_(0.0), imag_(imag) {}
    Complex(double real, double imag) : real_(real), imag_(imag) {}

    // Overloaded getter/setter for instance variable real_
    double real() const;
    void real(double real_val);

    // Overloaded getter/setter for instance variable imag_
    double imag() const;
    void imag(double imag_val);

    // Complex addition adds real_ and imag_ independantly
    // Double and int arguments are treated as real with zero imaginary part
    const Complex Add(const Complex& rhs) const;
    const Complex Add(const double rhs) const;
    const Complex Add(const int rhs) const;

    // Operator overload for + operator to call Complex::Add function
    const Complex operator+(const Complex& rhs) const;
    const Complex operator+(const double rhs) const;
    const Complex operator+(const int rhs) const;
    friend const Complex operator+(const double lhs, const Complex& rhs);
    friend const Complex operator+(const int lhs, const Complex& rhs);

    // Complex multiplication (a + bi) * (c + di) = ((ac - bd) + (ad + bc)i)
    // As in addition, double and int arguments are treated as real only
    const Complex Mul(const Complex& rhs) const;
    const Complex Mul(const double rhs) const;
    const Complex Mul(const int rhs) const;

    // Operator overload for * operator to call Complex::Mul function
    const Complex operator*(const Complex& rhs) const;
    const Complex operator*(const double rhs) const;
    const Complex operator*(const int rhs) const;
    friend const Complex operator*(const double lhs, const Complex& rhs);
    friend const Complex operator*(const int lhs, const Complex& rhs);

    /**
     * Converts a complex instance to a string according to the following rules
     * "(2 + 2i)" is the base case
     * "(1.71 + 3.14159i)" in the case of a non-whole floating point
     * "(2 + i)" in the case the imaginary portion is 1.0
     * "(2 - 2i)" in the case that the imaginary portion is < 0
     * "(2)" in the case that the imaginary portion is 0
     * "(2i)" in the case that the real portion is 0
     */
    const string ToString() const;

    // Converts a string to a Complex following rules of Complex::ToString
    static const Complex ToComplex(const string val);

    // Overloads << operator to add rhs.ToString() to lhs ostream and return lhs
    friend ostream& operator<<(ostream& lhs, const Complex rhs);

    /**
     * Overloads >> operator to extract from lhs a complex number and parse it
     * Characters are parsed from lhs until a pair of parentheses are found
     * Modifies rhs to contain the parsed number extracted from lhs
     * Returns the modified lhs after extraction
     */
    friend istream& operator>>(istream& lhs, Complex& rhs);

 private:
    // real and imaginary parts of the comlpex number, respectively
    double real_, imag_;
};

#endif  // 02HW_COMPLEX_H_
