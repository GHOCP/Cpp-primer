#include "port.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Testing base class Port ==========================\n";
    Port p1("Gallo", "tawny", 20);
    Port p2;
    /* info display */
    cout << "1. The info of port1 and port2:\n";
    p1.Show();
    p2.Show();
    /* assignment */
    cout << "2. After assign port1 to port2, port2 is:\n";
    p2 = p1;
    cout << p2;
    /* add and substract */
    cout << "3. Add 10 to port1:\n";
    p1 += 10;
    cout << p1;
    cout << "4. Subract 40 from port1:\n";
    p1-= 40;
    cout << p1;

    cout << "Testing derived class VintagePort ==========================\n";
    VintagePort v1("Maotai", 20, "Old Velvet", 1989);
    VintagePort v2;
    /* info display */
    cout << "1. The info of v1 and v2:\n";
    v1.Show();
    v2.Show();
    /* assignment */
    cout << "2. After assign v1 to v2, v2 is:\n";
    v2 = v1;
    cout << v2;
    /* add and substract */
    cout << "3. Add 10 to v1:\n";
    v1 += 10;
    cout << v1;
    cout << "4. Subract 20 from v1:\n";
    v1-= 20;
    cout << v1;

    return 0;
}
