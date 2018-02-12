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

class complex {
 public:
    complex() : real_(0.0), imag_(0.0) {}
    explicit complex(double imag) : real_(0.0), imag_(imag) {}
    complex(double real, double imag) : real_(real), imag_(imag) {}

    double real() const;
    void real(double real_val);

    double imag() const;
    void imag(double imag_val);

    const complex Add(const complex& rhs) const;
    const complex Add(const double rhs) const;
    const complex Add(const int rhs) const;

    const complex operator+(const complex& rhs) const;
    const complex operator+(const double rhs) const;
    const complex operator+(const int rhs) const;
    friend const complex operator+(const double lhs, const complex& rhs);
    friend const complex operator+(const int lhs, const complex& rhs);

    const complex Mul(const complex& rhs) const;
    const complex Mul(const double rhs) const;
    const complex Mul(const int rhs) const;

    const complex operator*(const complex& rhs) const;
    const complex operator*(const double rhs) const;
    const complex operator*(const int rhs) const;
    friend const complex operator*(const double lhs, const complex& rhs);
    friend const complex operator*(const int lhs, const complex& rhs);

    const string ToString() const;
    static const complex ToComplex(const string val);

    friend ostream& operator<<(ostream& lhs, const complex rhs);
    friend istream& operator>>(istream& lhs, complex& rhs);

 private:
    double real_, imag_;
};

#endif  // 02HW_COMPLEX_H_
