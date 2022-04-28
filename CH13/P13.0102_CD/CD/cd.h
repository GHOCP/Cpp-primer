#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

// base class
class Cd { // represents a CD disk
    private:
        char * performers;
        char * label;
        int selections; // number of selections
        double playtime; // playing time in minutes
    public:
        Cd(char * s1 = "NULL", char * s2 = "NULL",
           int n = 0, double x = 0);
        Cd(const Cd & d);
        virtual ~Cd();
        virtual void Report() const; // reports all CD data
        Cd & operator=(const Cd & d);
};

// derived clas
class Classic : public Cd {
    private:
        char * primary;
    public:
        Classic(char * s1 = "NULL", char * s2 = "NULL",
                char * s3 = "NULL", int n = 0, double x = 0);
        Classic(const Classic & cla);
        virtual ~Classic();
        virtual void Report() const;
        Classic & operator=(const Classic & cla);
};

#endif // CD_H_INCLUDED
