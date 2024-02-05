#include <iostream>
#include <iomanip>
using namespace std;

class Person {
    private:
        string nama;
        int usia, tinggi;
        double berat;
    public:
        Person () { nama = ""; usia = tinggi = 0; berat=0.0; }
        void setPerson (string nama, int usia, int tinggi, double berat) { 
            this -> nama = nama;
            this -> usia = usia;
            this -> tinggi = tinggi;
            this -> berat = berat;
        }
        int getTinggi () { 
            return tinggi;
            }
        void print () { cout << nama << " " << usia << endl; }
};

int main () {
    Person orang[101];
    int n;
    int frekuensi = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        string nama;
        int usia;
        int tinggi;
        double berat;
        cin >> nama >> usia >> tinggi >> berat;
        orang[i].setPerson (nama, usia, tinggi, berat);
    }
    double sum =0;
    for (int i = 0; i < n; i++) {
        sum += orang[i].getTinggi();
    }
    double rata = sum/n;
    for (int i = 0; i < n; i++) {
        if (orang[i].getTinggi() > rata) {
            ++frekuensi;
        }
        orang[i].print();
    }
    cout << setprecision(2) << fixed;
    cout << rata << endl;
    cout << frekuensi << endl;
}