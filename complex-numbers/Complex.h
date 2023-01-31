#ifndef COMPLEX_H
#define COMPLEX_H

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

// A class representing complex numbers
// of the form z = Re + i*Im
class Complex
{
public:
    // Create complex number 0
    Complex();

    // Create complex number with zero imaginary part.
    // Allows implicit conversion from real numbers (i.e. from double do Complex)
    Complex(double real);

    // Create complex number real + i*imag
    Complex(double real, double imag);

    // read value of real part
    double getReal() const;

    // set the real part
    void setReal(double newReal);

    // read value of imaginary part
    double getImag() const;

    // set imaginary part
    void setImag(double newImag);

    // get the absolute of the complex number
    double abs() const;

    // get the angle in the complex plane in degrees
    double angle() const;

    // Add another Complex number
    Complex& operator+=(const Complex& rhs);

    // Addition is a friend
    friend Complex operator+(Complex lhs, const Complex& rhs);

    // Multiply two complex numbers
    Complex& operator*=(const Complex& rhs);

    // Multiplication is a friend
    friend Complex operator*(Complex lhs, const Complex& rhs);

    // Printing is a friend
    friend std::ostream& operator<<(std::ostream& os, const Complex& z);

private:
    // The real part
    double real_;

    // The imaginary part
    double imag_;
};

// Add two complex numbers
Complex operator+(Complex lhs, const Complex& rhs);

// Multiply two complex numbers
Complex operator*(Complex lhs, const Complex& rhs);

// Print a complex number to the command line
std::ostream& operator<<(std::ostream& os, const Complex& z);

#endif
