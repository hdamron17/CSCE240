/**
 * complex.h
 * 
 * Created by Hunter Damron
 *     Copyright 2018
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
// using fabs
// using round

#include <string>
using std::string;

class complex {
public:
    complex() : real_(0.0), imag_(0.0) {};
    complex(double imag) : real_(0.0), imag_(imag) {};
    complex(double real, double imag) : real_(real), imag_(imag) {};

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

    const bool operator==(const complex& rhs) const;
    const bool operator!=(const complex& rhs) const;

    const string ToString() const;

private:
    double real_, imag_;
    const double epsilon = 0.00001;
};

#endif /* COMPLEX_H */
