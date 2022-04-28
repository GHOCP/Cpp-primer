/*
    Write a program using nested loops that asks the user to enter a value for the
    number of rows to display. It should then display that many rows of asterisks, with
    one asterisk in the first row, two in the second row, and so on. For each row, the
    asterisks are preceded by the number of periods needed to make all the rows
    display a total number of characters equal to the number of rows.A sample run
    would look like this:

    Enter number of rows: 5
    ....*
    ...**
    ..***
    .****
    *****
*/

#include <iostream>

int main() {

    using namespace std;
    int i_p;
    int i_a;
    int num;

    cout << "Enter number of rows: ";
    cin >> num;

    i_p = num -1;
    i_a = 1;
    for (int i = 0 ; i < num; i++, i_p--, i_a++) {
        for (int j = 0; j < i_p; j++)
            cout << ". ";
        for (int j = 0; j < i_a; j++)
            cout << "* ";
        cout << endl;
    }

    return 0;
}
