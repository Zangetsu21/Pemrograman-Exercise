#include <iostream>
using namespace std;

class Counter {
    private:
    int c;
    public:
        Counter () { c=0; }
        void set (int p) {
            if(p < 0){
                c = 0;
            } else c=p;
        }
        void inc () { c = c+1; }
        void dec () { 
            if(c > 0){
                c = c - 1;
            } 
        }
        void print () {cout << c << endl; }
};

int main () {
    Counter object;
    int a = 0, b;
    while (a != -9) {
        cin >> a;
        switch (a) {
            case 0 : cin >> b; object.set(b); break;
            case 1 : object.inc(); break;
            case -1: object.dec(); break;
            case 9 : object.print(); break;
            default: break;
        }
    }
    return 0;
}