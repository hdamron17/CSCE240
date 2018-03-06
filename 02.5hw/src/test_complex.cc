/**
 * test_complex.cc
 *
 * Created by Hunter Damron
 *     Copyright 2018
 */

#include <cassert>
// using assert

#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include "complex.h"  // NOLINT(build/include_subdir)

const bool operator==(const Complex& lhs, const Complex& rhs) {
    double epsilon = 0.00001;
    double real_err = abs(lhs.real() - rhs.real());
    double imag_err = abs(lhs.imag() - rhs.imag());
    return real_err <= epsilon && imag_err <= epsilon;
}

const bool operator!=(const Complex& lhs, const Complex& rhs) {
    return !(lhs == rhs);
}

int main() {
    Complex x;
    assert(x.real() == 0.0);
    assert(x.imag() == 0.0);
    assert(x == Complex(0.0, 0.0));

    Complex y(4.0);
    assert(y.real() == 0.0);
    assert(y.imag() == 4.0);
    assert(y == Complex(0.0, 4.0));

    Complex z(2.3, -1);
    assert(z.real() == 2.3);
    assert(z.imag() == -1);
    assert(z == Complex(2.3, -1));
    assert(z != Complex(2.3, -1.1));
    assert(z != Complex(-2.3, -1));
    assert(z != Complex(-2.3, 1));

    Complex w(4.3);
    assert(w.imag() == 4.3);
    assert(w.real() != 5);
    w.real(5);
    assert(w.real() == 5);
    assert(w.imag() == 4.3);
    w.imag(-134.4);
    assert(w.real() == 5);
    assert(w.imag() == -134.4);

    Complex xpy = x.Add(y);
    assert(xpy.real() == 0.0);
    assert(xpy.imag() == 4.0);

    Complex zpy = z.Add(y);
    assert(zpy.real() == 2.3);
    assert(zpy.imag() == 3.0);

    Complex ypz = y + z;
    assert(ypz.real() == zpy.real());
    assert(ypz.imag() == zpy.imag());

    assert(Complex(4.5, 32) * Complex(1, -1) == Complex(36.5, 27.5));
    assert(Complex(-1) * Complex(3, 4) == Complex(4, -3));

    assert(Complex(2, -1) * 0.5 == Complex(1, -0.5));
    assert(Complex(2, -1) * 2 == Complex(4, -2));

    assert(!Complex(2, -4).ToString().compare("(2 - 4i)"));
    assert(!Complex(2).ToString().compare("(2i)"));
    assert(!Complex(3, 0).ToString().compare("(3)"));
    assert(!Complex().ToString().compare("(0)"));
    assert(!Complex(-2, 3.2).ToString().compare("(-2 + 3.2i)"));
    assert(!Complex(1).ToString().compare("(i)"));

    stringstream so1, so2, so3;
    so1 << Complex(3.1, -1);
    assert(!so1.str().compare("(3.1 - i)"));
    so2 << Complex(-2.9999);
    assert(!so2.str().compare("(-2.9999i)"));
    so3 << Complex(-0.11, 0.12);
    assert(!so3.str().compare("(-0.11 + 0.12i)"));

    Complex a0, a1, a2, a3, a4;
    stringstream si("(4 - 3i)\n(4 + 3i)\n(2)\n(2 - i)\n(0 - 4i)");
    si >> a0;
    assert(a0 == Complex(4, -3));
    si >> a1;
    assert(a1 == Complex(4, 3));
    si >> a2;
    assert(a2 == Complex(2, 0));
    si >> a3;
    assert(a3 == Complex(2, -1));
    si >> a4;
    assert(a4 == Complex(0, -4));
    assert(!Complex::IsComplex(si));

    /// Revised for HW 2.5
    assert(!(Complex() < Complex()));
    assert(!(Complex(4, 5) < Complex(5, 4)));
    assert(Complex(4, 6) < Complex(6, 5));
    assert(!(Complex(6, 5) < Complex(4, 6)));
    assert(!(Complex(1, 2) < Complex(-1, -2)));
    assert(!(Complex(-1, -2) < Complex(1, 2)));
    assert(1.0 < Complex(43.0, 17.1));
    assert(Complex(2.0, 1) < 5.123);
    assert(33 < Complex(32, 32));
    assert(Complex(2,3) < 5);

    assert(Complex::IsComplex("(5 + 6i)"));
    assert(Complex::IsComplex("(-3.23 - 0.11i)"));
    assert(!Complex::IsComplex("(112 + 4)"));
    assert(!Complex::IsComplex(" (3.12 + 21.1i)"));
    assert(Complex::IsComplex("(3+2i)"));
    assert(!Complex::IsComplex("(3 + 2i) "));
    assert(Complex::IsComplex("(5 -i)"));
    assert(Complex::IsComplex("(5.2)"));
    assert(Complex::IsComplex("(-23.1i)"));
    assert(Complex::IsComplex("(2i)"));
    assert(Complex::ToComplex("(3i)") == Complex(0.0, 3.0));
    assert(Complex::ToComplex("(2i)") == Complex(0.0, 2.0));

    // Note: These values are supposed to be invalid contrary to common ideology
    assert(!Complex::IsComplex("i"));
    assert(!Complex::IsComplex("-i"));

    stringstream si2("\t(4 - 3i)\n\t\n(4 + 3)\n\n\t\n");
    assert(Complex::IsComplex(si2));
    assert(Complex::IsComplex(si2));
    assert(Complex::IsComplex(si2));
    assert(Complex::IsComplex(si2));
    assert(Complex::IsComplex(si2));
    Complex b0;
    si2 >> b0;
    assert(b0 == Complex(4, -3));
    assert(!Complex::IsComplex(si2));

    assert(Complex::IsComplex("(0.1)"));
    assert(Complex::IsComplex("(12.1 - 1.1i)"));
    assert(Complex::IsComplex("(12.9i)"));
    assert(Complex::IsComplex("(-1.1 + i)"));

    assert(Complex::ToComplex("(0.1)") == Complex(0.1, 0));
    assert(Complex::ToComplex("(12.1 - 1.1i)") == Complex(12.1, -1.1));
    assert(Complex::ToComplex("(12.9i)") == Complex(0, 12.9));
    assert(Complex::ToComplex("(-1.1 + i)") == Complex(-1.1, 1));

    assert(Complex::ToComplex("(.12)") == Complex(.12, 0));
    assert(Complex::ToComplex("(.001 + 7i)") == Complex(.001, 7));
    assert(Complex::ToComplex("(.1440i)") == Complex(0, .1440));
    assert(Complex::ToComplex("(.9 + .09i)") == Complex(.9, .09));

    // Should fail:
    // Complex b1;
    // si2 >> b1;

    cout << "All tests passed" << endl;
}
