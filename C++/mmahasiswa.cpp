#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Orang {
  protected:
    string nama;
    int usia;
  public:
    Orang(string n, int u) {
        nama = n;
        usia = u;
    }
};

class Mahasiswa : public Orang {
  private:
    string nim;
    double total_sks = 0;
    double total_bobot = 0;
    vector<pair<string, pair<int, char>>> daftar_nilai;
  public:
    Mahasiswa(string n, int u, string i) : Orang(n, u) {
        nim = i;
    }
    void tambah_nilai(string kode_mk, int sks, char huruf_mutu) {
        daftar_nilai.push_back(make_pair(kode_mk, make_pair(sks, huruf_mutu)));
        total_sks += sks;
        total_bobot += sks * (4 - (huruf_mutu - 'A'));
    }
    double hitung_ipk() {
        if (total_sks == 0) {
            return 0;
        } else {
            return total_bobot / total_sks;
        }
    }
    void tampilkan() {
        cout << nama << " (" << nim << "):";
        cout << total_sks << ":";
        cout << fixed << setprecision(2) << hitung_ipk() << endl;
    }
};

int main() {
    string nama, nim, kode_mk;
    int usia, sks;
    char huruf_mutu;
    cin >> nama >> usia >> nim;

    Mahasiswa mhs(nama, usia, nim);

    while (cin >> kode_mk >> sks >> huruf_mutu) {
        mhs.tambah_nilai(kode_mk, sks, huruf_mutu);
    }

    mhs.tampilkan();

    return 0;
}
