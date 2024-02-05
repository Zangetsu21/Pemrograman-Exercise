#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Barang {
public:
    int id;
    string kelompok;
    string nama;
    int jumlah;

    Barang(int i, string k, string n, int j) {
        id = i;
        kelompok = k;
        nama = n;
        jumlah = j;
    }
};

class Toko {
private:
    vector<Barang> stok;
    map<string, vector<string>> barangPerKelompok;

public:
    void tambahBarang(int id, string kelompok, string nama, int jumlah) {
        Barang barang(id, kelompok, nama, jumlah);
        stok.push_back(barang);
        barangPerKelompok[kelompok].push_back(nama);
    }

    void tampilkanJumlahBarangPerKelompok() {
        map<string, int> jumlahPerKelompok;
        for (Barang barang : stok) {
            jumlahPerKelompok[barang.kelompok]++;
        }

        vector<pair<string, int>> v;
        for (auto entry : jumlahPerKelompok) {
            v.push_back(entry);
        }

        sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        for (auto entry : v) {
            cout << entry.first << " " << entry.second << endl;
        }
    }

    void tampilkanDaftarBarang(string kelompok) {
        cout << "Daftar Barang " << kelompok << endl;
        vector<string> daftar = barangPerKelompok[kelompok];
        sort(daftar.begin(), daftar.end());

        for (string barang : daftar) {
            for (Barang b : stok) {
                if (b.kelompok == kelompok && b.nama == barang) {
                    cout << barang << " " << b.jumlah << endl;
                    break;
                }
            }
        }
        cout << "*****" << endl;
    }
};

int main() {
    int n, q;
    cin >> n;

    Toko toko;
    for (int i = 0; i < n; i++) {
        int id, jumlah;
        string kelompok, nama;
        cin >> id >> kelompok >> nama >> jumlah;
        toko.tambahBarang(id, kelompok, nama, jumlah);
    }

    toko.tampilkanJumlahBarangPerKelompok();

    cin >> q;
    for (int i = 0; i < q; i++) {
        string kelompok;
        cin >> kelompok;
        toko.tampilkanDaftarBarang(kelompok);
    }

    return 0;
}
