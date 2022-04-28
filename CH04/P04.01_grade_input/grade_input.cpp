/*
    Write a C++ program that requests and displays information as shown in the following
    example of output:
    What is your first name? Betty Sue
    What is your last name? Yewe
    What letter grade do you deserve? B
    What is your age? 22
    Name: Yewe, Betty Sue
    Grade: C
    Age: 22
    Note that the program should be able to accept first names that comprise more
    than one word. Also note that the program adjusts the grade downward¡ªthat is, up
    one letter.Assume that the user requests an A, a B, or a C so that you don¡¯t have to
    worry about the gap between a D and an F.
*/

#include <iostream>
#define SIZE 20

int main() {

    using namespace std;
    char * pc1 = new char[SIZE]; // First name input
    char * pc2 = new char[SIZE]; // Last name input
    char grade; // grade input
    int age;    // age input

    /* request and store the info */
    cout << "What is your first name? ";
    cin.get(pc1, SIZE-1).get();
    cout << "What is your last name? ";
    cin.get(pc2, SIZE-1).get();
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;

    /* display the info */
    cout << "Name: " << pc2 << ", " << pc1 << endl;
    grade = grade + 1;
    cout << grade << endl;
    cout << age;

    /* free the memory */
    delete pc1;
    delete pc2;

    return 0;
}
