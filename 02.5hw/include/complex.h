/**
 * complex.h
 *
 * Created by Hunter Damron
 *     Copyright 2018
 */

#ifndef _HDAMRON_HW_2_COMPLEX_H_  // NOLINT(build/header_guard)
#define _HDAMRON_HW_2_COMPLEX_H_

#include <cmath>
using std::abs;

#include <cassert>
// using assert

#include <string>
using std::string;
using std::stof;

#include <cctype>
using std::isspace;

#include <iostream>
using std::istream;
using std::ostream;
using std::streampos;
using std::ios_base;
using std::ios;

#include <sstream>
using std::stringstream;

#include <regex>  // NOLINT(build/c++11)
using std::regex;
using std::regex_match;
using std::smatch;


/**
 * Regex detects open ( followed by signed int/float
 *   then either a +/- followed by an unsigned int/float with i and end ),
 *   just i and end ),
 *   or just )
 *
 * Groups first int/float then operator then second int/float with i
 *   then i if there is no operator and second int/float)
 *
 * Note: Accounts for floats that begin with decimal as in (.4223)
 * Note: Does not account for the implicit 1 when only imaginary part (i)
 */
const regex re = regex("\\( *([+-]?[0-9]*\\.?[0-9]+)"  // num1
          "(?:"
            " *([+-]) *((?:[0-9]*\\.?[0-9]+)?) *i *\\)"  // num2
            "|(i) *\\)"  // i only
            "|\\)"  // end parentheses only
          ")");
// TODO(HD) The decimal in floating point numbers should work but does not
//       It has been tested in online regex testers and backed by online sources

class Complex {
 public:
    /**
     * Converts a string to a Complex following rules of the regex re
     * Returns the zero complex if invalid.
     */
    static const Complex ToComplex(const string& val);  // NOLINT (rtime/references)

    /**
     * Checks if the string contains a valid complex according to the regex re
     * For string argument, the whole string must match
     * For the istream argument, the complex may have leading whitespace
     */
    static bool IsComplex(const string& val);
    static bool IsComplex(istream& in_stream);

    // Complex constructors setting real_ and imag_ to 0.0 or a specified value
    Complex() : real_(0.0), imag_(0.0) {}
    Complex(double imag) : real_(0.0), imag_(imag) {}  // NOLINT (rtime/explicit)
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
    const Complex Add(double rhs) const;
    const Complex Add(int rhs) const;

    // Operator overload for + operator to call Complex::Add function
    const Complex operator+(const Complex& rhs) const;
    const Complex operator+(double rhs) const;
    const Complex operator+(int rhs) const;

    // Complex multiplication (a + bi) * (c + di) = ((ac - bd) + (ad + bc)i)
    // As in addition, double and int arguments are treated as real only
    const Complex Mul(const Complex& rhs) const;
    const Complex Mul(double rhs) const;
    const Complex Mul(int rhs) const;

    // Operator overload for * operator to call Complex::Mul function
    const Complex operator*(const Complex& rhs) const;
    const Complex operator*(double rhs) const;
    const Complex operator*(int rhs) const;

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

    // Addition of real and imaginary parts independantly
    friend const Complex operator+(double lhs, const Complex& rhs);
    friend const Complex operator+(int lhs, const Complex& rhs);

    friend const Complex operator*(double lhs, const Complex& rhs);
    friend const Complex operator*(int lhs, const Complex& rhs);

    // Less than compares the magnitudes of two complex numbers
    // Note that int/double args are promoted to complex with zero imaginary
    bool LT(const Complex& rhs) const;
    bool LT(double rhs) const;
    bool LT(int rhs) const;
    bool operator<(const Complex& rhs) const;
    bool operator<(double rhs) const;
    bool operator<(int rhs) const;
    friend bool operator<(double lhs, const Complex& rhs);
    friend bool operator<(int lhs, const Complex& rhs);

    /**
     * Overloads >> operator to extract from lhs a complex number and parse it
     * Characters are parsed from lhs until a pair of parentheses are found
     * Modifies rhs to contain the parsed number extracted from lhs
     * Asserts that a valid number can be extracted
     * Returns the modified lhs after extraction
     */
    friend istream& operator>>(istream& lhs, Complex& rhs);

    // Overloads << operator to add rhs.ToString() to lhs ostream and return lhs
    friend ostream& operator<<(ostream& lhs, const Complex rhs);

 private:
    // real and imaginary parts of the comlpex number, respectively
    double real_, imag_;

    // Extracts the next complex number from in_stream ignoreing leading wspace
    // Detects complex number by presence of open and close parentheses only
    // If the stream cannot provide open and close parentheses, an empty string
    //   is returned
    static const string ExtractComplex(istream& in_stream, const bool nochange);
};

#endif  // _HDAMRON_HW_2_COMPLEX_H_
