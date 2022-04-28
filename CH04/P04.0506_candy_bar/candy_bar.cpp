/*
    The CandyBar structure contains three members.The first member holds the brand
    name of a candy bar.The second member holds the weight (which may have a fractional
    part) of the candy bar, and the third member holds the number of calories
    (an integer value) in the candy bar.Write a program that declares such a structure
    and creates a CandyBar variable called snack, initializing its members to "Mocha
    Munch", 2.3, and 350, respectively.The initialization should be part of the declaration
    for snack. Finally, the program should display the contents of the snack variable.

    The CandyBar structure contains three members, as described in Programming
    Exercise 5.Write a program that creates an array of three CandyBar structures, initializes
    them to values of your choice, and then displays the contents of each structure.
*/

#include <iostream>
#define SIZE 20
struct candy_bar {
    char name[SIZE];
    float weight;
    int calories;
};

int main() {

    using namespace std;

    /*
        using new to allocate the array dynamically:
        candy_bar * ps = new candy_bar[3];
        ...
        delete [] ps;
    */
    candy_bar myBar[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Aries Flipp", 1.3, 210},
        {"Paore Leo", 4.7, 400}
    };
    cout << "The infos of the candy bars:" << endl;
    cout << "NAME: "<< "WEIGHT / "<<"CALORIES" << endl;
    cout << myBar[0].name << ": " << myBar[0].weight << " / " << myBar[0].calories << endl;
    cout << myBar[1].name << ": " << myBar[1].weight << " / " << myBar[1].calories << endl;
    cout << myBar[2].name << ": " << myBar[2].weight << " / " << myBar[2].calories << endl;

    return 0;
}
