#include <iostream>
#include <iomanip>
using namespace std;
int main () {
    int n, k, angka, i=0;
    double rataan;
    cin >> n
        >> k;
    for (int counter = 1; counter<=n; counter++) {
        cin >> angka;
        if(counter % k == 0) {
            rataan += double (angka);
            i++;
        }
    }
    if (k > n || n == 0 || k == 0) {
        double nilai = 0.00;
        cout.precision(2);
        cout << fixed << nilai << endl;
    } else {
        rataan = rataan / (n/k);
        cout.precision(2);
        cout << fixed << rataan << endl;
    }
    return 0;      
}