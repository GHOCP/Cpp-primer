#ifndef WINE_H_INCLUDED
#define WINE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <string>
#include <valarray>

using std::valarray;
using std::string;
using std::cin;
using std::cout;
using std::endl;

/* ================== Pair object ================== */
template <class T1, class T2>
class Pair {
    private:
        T1 a;
        T2 b;
    public:
        T1 & first();
        T2 & second();
        T1 first() const {
            return a;
        }
        T2 second() const {
            return b;
        }
        Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
        Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first() {
    return a;
}

template<class T1, class T2>
T2 & Pair<T1,T2>::second() {
    return b;
}



/* ================== Wine object ================== */
typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine {
    private:
        // name of the wine
        string name;
        // number of years;
        int n;
        // vintages years and numbers of bottles
        PairArray year_bottle;

    public:
        // default constructor
        Wine() : name("NULL"), n(0), year_bottle() {};
        // initialize label to l, number of years to y,
        // vintage years to yr[], bottles to bot[]
        Wine(const char * l, int y, const int yr[], const int bot[]);
        // initialize label to l, number of years to y,
        // create array objects of length y
        Wine(const char * l, int y);

        // given a Wine object with y years, prompts the user to
        // enter the corresponding number of vintage years and
        // bottle counts
        void GetBottles();
        // return a reference to the wine name
        string & Label();
        // return the total number of bottles
        int Sum() const;
        // display all the info
        void Show() const;
};

#endif // WINE_H_INCLUDED
