// implementation of winei.h
#include "winei.h"

/* ================== static functions ================== */
static int get_int() {
    int n;
    while (!(cin >> n)) {
        cout << "WRONG INPUT! Please enter an integer: ";
        while (cin.get() != '\n')
            continue;
    }
    return n;
}


/* ================== constructors ================== */
Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : string(l), n(y), Pair(ArrayInt(yr, y), ArrayInt(bot, y)) {}

Wine::Wine(const char * l, int y)
    : string(l), n(y), Pair(ArrayInt(0, y), ArrayInt(0, y)) {}


/* ================== public methods ================== */
void Wine::GetBottles() {
    // if no year input
    if (n == 0)
        exit(EXIT_FAILURE);
    // prompt the user to enter the info
    ArrayInt temp_years(n);
    ArrayInt temp_bottles(n);
    cout << "Enter " << (string &) *this << " data for " << n << " year(s):\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter year: ";
        temp_years[i] = get_int();
        cout << "Enter bottles for that year: ";
        temp_bottles[i] = get_int();
    }
    // initialize the years and bottles
    for (int i = 0; i < n; i++) {
        Pair::first()[i] = temp_years[i];
        Pair::second()[i] = temp_bottles[i];
    }
}

string & Wine::Label() {    // you cannot use const here because the reutrn type is
                            // a reference which means potential value changing
    return (string &)(*this);
}

int Wine::Sum() const {
    int temp = 0;
    for (int i = 0; i < n; i++)
        temp += Pair::second()[i];
    return temp;
}

void Wine::Show() const {
    cout << "Wine: " << (string &)(*this) << endl;
    cout << "      " << "YEAR       " << "Bottles" << endl;
    for (int i = 0; i < n; i++)
        cout << "      " << Pair::first()[i]
             << "       " << Pair::second()[i] << endl;
}
