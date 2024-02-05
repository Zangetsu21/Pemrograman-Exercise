#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Mahasiswa {
public:
    string nim;
    string nama;
    char jenis_kelamin;
    double ipk;
};

class Kelas {
public:
    vector<Mahasiswa> mahasiswa;
    int jml_laki_laki = 0;
    int jml_perempuan = 0;
    double rata_ipk = 0;

    void hitung() {
        int total_mahasiswa = mahasiswa.size();
        for (int i = 0; i < total_mahasiswa; i++) {
            if (mahasiswa[i].jenis_kelamin == 'L') {
                jml_laki_laki++;
            }
            else if (mahasiswa[i].jenis_kelamin == 'P') {
                jml_perempuan++;
            }
            rata_ipk += mahasiswa[i].ipk;
        }
        rata_ipk /= total_mahasiswa;
    }
};

int main() {
    int n, m;
    cin >> n;

    vector<Mahasiswa> daftar_mahasiswa(n);
    unordered_map<string, int> map_nim;
    for (int i = 0; i < n; i++) {
        cin >> daftar_mahasiswa[i].nim >> daftar_mahasiswa[i].nama >> daftar_mahasiswa[i].jenis_kelamin >> daftar_mahasiswa[i].ipk;
        map_nim[daftar_mahasiswa[i].nim] = i;
    }

    cin >> m;
    Kelas kelas_wira;
    for (int i = 0; i < m; i++) {
        string nim;
        cin >> nim;
        if (map_nim.find(nim) != map_nim.end()) {
            int idx = map_nim[nim];
            kelas_wira.mahasiswa.push_back(daftar_mahasiswa[idx]);
        }
    }

    kelas_wira.hitung();

    cout << kelas_wira.jml_laki_laki << " " << kelas_wira.jml_perempuan << endl;
    cout << fixed << setprecision(2) << kelas_wira.rata_ipk << endl;

    return 0;
}
