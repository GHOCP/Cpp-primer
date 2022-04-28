/* implementations of golf.h */

#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;

void setgolf(golf & g, const char * name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g) {
    /* read in the number of handicap */
    int num;
    cout << "Please enter the number of handicap: ";
    while (!(cin >> num)) {
        cin.clear();    // reset the cin flags
        while (cin.get() != '\n')
            continue;
        cout << "Invalid input, please enter an integer: ";
    }
    cin.get();  // abandon the newline

    /* read in the fullname */
    char name[Len] = "\0";
    cout << "Please enter the full name(empty line to quit): ";
    cin.getline(name, Len); // you need to read the newline
                            // to indicate the empty input
    // when no name enter
    if (name[0] == '\0') {
        while (cin.get() != '\n')
            continue;
        return 0;
    }
    // not empty name
    else {
        while (cin.get() != '\n')
            continue;
        /* using setgolf above to set data */
        setgolf(g, name, num);
        return 1;
    }
}

void handicap(golf & g, int hc) {
    g.handicap = hc;
}

void showgolf(const golf & g) {
    cout << g.fullname << "has " << g.handicap << " handicap(s)" << endl;
}

