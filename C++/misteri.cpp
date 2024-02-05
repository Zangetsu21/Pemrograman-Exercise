#include <iostream>
using namespace std;

class Misteri {
    int result;
    public:
    Misteri (int n) { result = n; }
    void func1 (int n) { result = func2(result,n); }
    int func2 (int a, int b) { if (a < b) return a; return b; }
    int getResult() { return result; }
};

int main () {
    Misteri a(15);
    a.func1(35);
    a.func1(30);
    a.func1(20);
    cout << a.getResult() << endl;
    return 0;
}