/*
    The CandyBar structure contains three members.The first member holds the brand
    name of a candy bar.The second member holds the weight (which may have a fractional
    part) of the candy bar, and the third member holds the number of calories
    (an integer value) in the candy bar.Write a program that uses a function that takes
    as arguments a reference to CandyBar, a pointer-to-char, a double, and an int and
    uses the last three values to set the corresponding members of the structure.The last
    three arguments should have default values of ¡°Millennium Munch,¡± 2.85, and 350.
    Also the program should use a function that takes a reference to a CandyBar as an
    argument and displays the contents of the structure. Use const where appropriate.
*/

#include <iostream>
#include <cstring>
#define arrSize 20
struct CandyBar {
    char brand_name[20];
    double weight;
    int calories;
};

void iniCandyBar(CandyBar &,
                char * arr = "Millennium Munch",
                double d1 = 2.85,i
                int num = 350);

void showCandyBar(const CandyBar &);

int main() {
    using namespace std;
    CandyBar myCandyBar1;
    CandyBar myCandyBar2;
    CandyBar & myCandyBarRef1 = myCandyBar1;
    CandyBar & myCandyBarRef2 = myCandyBar2;

    /* initialization */
    iniCandyBar(myCandyBarRef1);
    iniCandyBar(myCandyBarRef2, "OCPP Prod.Otd", 3.06, 200);

    /* info displaying */
    showCandyBar(myCandyBarRef1);
    showCandyBar(myCandyBarRef2);

    return 0;
}

void iniCandyBar(CandyBar & myCandy, char * arr, double d1, int num) {
    strcpy(myCandy.brand_name, arr);
    myCandy.weight = d1;
    myCandy.calories = num;
}

void showCandyBar(const CandyBar & myCandy) {
    using namespace std;
    cout << myCandy.brand_name << ": "
         << myCandy.weight << ", "
         << myCandy.calories << endl;
}
