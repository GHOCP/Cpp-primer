#include <iostream>
#include "tvmf.h"

int main() {
    using namespace std;
    Tv s42;
    Remote grey;
    //
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();
    cout << "Try to use off Tv to toggle the remote state:\n";
    s42.modetoggle(grey);
    //
    s42.onoff();
    s42.chanup();
    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    //
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();
    grey.showstate();
    cout << "Try to toggle the remote state again:\n";
    s42.modetoggle(grey);
    //
    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58,28);
    cout << "\n58\" settings:\n";
    s58.settings();

    return 0;
}
