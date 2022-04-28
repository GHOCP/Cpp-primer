/*
    Begin with the following structure declaration:
    struct chaff
    {
        char dross[20];
        int slag;
    };
    Write a program that uses placement new to place an array of two such structures in
    a buffer.Then assign values to the structure members (remembering to use
    strcpy() for the char array) and use a loop to display the contents. Option 1 is to
    use a static array, like that in Listing 9.10, for the buffer. Option 2 is to use regular
    new to allocate the buffer.
*/

#include <iostream>
#include <cstring>
#define LEN 64

char buffer[LEN];
struct chaff {
    char dross[20];
    int slag;
};

int main () {
    using namespace std;
    chaff * ps = new (buffer) chaff[2];
    /* chaff 1 */
    strcpy(ps[0].dross, "NAME_1");
    ps[0].slag = 12;
    /* chaff 2 */
    strcpy(ps[1].dross, "NAME_2");
    ps[1].slag = 13;
    /* info display */
    cout << "The buffer array in " << (void*)buffer << endl;
    cout << "The array in " << ps << endl;
    cout << "Chaff 1 in " << &ps[0] << " : "
         << ps[0].dross << " ," << ps[0].slag << endl;
    cout << "Chaff 2 in " << &ps[1] << " : "
         << ps[1].dross << " ," << ps[1].slag << endl;

    delete [] ps;

    return 0;
}
