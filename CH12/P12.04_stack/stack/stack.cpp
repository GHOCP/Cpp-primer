// stack.cpp -- stack class methods
#include "stack.h"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;

/* a static function that enbale item copying */
static void ItemCopy(Item & a, const Item & b) {
    a = b;
}

/* creates stack with n elements */
Stack::Stack(int n) {
    if (n > MAX)
        exit(EXIT_FAILURE);
    pitems = new Item[MAX];
    size = n;
    top = n - 1;
    // initialize the stack with value input
    if (n == 0)
        cout << "You create a stack with 0 element.\n";
    else {
        Item temp;
        cout << "Enter the value:\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ": ";
            while (!(cin >> temp)) {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "Wrong input! Please enter again: ";
            }
            ItemCopy(*(pitems + i), temp);
        }
    }
}
/* crates stack with another stack */
Stack::Stack(const Stack & st) {
    size = st.size;
    top = st.top;
    pitems = new Item[MAX];
    for (int i = 0; i < st.size; i++)
        *(pitems + i) = *(st.pitems + i);
}
/* desctructor */
Stack::~Stack() {
    delete [] pitems;
}
/* to see if the Stack is empty or not */
bool Stack::isempty() const {
    return (size == 0);
}
/* to see if the Stack is full or not */
bool Stack::isfull() const {
    return (size == MAX);
}

/* returns false if stack already is full, true otherwise */
bool Stack::push(const Item & item) {
    if (this->isfull())
        return false;
    ItemCopy(*(pitems + top + 1), item);
    top += 1;
    size +=1;
    return true;
}
/* returns false if stack already is empty, true otherwise */
bool Stack::pop(Item & item) {
    if (this->isempty())
        return false;
    ItemCopy(item, *(pitems + top));
    top -= 1;
    size -=1;
    return true;
}
/* assignment operator */
Stack & Stack::operator=(const Stack & st) {
    if (this == &st)
        return *this;
    delete [] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[MAX];
    for (int i = 0; i < st.size; i++)
        *(pitems + i) = *(st.pitems + i);
    return *this;
}
