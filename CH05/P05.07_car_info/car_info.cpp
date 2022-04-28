/*
    Design a structure called car that holds the following information about an automobile:
    its make, as a string in a character array or in a string object, and the year
    it was built, as an integer.Write a program that asks the user how many cars to catalog.
    The program should then use new to create a dynamic array of that many car
    structures. Next, it should prompt the user to input the make (which might consist
    of more than one word) and year information for each structure. Note that this
    requires some care because it alternates reading strings with numeric data (see
    Chapter 4). Finally, it should display the contents of each structure.A sample run
    should look something like the following:

    How many cars do you wish to catalog? 2
    Car #1:
    Please enter the make: Hudson Hornet
    Please enter the year made: 1952
    Car #2:
    Please enter the make: Kaiser
    Please enter the year made: 1951
    Here is your collection:
    1952 Hudson Hornet
    1951 Kaiser
*/
#include <iostream>
#include <string>
#define SIZE 15
struct car {
    char make[SIZE];
    int year_built;
};

int main() {

    using namespace std;
    int num;

    cout << "How many cars do you wish to catalog? ";
    cin >> num;
    cin.get();  // abandon the trivial ENTER

    /* tip the user to enter info */
    car * p_car = new car[num];   // creating the car array using new
    for (int i = 0; i < num; i++) {
        cout << "Car #" << i + 1 << ":" << endl;
        cout << "Please enter the make: ";
        cin.get(p_car[i].make, SIZE);
        cout << "Please enter the year made: ";
        cin >> p_car[i].year_built;
        cin.get();  // abandon the trivial ENTER
    }

    /* display the info */
    cout << "Here is your collection:" << endl;
    for (int i = 0; i < num; i++)
        cout << p_car[i].year_built << " " << p_car[i].make << endl;

    delete [] p_car;    // free the memory
    return 0;
}
