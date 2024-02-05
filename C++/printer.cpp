#include <iostream>
#include <iomanip>
using namespace std;

class Printer {
    public:
        void print(int i) { cout << "SATU: " << i; }
        void print(double f) { cout << "DUA: " << f; }
        void print(char* c) { cout << "TIGA: " << c; }
};

int main () {
    Printer.print("5");
    return 0;
}