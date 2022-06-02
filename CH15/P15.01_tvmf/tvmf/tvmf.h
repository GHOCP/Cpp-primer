#ifndef TVMF_H_INCLUDED
#define TVMF_H_INCLUDED

class Remote;   // forwad declaration

class Tv {
    public:
        friend class Remote; // Remote can access Tv private parts
        enum {Off, On};
        enum {MinVal,MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        Tv(int s = Off, int mc = 125) : state(s), volume(5),
            maxchannel(mc), channel(2), mode(Cable), input(TV) {}
        void onoff() {
            state = (state == On)? Off : On;
        }
        bool ison() const {
            return state == On;
        }
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode() {
            mode = (mode == Antenna)? Cable : Antenna;
        }
        void set_input() {
            input = (input == TV)? DVD : TV;
        }
        void settings() const; // display all settings
        void modetoggle(Remote & r);  // toggling the Remote member's mode
    private:
        int state; // on or off
        int volume; // assumed to be digitized
        int maxchannel; // maximum number of channels
        int channel; // current channel setting
        int mode; // broadcast or cable
        int input; // TV or DVD
};

class Remote {
    private:
        int mode; // controls TV or DVD
        int state;  // normal or interactive
    public:
        friend class Tv;
        enum {normal, interactive};   // whether the remote control is in normal or interactive mode
        Remote(int m = Tv::TV, int s = normal) : mode(m), state(s) {}
        bool volup(Tv & t);
        bool voldown(Tv & t);
        void onoff(Tv & t);
        void chanup(Tv & t);
        void chandown(Tv & t);
        void set_chan(Tv & t, int c);
        void set_mode(Tv & t);
        void set_input(Tv & t);
        void showstate() const;
};

/* inline Tv function */
inline void Tv::modetoggle(Remote & r) {
    using std::cout;
    using std::endl;
    if (state == On) {
        r.state = (r.state == Remote::normal? Remote::interactive : Remote::normal);
        cout << "Successfully change the remote state." << endl;
        r.showstate();
    }

    else
        cout << "======= Sorry, TV's off now. You cannot set the remote state. =======" << endl;
}

/* Remote methods as inline functions */
inline bool Remote::volup(Tv & t) {
    return t.volup();
}
inline bool Remote::voldown(Tv & t) {
    return t.voldown();
}
inline void Remote::onoff(Tv & t) {
    t.onoff();
}
inline void Remote::chanup(Tv & t) {
    t.chanup();
}
inline void Remote::chandown(Tv & t) {
    t.chandown();
}
inline void Remote::set_mode(Tv & t) {
    t.set_mode();
}
inline void Remote::set_input(Tv & t) {
    t.set_input();
}
inline void Remote::set_chan(Tv & t, int c) {
    t.channel = c;
}
inline void Remote::showstate() const {
    using std::cout;
    using std::endl;
    cout << "======= Remote state: " << (state == normal? "Normal =======" : "Interactive =======") << endl;
}



#endif // TVMF_H_INCLUDED
