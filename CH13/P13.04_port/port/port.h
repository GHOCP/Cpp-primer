/*
    The Show() method presents information in the following format:

    Brand: Gallo
    Kind: tawny
    Bottles: 20

    The operator<<() function presents information in the following format (with no
    newline character at the end):

    Gallo, tawny, 20
    ------------------

    You get the job of completing the VintagePort work.

    a. Your first task is to re-create the Port method definitions because the former
    Portmaster immolated his upon being relieved.

    b. Your second task is to explain why certain methods are redefined and others
    are not.

    c. Your third task is to explain why operator=() and operator<<() are not
    virtual.

    d. Your fourth task is to provide definitions for the VintagePort methods.
*/
#ifndef PORT_H_INCLUDED
#define PORT_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;

class Port {
    private:
        char * brand;
        char style[20]; // i.e., tawny, ruby, vintage
        int bottles;
    public:
        Port(const char * br = "none", const char * st = "none", int b = 0);
        Port(const Port & p); // copy constructor
        virtual ~Port() {
            delete [] brand;
        }
        Port & operator=(const Port & p);
        Port & operator+=(int b); // adds b to bottles
        Port & operator-=(int b); // subtracts b from bottles, if available
        int BottleCount() const {
            return bottles;
        }
        virtual void Show() const;
        friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port { // style necessarily = "vintage"
    private:
        char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
        int year; // vintage year
    public:
        VintagePort();
        VintagePort(const char * br, int b, const char * nn, int y);
        VintagePort(const VintagePort & vp);
        ~VintagePort() {
            delete [] nickname;
        }
        VintagePort & operator=(const VintagePort & vp);
        virtual void Show() const;
        friend ostream & operator<<(ostream & os, const VintagePort & vp);
};
#endif // PORT_H_INCLUDED
