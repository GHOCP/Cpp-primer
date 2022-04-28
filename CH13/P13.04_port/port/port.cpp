#include "port.h"
#include <iostream>
using namespace std;

/* ================== defintion of Port ================== */

/* consctructor */
Port::Port(const char * br, const char * st, int b) {
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}
/* copy constructor */
Port::Port(const Port & p) {
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}
/* assignment operator */
Port & Port::operator=(const Port & p) {
    if (this == &p)
        return *this;
    //
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    for (int i = 0; i < 20; i++)
        style[i] = '\0';
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}
/* add b to bottles */
Port & Port::operator+=(int b) {
    bottles += b;
    return *this;
}
/* subtracts b from bottles, if available */
Port & Port::operator-=(int b) {
    if (b <= bottles)
        bottles -= b;
    else
        cout << "No enough bottles\n";
    return *this;
}
/*
    Brand: Gallo
    Kind: tawny
    Bottles: 20
*/
void Port::Show() const {
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}
/*
    Gallo, tawny, 20
*/
ostream & operator<<(ostream & os, const Port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles << endl;
    return os;
}



/* ================== defintion of VintagePort ================== */

/* default consctructor */
VintagePort::VintagePort() : Port("none", "vintage", 0) {
    nickname = new char[strlen("none") + 1];
    strcpy(nickname, "none");
    year = 0;
}
/* consctructor */
VintagePort::VintagePort(const char * br, int b, const char * nn, int y) :
                        Port(br, "vintage", b) {
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}
/* copy consctructor */
VintagePort::VintagePort(const VintagePort & vp) : Port(vp) {
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
/* assignment operator - redefinition hiding */
VintagePort & VintagePort::operator=(const VintagePort & vp) {
    if (this == &vp)
        return *this;
    //
    Port::operator=(vp);
    //
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}
/* display the info */
void VintagePort::Show() const {
    cout << "nickname: " << nickname << endl;
    cout << "year: " << year << endl;
    Port::Show();
}
/* << overloading */
ostream & operator<<(ostream & os, const VintagePort & vp) {
    os << Port(vp); // pay attention to the explicit conversion !!!
    os << vp.nickname << ", " << vp.year << endl;
    return os;
}


