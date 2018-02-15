/**
 * complex.cc
 *
 * Created by Hunter Damron
 *     Copyright 2018
 */

#include "complex.h"  // NOLINT(build/include_subdir)

double Complex::real() const {
    return this->real_;
}

void Complex::real(double real_val) {
    this->real_ = real_val;
}

double Complex::imag() const {
    return this->imag_;
}

void Complex::imag(double imag_val) {
    this->imag_ = imag_val;
}

const Complex Complex::Add(const Complex& rhs) const {
    return Complex(this->real_ + rhs.real_, this->imag_ + rhs.imag_);
}

const Complex Complex::Add(double rhs) const {
    return Complex(this->real_ + rhs, this->imag_);
}

const Complex Complex::Add(int rhs) const {
    return Complex(this->real_ + rhs, this->imag_);
}

const Complex Complex::operator+(const Complex& rhs) const {
    return this->Add(rhs);
}

const Complex Complex::operator+(double rhs) const {
    return this->Add(rhs);
}

const Complex Complex::operator+(int rhs) const {
    return this->Add(rhs);
}

const Complex operator+(double lhs, const Complex& rhs) {
    return rhs.Add(lhs);
}

const Complex operator+(int lhs, const Complex& rhs) {
    return rhs.Add(lhs);
}

const Complex Complex::Mul(const Complex& rhs) const {
    // (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
    return Complex(this->real_ * rhs.real_ - this->imag_ * rhs.imag_,
                   this->real_ * rhs.imag_ + this->imag_ * rhs.real_);
}

const Complex Complex::Mul(double rhs) const {
    return Complex(this->real_ * rhs, this->imag_ * rhs);
}

const Complex Complex::Mul(int rhs) const {
    return Complex(this->real_ * rhs, this->imag_ * rhs);
}

const Complex Complex::operator*(const Complex& rhs) const {
    return this->Mul(rhs);
}

const Complex Complex::operator*(double rhs) const {
    return this->Mul(rhs);
}

const Complex Complex::operator*(int rhs) const {
    return this->Mul(rhs);
}

const Complex operator*(double lhs, const Complex& rhs) {
    return rhs.Mul(lhs);
}

const Complex operator*(int lhs, const Complex& rhs) {
    return rhs.Mul(lhs);
}

const string Complex::ToString() const {
    stringstream ret;

    bool has_real = this->real_ != 0.0;
    bool has_imag = this->imag_ != 0.0;

    ret << "(";

    if (has_real) {
        ret << this->real_;  // Adds real_ is it is nonzero
    }
    if (has_imag) {
        if (has_real) {
            if (this->imag_ > 0)
                ret << " + ";  // If real_ nonzero and imag_ positive, addition
            if (this->imag_ < 0)
                ret << " - ";  // If real_ nonzero and imag_ negative, addition
        } else {
            if (this->imag_ < 0)
                ret << "-";  // No spaces around minus if there is no real part
        }

        if (abs(this->imag_) != 1) {
            ret << abs(this->imag_);  // If imag_ is not 1, add abs(imag_)
        }

        ret << "i";  // Append i so we know it's the imaginary part
    }
    if (!has_real && !has_imag) {
        ret << "0";  // If both real_ and imag_ are zero, the number is 0
    }

    ret << ")";

    return ret.str();
}

const Complex Complex::ToComplex(string& val) {
    if (val.size() <= 2 || val.front() != '(' || val.back() != ')')
        return Complex();  // Invalid if it does not begin and end with ( and )

    stringstream in(val);
    stringstream num;
    char tmp;
    float real = 0, imag = 0;

    in.get(tmp);            // Get first parenthesis
    bool has_num = false,   // True when number has begun (for negative sign)
         imag_neg = false,  // True iff imag_ should be negative
         done = false;      // True when the conversion is done so loop exits

    while (!done) {
        in.get(tmp);

        if (in.fail()) {
            return Complex();  // Return 0 complex number if anything fails
        }

        switch (tmp) {
            case '-':
            case '+':
                if (has_num) {
                    // Negative is not first so it is the separator
                    real = stof(num.str());  // Put number into real part
                    num.str("");  // Clear sstream to start over for imag
                    has_num = false;
                    if (tmp == '-')
                        imag_neg = true;
                } else {
                    // The negative is first in number so add it to the sstream
                    num << tmp;
                }
                break;
            case 'i':
                // Immediately follows imaginary part and ends number
                if (num.str() == "")
                    imag = 1;  // 1 by default if none is specified
                else
                    imag = stof(num.str());  // Else convert to a number
                if (imag_neg)
                    imag = -imag;  // If we found a negative earlier, apply now
                done = true;  // Because imaginary is second, number is done
                break;
            default:
                if (tmp == ')' || in.eof()) {
                    // End ) signals end of number
                    // We should not run into eof before ) but just in case
                    real = stof(num.str());  // Parse number into real
                    done = true;
                } else if (tmp == '.' || (tmp >= '0' && tmp <= '9')) {
                    // 0-9 and . can be parts of a number, anything else ignored
                    num << tmp;
                    has_num = true;
                }
        }
    }

    return Complex(real, imag);
}

ostream& operator<<(ostream& lhs, const Complex rhs) {
    lhs << rhs.ToString();
    return lhs;
}

istream& operator>>(istream& lhs, Complex& rhs) {
    stringstream complex_str;
    char tmp = '\0';

    while (tmp != '(' && lhs.good()) {
        // Reads and discards until open ( is found
        lhs.get(tmp);
    }
    complex_str << tmp;

    while (tmp != ')' && lhs.good()) {
        // Until close ) is found, add read characters to sstream for number
        lhs.get(tmp);
        complex_str << tmp;
    }

    if (lhs.good()) {
        // If all goes well, we can parse the value via Complex::ToComplex
        string rhs_str = complex_str.str();
        rhs = Complex::ToComplex(rhs_str);
    } else {
        // If anything fails, just give back the empty Complex instance
        rhs = Complex();
    }

    return lhs;
}
