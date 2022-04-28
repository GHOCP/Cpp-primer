#include <iostream>
#include <cstring>
#include "cow.h"
/*
using std::strlen;
using std::strcpy;
*/

/* default constructor */
Cow::Cow() {
    strcpy(name, "Empty Cow");  // default name(char array)
    hobby = new char[1];    // default hobby(pc)
    hobby[0] = '\0';
    weight = 0;
}
/* my constructor */
Cow::Cow(const char * name_, const char * hobby_, double weight_) {
    strcpy(name, name_);
    hobby = new char[strlen(hobby_) + 1];
    strcpy(hobby, hobby_);
    weight = weight_;
}
/* copy constructor */
Cow::Cow(const Cow & c) {
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
/* destructor */
Cow::~Cow() {
    delete [] hobby;
}
/* assignment operator */
Cow & Cow::operator=(const Cow & c) {
    if (this == &c)
        return *this;
    else {
        strcpy(name, c.name);
        weight = c.weight;
        delete [] hobby;
        hobby = new char[strlen(c.hobby) + 1];
        strcpy(hobby, c.hobby);
        return *this;
    }
}
/* display the info of cow */
void Cow::ShowCow() const {
    cout << name << " likes " << hobby << ", "
         << "weighting in " << weight << endl;
}
