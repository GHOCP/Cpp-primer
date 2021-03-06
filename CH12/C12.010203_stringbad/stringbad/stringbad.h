#ifndef STRINGBAD_H_INCLUDED
#define STRINGBAD_H_INCLUDED

// strngbad.h -- flawed string class definition
#include <iostream>
class StringBad {
    private:
        char * str; // pointer to string
        int len; // length of string
        static int num_strings; // number of objects
    public:
        StringBad(const char * s); // constructor
        StringBad(); // default constructor
        ~StringBad(); // destructor
        // friend function
        friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif // STRINGBAD_H_INCLUDED
