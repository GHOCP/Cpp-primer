#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

// stack.h -- class definition for the stack ADT
typedef unsigned long Item;
class Stack {
    private:
        enum {MAX = 10}; // constant specific to class
        Item items[MAX]; // holds stack items
        int top; // index for top stack item
    public:
        Stack();
        bool isempty() const;
        bool isfull() const;
    // push() returns false if stack already is full, true otherwise
        bool push(const Item & item); // add item to stack
    // pop() returns false if stack already is empty, true otherwise
        bool pop(Item & item); // pop top into item
};

#endif // STACK_H_INCLUDED
