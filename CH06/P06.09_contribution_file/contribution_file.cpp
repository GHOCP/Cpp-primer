/*
    Put together a program that keeps track of monetary contributions to the Society
    for the Preservation of Rightful Influence. It should ask the user to enter the number
    of contributors and then solicit the user to enter the name and contribution of
    each contributor.The information should be stored in a dynamically allocated array
    of structures. Each structure should have two members: a character array (or else a
    string object) to store the name and a double member to hold the amount of the
    contribution.After reading all the data, the program should display the names and
    amounts donated for all donors who contributed $10,000 or more.This list should
    be headed by the label Grand Patrons.After that, the program should list the
    remaining donors.That list should be headed Patrons. If there are no donors in one
    of the categories, the program should print the word ¡°none.¡±Aside from displaying
    two categories, the program need do no sorting.

    Do the above exercise but modify it to get information from a file.The first
    item in the file should be the number of contributors, and the rest of the file should
    consist of pairs of lines, with the first line of each pair being a contributor¡¯s name
    and the second line being a contribution.That is, the file should look like this:

    4
    Sam Stone
    2000
    Freida Flass
    100500
    Tammy Tubbs
    5000
    Rich Raptor
    55000
*/

#include <iostream>
#include <fstream> // file I/O support
#include <cstdlib> // support for exit()
#define SIZE 20

using namespace std;
struct contri_info {
    char name[SIZE];
    double amount;
};
void file_test (ifstream inFile);

int main() {

    /* || open the file */
    char filename[20] = "list.txt";
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "Could not open the file" << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    /* || extract the data from the file */
    int num, index;
    index = 0;
    /* reading the number of members */
    inFile >> num;
    inFile.get();   // abandon the newline

    /* reading the info of members */
    contri_info * p_s = new contri_info[num];
    while (inFile.good()) {
        inFile.get(p_s[index].name, SIZE);
        inFile >> p_s[index].amount;
        inFile.get();   // abandon the newline
        index++;
    }
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

    /* || display the info */
    if (num == 0)
        cout << "No data processed.\n";
    else {
        cout << "The information of the members is:\n";
        for (int i = 0; i < num; i++)
            cout << p_s[i].name << " : " << p_s[i].amount << endl;
    }

    /* || close the file and free memory */
    inFile.close();
    delete [] p_s;

    return 0;
}

void file_test (ifstream inFile) {

}
