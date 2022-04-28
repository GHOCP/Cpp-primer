#include "cd.h"

/* ============== basse class implementation ============== */

/* self-made constructor */
Cd::Cd(char * s1, char * s2, int n, double x) {
    //
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    //
    selections = n;
    playtime = x;
}
/* copy constructor */
Cd::Cd(const Cd & d) {
    //
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    //
    selections = d.selections;
    playtime = d.playtime;
}
/* destructor */
Cd::~Cd() {
    delete [] performers;
    delete [] label;
}
/* reports all CD data */
void Cd::Report() const {
    cout << "PERFORMERS: " << performers << endl;
    cout << "LABEL:      " << label << endl;
    cout << "SELECTIONS: " << selections << endl;
    cout << "PLAYTIME:   " << playtime << endl;
}
/* assignment operator */
Cd & Cd::operator=(const Cd & d) {
    if (this == &d)
        return *this;
    //
    delete [] performers;
    delete [] label;
    //
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    //
    return *this;
}



/* ============== derived class implementation ============== */

/* self-made constructor */
Classic::Classic(char * s1, char * s2, char * s3, int n, double x)
                : Cd(s1, s2, n, x) {
    primary = new char[strlen(s3) + 1];
    strcpy(primary, s3);
}
/* copy constructor */
Classic::Classic(const Classic & cla) : Cd(cla) {
    primary = new char[strlen(cla.primary) + 1];
    strcpy(primary, cla.primary);
}
/* destructor */
Classic::~Classic() {
    delete [] primary;
}
/* reports all CD data for derived class*/
void Classic::Report() const {
    Cd::Report();
    cout << "PRIMARY:    " << primary << endl;
}
/* assignment operator */
Classic & Classic::operator=(const Classic & cla) {
    if (this == &cla)
        return *this;
    //
    Cd::operator=(cla);
    //
    delete [] primary;
    primary = new char[strlen(cla.primary) + 1];
    strcpy(primary, cla.primary);
    return *this;
}
