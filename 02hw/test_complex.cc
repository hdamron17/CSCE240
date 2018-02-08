/**
 * test_complex.cc
 * 
 * Created by Hunter Damron
 *     Copyright 2018
 */

#include <iostream>
#include <cassert>

#include "complex.h"

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

    complex a = complex(4.5, 32) * complex(1, -1);
    // assert(a == complex(36.5, 27.5)); //TODO

    assert(complex(2,-1) * 0.5 == complex(1,-0.5));
    assert(complex(2,-1) * 2 == complex(4, -2));
}
