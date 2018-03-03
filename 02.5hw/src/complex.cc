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

bool Complex::LT(const Complex& rhs) const {
    // Calculates magnitude of this complex using euclidean distance
    double this_magnitude  = sqrt(this->real_ * this->real_
                                + this->imag_ * this->imag_);
    // Calculates magnitude of rhs complex using euclidean distance
    double other_magnitude = sqrt(rhs.real_ * rhs.real_
                                + rhs.imag_ * rhs.imag_);
    // Compares magnitudes
    return this_magnitude < other_magnitude;
}

bool Complex::LT(double rhs) const {
  return this->LT(Complex(rhs, 0));
}

bool Complex::LT(int rhs) const {
    return this->LT(Complex(rhs, 0));
}

bool Complex::operator<(const Complex& rhs) const {
    return this->LT(rhs);
}

bool Complex::operator<(double rhs) const {
    return this->LT(rhs);
}

bool Complex::operator<(int rhs) const {
    return this->LT(rhs);
}

bool operator<(double lhs, const Complex& rhs) {
    return Complex(lhs, 0).LT(rhs);
}

bool operator<(int lhs, const Complex& rhs) {
    return Complex(lhs, 0).LT(rhs);
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

const Complex Complex::ToComplex(const string& val) {
    smatch res;
    bool matched = regex_match(val, res, re);
    assert(matched);

    double real = 0, imag = 0;

    // Testing matched asserts that it is a valid complex
    if (matched) {
        // First element of match is the full match so start with 1 as real
        real = stof(res[1]);
        if (res[4] == "i") {
            // If it has i in the last place, it is only the imaginary part
            imag = real;
            real = 0;
        } else if (res[2] == "") {
            // If there is only one match, it is just the real part
        } else {
            // If there are 3 match groups, the second is the +/- and third
            //   is the imaginary part (accounts for implicit 1)
            if (res[3] == "")
                imag = 1;
            else
                imag = stof(res[3]);

            if (res[2] == "-")
                imag = -imag;
        }
    }
    return Complex(real, imag);
}

const string Complex::ExtractComplex(istream& in_stream, const bool nochange) {
    string comp_str;
    char c = '\0';
    bool past_wspace = false;
    streampos start = in_stream.tellg();
    ios::iostate start_state = in_stream.rdstate();
    do {
        if (nochange) {
            // If nochange, peek at value and seek forward instead of getting
            c = in_stream.peek();
            in_stream.seekg(1, ios_base::cur);
        } else {
            // If allowed to change, get value
            in_stream.get(c);
        }
        if (!past_wspace && !isspace(c))
            past_wspace = true;
        if (past_wspace)
            comp_str += c;
    } while (c != ')' && in_stream.good());

    if (!in_stream.good()) {
        comp_str = "";
    }

    if (nochange) {
        // If nochange, set stream back to beginning position and clear failures
        in_stream.seekg(start);
        in_stream.setstate(start_state);
    }

    return comp_str;
}

bool Complex::IsComplex(const string& val) {
    smatch res;
    bool matched = regex_match(val, res, re);
    return matched;
}

bool Complex::IsComplex(istream& in_stream) {
    return IsComplex(ExtractComplex(in_stream, true));
}

ostream& operator<<(ostream& lhs, const Complex rhs) {
    lhs << rhs.ToString();
    return lhs;
}

istream& operator>>(istream& lhs, Complex& rhs) {
    string comp = Complex::ExtractComplex(lhs, false);
    rhs = Complex::ToComplex(comp);
    return lhs;
}
