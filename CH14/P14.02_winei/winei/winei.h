#ifndef WINEI_H_INCLUDED
#define WINEI_H_INCLUDED

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

class Wine : private string, private PairArray {
    private:
        int n;  // number of years
    public:
        Wine() : string("NULL"), n(0), PairArray() {};
        Wine(const char * l, int y, const int yr[], const int bot[]);
        Wine(const char * l, int y);
        void GetBottles();
        string & Label();
        int Sum() const;
        void Show() const;
};

#endif // WINEI_H_INCLUDED
