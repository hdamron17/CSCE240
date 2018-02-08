/**
 * complex.cc
 * 
 * Created by Hunter Damron
 *     Copyright 2018
 */

#include "complex.h"

double complex::real() const {
    return this->real_;
}

void complex::real(double real_val) {
    this->real_ = real_val;
}

double complex::imag() const {
    return this->imag_;
}

void complex::imag(double imag_val) {
    this->imag_ = imag_val;
}

const complex complex::Add(const complex& rhs) const {
    return complex(this->real_ + rhs.real_, this->imag_ + rhs.imag_);
}

const complex complex::Add(const double rhs) const {
    return complex(this->real_ + rhs, this->imag_);
}

const complex complex::Add(const int rhs) const {
    return complex(this->real_ + rhs, this->imag_);
}

const complex complex::operator+(const complex& rhs) const {
    return this->Add(rhs);
}

const complex complex::operator+(const double rhs) const {
    return this->Add(rhs);
}

const complex complex::operator+(const int rhs) const {
    return this->Add(rhs);
}

const complex operator+(const double lhs, const complex& rhs) {
    return rhs.Add(lhs);
}

const complex operator+(const int lhs, const complex& rhs) {
    return rhs.Add(lhs);
}

const complex complex::Mul(const complex& rhs) const {
    // (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
    return complex(this->real_ * rhs.real_ - this->imag_ * rhs.imag_,
        this->real_ * rhs.imag_ + this->imag_ * this->real_);
}

const complex complex::Mul(const double rhs) const {
    return complex(this->real_ * rhs, this->imag_ * rhs);
}

const complex complex::Mul(const int rhs) const {
    return complex(this->real_ * rhs, this->imag_ * rhs);
}

const complex complex::operator*(const complex& rhs) const {
    return this->Mul(rhs);
}

const complex complex::operator*(const double rhs) const {
    return this->Mul(rhs);
}

const complex complex::operator*(const int rhs) const {
    return this->Mul(rhs);
}

const complex operator*(const double lhs, const complex& rhs) {
    return rhs.Mul(lhs);
}

const complex operator*(const int lhs, const complex& rhs) {
    return rhs.Mul(lhs);
}

const bool complex::operator==(const complex& rhs) const {
    double real_err = fabs(this->real_ - rhs.real_);
    double imag_err = fabs(this->imag_ - rhs.imag_);
    return real_err <= epsilon && imag_err <= epsilon;
}

const bool complex::operator!=(const complex& rhs) const {
    return !((*this) == rhs);
}

const string complex::ToString() const {
    bool real_whole = this->real_ - static_cast<int>(this->real_) <= epsilon;
    bool imag_whole = this->imag_ - static_cast<int>(this->imag_) <= epsilon;
}
