#include <iostream>
#include "../test.h"

#include "Complex.h"

TEST(AddingComplexNumbersTest)
{
    Complex z1 { 3, 4 };
    Complex z2 { 10, 15 };

    Complex z3 = z1 + z2;
    check(z3.getReal(), 13);
    check(z3.getImag(), 19);

    z1 += z2;
    check(z1.getReal(), 13);
    check(z1.getImag(), 19);
}

TEST(MultiplyComplexNumbersTest)
{
    // Test multiplication
    Complex z1 = Complex {2, 5};
    Complex z2 = Complex {3, 4};
    Complex z3 = z1 * z2;
    check(z3.getReal(), 2*3 - 5*4);
    check(z3.getImag(), 2*4 + 5*3);

    z1 *= z2;
    check(z1.getReal(), 2*3 - 5*4);
    check(z1.getImag(), 2*4 + 5*3);
}

TEST(AddDoubleAndComplexTest)
{
    Complex z1 = Complex { 2, 3 };
    z1 += 5;
    check(z1.getReal(), 7);
    check(z1.getImag(), 3);

    Complex z2 = z1 + 4;
    check(z2.getReal(), 11);
    check(z2.getImag(), 3);

    Complex z3 = 4 + z1;
    check(z3.getReal(), 11);
    check(z3.getImag(), 3);
}



int main()
{
    Complex z1 {2, 3};
    std::cout << "z1=" << z1 << "\n";
    z1 = Complex{-2, -3};
    std::cout << "z1=" << z1 << std::endl;
    return 0;
}