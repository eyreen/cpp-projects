#include <iostream>

#include "Complex.h"

#define _USE_MATH_DEFINES
#include <math.h>

Complex::Complex()
    : real_{0},
      imag_{0}
{
}

Complex::Complex(double real)
    : real_{real},
      imag_{0}
{
}

Complex::Complex(double real, double imag)
    : real_{real},
      imag_{imag}
{
}

double Complex::getReal() const
{
    return real_;
}

void Complex::setReal(double newReal)
{
    real_ = newReal;
}

double Complex::getImag() const
{
    return imag_;
}

void Complex::setImag(double newImag)
{
    imag_ = newImag;
}

double Complex::abs() const
{
    return sqrt(real_ * real_ + imag_ * imag_);
}

double Complex::angle() const
{
    double angleInRad = atan2(imag_, real_);
    double angleInDeg = angleInRad * 180. / M_PI;
    if (angleInDeg < 0)
        angleInDeg += 360;
    return angleInDeg;
}

Complex& Complex::operator+=(const Complex& rhs)
{
    real_ += rhs.real_;
    imag_ += rhs.imag_;
    return *this;
}

Complex operator+(Complex lhs, const Complex& rhs)
{
    lhs += rhs;
    return lhs;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    // The product of two complex numbers is defined as
    // (x + iy)*(u + iv) = (xu-yv) + (xv+yu)i
    double x = real_;
    double y = imag_;
    double u = rhs.real_;
    double v = rhs.imag_;

    real_ = x * u - y * v;
    imag_ = x * v + y * u;
    return *this;
}

Complex operator*(Complex lhs, const Complex& rhs)
{
    lhs *= rhs;
    return lhs;
}

std::ostream& operator<<(std::ostream& os, const Complex& z)
{
    if (z.imag_ >= 0)
    {
        os << z.real_ << "+" << z.imag_ << "i";
    }
    else
    {
        os << z.real_ << "-" << fabs(z.imag_) << "i";
    }
    return os;
}
