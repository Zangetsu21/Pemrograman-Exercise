#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Kalori {
protected:
    string nama;
    int beratGula;
    int beratKarbohidrat;

public:
    Kalori(string n, int g, int k) {
        nama = n;
        beratGula = g;
        beratKarbohidrat = k;
    }

    virtual int hitungKalori() = 0;

    string getNama() {
        return nama;
    }

    int getBeratGula() {
        return beratGula;
    }

    int getBeratKarbohidrat() {
        return beratKarbohidrat;
    }
};

class KaloriKalori : public Kalori {
public:
    KaloriKalori(string n, int g, int k) : Kalori(n, g, k) {}

    int hitungKalori() {
        return 50 * beratGula + 20 * beratKarbohidrat;
    }
};

class KaloriNutrisi : public Kalori {
public:
    KaloriNutrisi(string n, int g, int k) : Kalori(n, g, k) {}

    int hitungKalori() {
        return 20 * beratGula + 10 * beratKarbohidrat;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Kalori*> daftarKalori;
    for (int i = 0; i < n; i++) {
        string nama, jenis;
        int g, k;
        cin >> nama >> jenis >> g >> k;

        if (jenis == "Kalori") {
            daftarKalori.push_back(new KaloriKalori(nama, g, k));
        }
        else {
            daftarKalori.push_back(new KaloriNutrisi(nama, g, k));
        }
    }

    int totalKalori = 0;
    vector<string> daftarKaloriKaloriTinggi;
    for (Kalori* Kalori : daftarKalori) {
        totalKalori += Kalori->hitungKalori();
        if (Kalori->hitungKalori() > 1000) {
            daftarKaloriKaloriTinggi.push_back(Kalori->getNama());
        }
    }

    cout << totalKalori << endl;
    for (string namaKalori : daftarKaloriKaloriTinggi) {
        cout << namaKalori << endl;
    }

    for (Kalori* Kalori : daftarKalori) {
        delete Kalori;
    }
    return 0;
}
