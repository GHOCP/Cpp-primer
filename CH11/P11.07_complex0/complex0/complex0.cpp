// complex0.cpp -- methods for the complex0 class
#include "complex0.h"

/* ============== part 1 ============== */
/* default constructor */
complex_my::complex_my() {
    real = 0;
    imaginary = 0;
}
/* user-defined constructor */
complex_my::complex_my(double r, double i) {
    real = r;
    imaginary = i;
}
/* destrutor */
complex_my::~complex_my() {
};
/* set the values */
void complex_my::set_value(double r, double i) {
    real = r;
    imaginary = i;
}
/* show the complex */
void complex_my::show() const {
    std::cout << "(" << real << "," << imaginary << ")";
}


/* ============== part 2 ============== */
/* Addition: a + c = (A + C, (B + D)i) */
complex_my complex_my::operator+(const complex_my & c) const {
    return complex_my(real + c.real, imaginary + c.imaginary);
}
/* Subtraction: a - c = (A - C, (B - D)i) */
complex_my complex_my::operator-(const complex_my & c) const {
    return complex_my(real - c.real, imaginary - c.imaginary);
}
/* Multiplication: a ¡Á c = (A ¡Á C - B¡ÁD, (A¡ÁD + B¡ÁC)i) */
complex_my complex_my::operator*(const complex_my & c) const {
    return complex_my(real * c.real - imaginary * c.imaginary,
                      real * c.imaginary + imaginary * c.real);
}
/* Conjugation: ~a = (A, - Bi) */
complex_my complex_my::operator~() const {
    return complex_my(real, -imaginary);
}


/* ============== part 3 ============== */
/* Multiplication: (x a real number): x ¡Á c = (x¡ÁC,x¡ÁDi) */
complex_my operator*(const double x, const complex_my & c) {
    return complex_my(c.real * x, c.imaginary * x);
}
/* Multiplication: (x a real number): c ¡Á x = (x¡ÁC,x¡ÁDi) */
complex_my operator*(const complex_my & c, const double x) {
    return complex_my(c.real * x, c.imaginary * x);
}


/* ============== part 4 ============== */
/* overload >> */
std::istream & operator>>(std::istream & is, complex_my & c) {
    double r, i;
    std::cout << "real: ";
    if (is >> r) {
        std::cout << "imaginary: ";
        if (is >> i)
            c.set_value(r, i);
    }
    return is;
}
/* overload << */
std::ostream & operator<<(std::ostream & os, const complex_my & c) {
    os << "(" << c.real << "," << c.imaginary << "i)";
    return os;
}






