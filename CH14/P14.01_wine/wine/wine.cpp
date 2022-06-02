// implementation of wine.h
#include "wine.h"

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
/*
    remember to instantiate the contained object first, before you
    use the constructors to give them values:
    -- year_bottle(ArrayInt(y), ArrayInt(y))
*/
Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : name(l), n(y), year_bottle(ArrayInt(yr, y), ArrayInt(bot, y)) {
    /*
    for (int i = 0; i < y; i++) {
        year_bottle.first()[i] = yr[i];
        year_bottle.second()[i] = bot[i];
    }
    */
    // year_bottle(temp_years, temp_bottles); this is wrong
}

Wine::Wine(const char * l, int y)
    : name(l), n(y), year_bottle(ArrayInt(0, y), ArrayInt(0, y)) {
    /*
    for (int i = 0; i < y; i++) {
        year_bottle.first()[i] = 0;
        year_bottle.second()[i] = 0;
    }
    */
}

/* ================== public methods ================== */
void Wine::GetBottles() {
    // if no year input
    if (n == 0)
        exit(EXIT_FAILURE);
    // prompt the user to enter the info
    ArrayInt temp_years(n);
    ArrayInt temp_bottles(n);
    cout << "Enter " << name << " data for " << n << " year(s):\n";
    for (int i = 0; i < n; i ++) {
        cout << "Enter year: ";
        temp_years[i] = get_int();
        cout << "Enter bottles for that year: ";
        temp_bottles[i] = get_int();
    }
    // initialize the years and bottles
    for (int i = 0; i < n; i++) {
        year_bottle.first()[i] = temp_years[i];
        year_bottle.second()[i] = temp_bottles[i];
    }
}

string & Wine::Label() {    // you cannot use const here because the reutrn type is
                            // a reference which means potential value changing
    return name;
}

int Wine::Sum() const {
    int temp = 0;
    for (int i = 0; i < n; i++)
        temp += year_bottle.second()[i];
    return temp;
}

void Wine::Show() const {
    cout << "Wine: " << name << endl;
    cout << "      " << "YEAR       " << "Bottles" << endl;
    for (int i = 0; i < n; i++)
        cout << "      " << year_bottle.first()[i]
             << "       " << year_bottle.second()[i] << endl;
}
