#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

class Ruang2D {
protected:
    int sisi1, sisi2, sisi3, sisi4;
public:
    virtual double luas() = 0;
    virtual double keliling() = 0;
    void set(int s1 = 0, int s2 = 0, int s3 = 0, int s4 = 0) {
        sisi1 = s1; sisi2 = s2; sisi3 = s3; sisi4 = s4;
    }
};

class Segiempat : public Ruang2D {
public:
    double luas() {
        return sisi1 * sisi2;
    }
    double keliling() {
        return (sisi1 + sisi2 + sisi3 + sisi4)*1.0;
    }
};

class Segitiga : public Ruang2D {
public:
    double luas() {
        return 0.5 * sisi1 * sisi2;
    }
    double keliling() {
        return (sisi1 + sisi2 + sqrt(sisi1 * sisi1 + sisi2 * sisi2))*1.0;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<Segiempat> segiempat(m);
    for (int i = 0; i < m; i++) {
        int p, l;
        cin >> p >> l;
        segiempat[i].set(p, l, p, l);
    }

    vector<Segitiga> segitiga(n);
    for (int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> t;
        segitiga[i].set(a, t, 0, 0);
    }

    sort(segiempat.begin(), segiempat.end(), [](Segiempat a, Segiempat b) {
        if (a.luas() == b.luas()) {
            return a.keliling() > b.keliling();
        }
        return a.luas() > b.luas();
    });

    sort(segitiga.begin(), segitiga.end(), [](Segitiga a, Segitiga b) {
        if (a.luas() == b.luas()) {
            return a.keliling() > b.keliling();
        }
        return a.luas() > b.luas();
    });

    cout << "SEGIEMPAT" << endl;
    for (auto s : segiempat) {
        cout << setprecision(1) << fixed << s.luas() << " " <<  s.keliling() << endl;
    }

    cout << "SEGITIGA" << endl;
    for (auto s : segitiga) {
        cout << setprecision(1) << fixed << s.luas() << " " << s.keliling() << endl;
    }

    return 0;
}
