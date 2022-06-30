//error4_3.cpp using exception classes
#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include "exc_mean_ii.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try { // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block

        catch (my_error & p_err) {
            /*
            // RTTI version
            bad_hmean * p_h;
            bad_gmean * p_g;
            if (p_h = dynamic_cast<bad_hmean *>(&p_err))
                p_h -> mesg();
            else if (p_g = dynamic_cast<bad_gmean *>(&p_err))
                p_g -> mesg();
            else
                cout << "UNKNOWN ERRORS\n";
            */
            p_err.mesg();
            break;
        }
        /*
        // the origin version
        catch (bad_hmean & bg) { // start of catch block
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean & hg) {
            hg.mesg();
            cout << "Values used: " << x << ", "
                 << y << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
        */
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) {
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) {
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

