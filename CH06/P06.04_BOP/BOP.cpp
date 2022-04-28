/*
    When you join the Benevolent Order of Programmers, you can be known at BOP
    meetings by your real name, your job title, or your secret BOP name.Write a program
    that can list members by real name, by job title, by secret name, or by a member¡¯s
    preference. Base the program on the following structure:
    // Benevolent Order of Programmers name structure
    struct bop {
    char fullname[strsize]; // real name
    char title[strsize]; // job title
    char bopname[strsize]; // secret BOP name
    int preference; // 0 = fullname, 1 = title, 2 = bopname
    };
    In the program, create a small array of such structures and initialize it to suitable
    values. Have the program run a loop that lets the user select from different alternatives:
    a. display by name b. display by title
    c. display by bopname d. display by preference
    q. quit
    Note that ¡°display by preference¡± does not mean display the preference member; it
    means display the member corresponding to the preference number. For instance, if
    preference is 1, choice d would display the programmer¡¯s job title.A sample run
    may look something like the following:

    Benevolent Order of Programmers Report
    a. display by name b. display by title
    c. display by bopname d. display by preference
    q. quit
    Enter your choice: a
    Wimp Macho
    Raki Rhodes
    Celia Laiter
    Hoppy Hipman
    Pat Hand
    Next choice: d
    Wimp Macho
    Junior Programmer
    MIPS
    Analyst Trainee
    LOOPY
    Next choice: q
    Bye!
*/

#include <iostream>
#include <cstring>
#define SIZE 3
#define strsize 20

char get_choice(void);
struct bop {
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;     // 0 = fullname, 1 = title, 2 = bopname
};

using namespace std;
int main() {

    char ch;
    /* initialize the members' info */
    bop members[SIZE] = {
        {"Wimp Macho", "Senior Programmer", "WMAN", 0},
        {"Raki Rhodes", "Junior Programmer", "HEONG", 1},
        {"Celia Laiter", "Analyst Trainee", "LOOPY", 2}
    };

    /* display the menu */
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name         b. display by title" << endl;
    cout << "c. display by bopname      d. display by preference" << endl;
    cout << "q. quit" << endl;

    /* get choice */
    cout << "Enter your choice: ";
    while ((ch = get_choice()) != 'q') {
        switch (ch) {
            case 'a':
                for (int i = 0; i < SIZE; i++)
                    cout << members[i].fullname << endl;
                break;
            case 'b':
                for (int i = 0; i < SIZE; i++)
                    cout << members[i].title << endl;
                break;
            case 'c':
                for (int i = 0; i < SIZE; i++)
                    cout << members[i].bopname << endl;
                break;
            case 'd':
                for (int i = 0; i < SIZE; i++) {
                    if (members[i].preference == 0)
                        cout << members[i].fullname << endl;
                    else if (members[i].preference == 1)
                        cout << members[i].title << endl;
                    else
                        cout << members[i].bopname << endl;
                }
        }
        cout << "Next choice: ";
    }
    cout << "DONE!";

    return 0;
}

char get_choice(void) {
    char ch;
    while (strchr("abcdq", ch = cin.get()) == NULL) {
        cout << "Wrong Input! Please enter a, b, c, d or q: ";
        while (cin.get() != '\n')   // clear  the left input
            continue;
    }
    while (cin.get() != '\n')   // clear  the left input
        continue;
    return ch;
}

