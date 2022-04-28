#include "stack.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    /* stack creating */
    int num;
    cout << "1. Tesing stack creating ======================\n";
    cout << "Please input the size of the Stack(0 ~ 10): " << endl;
    while (!(cin >> num)) {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Wrong input! Please enter an integer(0~10): ";
    }
    Stack myStack1(num);    // equals to: "Stack myStack = Stack(num);"
    /* push and pop */
    cout << "2. Now testing push and pop ======================\n";
    cout << "Enter an item to push into the Stack(invalid input to quit): ";
    Item temp;
    while ((cin >> temp) && myStack1.push(temp)) {
        if (myStack1.isfull())
            break;
        cout << "Enter next value: ";
    }

    if (myStack1.pop(temp))
        cout << "Poping out the last item: " << temp << endl;
    else
        cout << "The stack is empty, we cannot show you the last item." << endl;
    /* copy constructor and assignment operator */
    cout << "3. Now testing copy constructor and assignment operator ======================\n";
    Stack myStack2(myStack1);
    Stack myStack3 = myStack1;
    Item show;
    int index = 1;
    cout << "Stack2 from top to bottom:\n";
    while (myStack2.pop(show)) {
        cout << index << ": " << show << endl;
        index++;
    }
    index = 1;
    cout << "Stack3 from top to bottom:\n";
    while (myStack3.pop(show)) {
        cout << index << ": " << show << endl;
        index++;
    }
    if (myStack2.isempty() && myStack3.isempty())
        cout << "Now myStack2 and myStack3 are both empty.\n";

    cout << "DONE!";
    return 0;
}
