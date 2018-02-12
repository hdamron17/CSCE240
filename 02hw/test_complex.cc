/**
 * test_complex.cc
 *
 * Created by Hunter Damron
 *     Copyright 2018
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

#include <sstream>
using std::stringstream;

#include "complex.h"  // NOLINT(build/include_subdir)

const bool operator==(const complex& lhs, const complex& rhs) {
    double epsilon = 0.0000001;
    double real_err = fabs(lhs.real() - rhs.real());
    double imag_err = fabs(lhs.imag() - rhs.imag());
    return real_err <= epsilon && imag_err <= epsilon;
}

const bool operator!=(const complex& lhs, const complex& rhs) {
    return !(lhs == rhs);
}

int main() {
    complex x;
    assert(x.real() == 0.0);
    assert(x.imag() == 0.0);
    assert(x == complex(0.0, 0.0));

    complex y(4.0);
    assert(y.real() == 0.0);
    assert(y.imag() == 4.0);
    assert(y == complex(0.0, 4.0));

    complex z(2.3, -1);
    assert(z.real() == 2.3);
    assert(z.imag() == -1);
    assert(z == complex(2.3, -1));
    assert(z != complex(2.3, -1.1));
    assert(z != complex(-2.3, -1));
    assert(z != complex(-2.3, 1));

    complex w(4.3);
    assert(w.imag() == 4.3);
    assert(w.real() != 5);
    w.real(5);
    assert(w.real() == 5);
    assert(w.imag() == 4.3);
    w.imag(-134.4);
    assert(w.real() == 5);
    assert(w.imag() == -134.4);

    complex xpy = x.Add(y);
    assert(xpy.real() == 0.0);
    assert(xpy.imag() == 4.0);

    complex zpy = z.Add(y);
    assert(zpy.real() == 2.3);
    assert(zpy.imag() == 3.0);

    complex ypz = y + z;
    assert(ypz.real() == zpy.real());
    assert(ypz.imag() == zpy.imag());

    assert(complex(4.5, 32) * complex(1, -1) == complex(36.5, 27.5));
    assert(complex(-1) * complex(3, 4) == complex(4, -3));

    assert(complex(2, -1) * 0.5 == complex(1, -0.5));
    assert(complex(2, -1) * 2 == complex(4, -2));

    assert(!complex(2, -4).ToString().compare("(2 - 4i)"));
    assert(!complex(2).ToString().compare("(2i)"));
    assert(!complex(3, 0).ToString().compare("(3)"));
    assert(!complex().ToString().compare("(0)"));
    assert(!complex(-2, 3.2).ToString().compare("(-2 + 3.2i)"));
    assert(!complex(1).ToString().compare("(i)"));

    stringstream so1, so2, so3;
    so1 << complex(3.1, -1);
    assert(!so1.str().compare("(3.1 - i)"));
    so2 << complex(-2.9999);
    assert(!so2.str().compare("(-2.9999i)"));
    so3 << complex(-0.11, 0.12);
    assert(!so3.str().compare("(-0.11 + 0.12i)"));

    complex a0, a1, a2, a3, a4;
    stringstream si("(4 - 3i)\n(4 + 3i)\n(2)\n(2 - i)\n(0 - -4i)");
    si >> a0;
    assert(a0 == complex(4, -3));
    si >> a1;
    assert(a1 == complex(4, 3));
    si >> a2;
    assert(a2 == complex(2, 0));
    si >> a3;
    assert(a3 == complex(2, -1));
    si >> a4;
    assert(a4 == complex(0, 4));
}
