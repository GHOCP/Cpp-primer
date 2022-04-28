#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

class complex_my {
    /* ======= private part ======= */
    private:
        double real;
        double imaginary;
    /* ======= public part ======= */
    public:
        /* 1. constructors, destructors, value setting and displaying*/
        complex_my();
        complex_my(double r, double i);
        ~complex_my();
        void set_value(double r, double i);
        void show() const;

        /* 2. functions for complex operations */
        complex_my operator+(const complex_my & c) const; // addition
        complex_my operator-(const complex_my & c) const; // subtraction
        complex_my operator*(const complex_my & c) const; // multiplication
        complex_my operator~() const; // conjugation

        /* 3. overload the * (x a real number) */
        friend complex_my operator*(const double x, const complex_my & c);
        friend complex_my operator*(const complex_my & c, const double x);

        /* 4. overload the cout and cin with friend functions */
        friend std::istream & operator>>(std::istream & is, complex_my & c);
        friend std::ostream & operator<<(std::ostream & os, const complex_my & c);
};


#endif // COMPLEX_H_INCLUDED
