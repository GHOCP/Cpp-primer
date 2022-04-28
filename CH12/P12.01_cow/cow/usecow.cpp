#include <iostream>
#include "cow.h"

int main() {
    Cow c1;
    Cow c2("Flippi", "Running around", 25.2);
    Cow c3 = Cow("Octopus", "Sleeping all day", 30.2);
    Cow c4 = c3;
    Cow c5;
    c5 = c2;
    c1.ShowCow();
    c2.ShowCow();
    c3.ShowCow();
    c4.ShowCow();
    c5.ShowCow();
    return 0;
}
