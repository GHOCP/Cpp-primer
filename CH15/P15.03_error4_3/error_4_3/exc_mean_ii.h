#ifndef EXC_MEAN_II_H_INCLUDED
#define EXC_MEAN_II_H_INCLUDED

/*
    This exercise is the same as Programming Exercise 2, except that the exceptions
    should be derived from a base class (itself derived from logic_error) that stores the
    two argument values, the exceptions should have a method that reports these values
    as well as the function name, and a single catch block that catches the base-class
    exemption should be used for both exceptions, with either exception causing the
    loop to terminate.
*/

#include <iostream>
#include <stdexcept>

class my_error : public std::logic_error {
    private:
        double v1;
        double v2;
    public:
        explicit my_error(double a = 0, double b = 0)
            : logic_error("NULL"), v1(a), v2(b) {}
        virtual void mesg() const = 0;  // a pure virtual function
        double show_v1() const {return v1;}
        double show_v2() const {return v2;}
};

class bad_hmean : public my_error {
    public:
        explicit bad_hmean(double a, double b)
            : my_error(a, b) {}
        virtual void mesg() const;
};

inline void bad_hmean::mesg() const {
    std::cout << "hmean(" << my_error::show_v1() << ", " << my_error::show_v2() <<"): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public my_error {
    public:
        explicit bad_gmean(double a = 0, double b = 0)
            : my_error(a, b) {}
        virtual void mesg() const;
};

inline void bad_gmean::mesg() const {
    std::cout << "gmean() arguments should be >= 0\n";
}

#endif // EXC_MEAN_II_H_INCLUDED
