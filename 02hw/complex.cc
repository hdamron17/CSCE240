/**
 * complex.cc
 *
 * Created by Hunter Damron
 *     Copyright 2018
 */

#include "complex.h"  // NOLINT(build/include_subdir)

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
                   this->real_ * rhs.imag_ + this->imag_ * rhs.real_);
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

const string complex::ToString() const {
    stringstream ret;

    bool has_real = this->real_ != 0.0;
    bool has_imag = this->imag_ != 0.0;

    ret << "(";

    if (has_real) {
        ret << this->real_;
    }
    if (has_imag) {
        if (has_real) {
            if (this->imag_ > 0)
                ret << " + ";
            if (this->imag_ < 0)
                ret << " - ";
        } else {
            if (this->imag_ < 0)
                ret << "-";
        }

        if (abs(this->imag_) != 1) {
            ret << abs(this->imag_);
        }

        ret << "i";
    }
    if (!has_real && !has_imag) {
        ret << "0";
    }

    ret << ")";

    return ret.str();
}

const complex complex::ToComplex(const string val) {
    if (val.size() <= 2 || val.front() != '(' || val.back() != ')')
        return complex();

    stringstream in(val);
    stringstream num;
    char tmp;
    float real = 0, imag = 0;

    in.get(tmp);            // Get first parenthesis
    bool has_num = false,   // True when number has begun (for negative sign)
         has_real = false,  // True when real number has already been parsed
         imag_neg = false,  // True iff imag_ should be negative
         done = false;

    while (!done) {
        in.get(tmp);

        if (in.fail()) {
            return complex();  // Return 0 complex number if anything fails
        }

        switch (tmp) {
            case '-':
            case '+':
                if (has_num) {
                    // Negative is not first so it is the separator
                    real = stof(num.str());
                    num.str("");
                    has_real = true;
                    has_num = false;
                    if (tmp == '-')
                        imag_neg = true;
                } else {
                    // The negative is first in number so add it to the sstream
                    num << tmp;
                }
                break;
            case 'i':
                imag = (num.str() == "") ? 1 : stof(num.str());  // 1 by default
                num.str("");
                if (imag_neg)
                    imag = -imag;
                done = true;
                break;
            default:
                if (tmp == ')' || in.eof()) {
                    real = stof(num.str());
                    done = true;
                } else if (tmp == '.' || (tmp >= '0' && tmp <= '9')) {
                    num << tmp;
                    has_num = true;
                }
        }
    }

    return complex(real, imag);
}

ostream& operator<<(ostream& lhs, const complex rhs) {
    lhs << rhs.ToString();
    return lhs;
}

istream& operator>>(istream& lhs, complex& rhs) {
    stringstream complex_str;
    char tmp = '\0';

    while (tmp != '(' && lhs.good()) {
        lhs.get(tmp);
    }
    complex_str << tmp;

    while (tmp != ')' && lhs.good()) {
        lhs.get(tmp);
        complex_str << tmp;
    }

    if (lhs.good()) {
        rhs = complex::ToComplex(complex_str.str());
    } else {
        rhs = complex();
    }

    return lhs;
}
