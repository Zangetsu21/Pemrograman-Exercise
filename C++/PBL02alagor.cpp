#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

struct Village {
    int x, y; // Koordinat geografis desa
    int goods; // Jumlah barang yang akan dikirim dari desa ini
};

// Fungsi untuk menghitung jarak antara dua desa
double distance(const Village& A, const Village& B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

// Algoritma Greedy untuk menentukan rute terpendek
std::vector<Village> greedyRoute(std::vector<Village> villages) {
    std::vector<Village> route;
    int n = villages.size();

    // Pilih desa awal sebagai desa produsen pertama
    route.push_back(villages[0]);
    villages.erase(villages.begin());

    // Selama ada desa yang belum dikunjungi
    while (!villages.empty()) {
        int minIndex = -1;
        double minDistance = std::numeric_limits<double>::max();

        // Cari desa terdekat
        for (int i = 0; i < villages.size(); i++) {
            double dist = distance(route.back(), villages[i]);
            if (dist < minDistance) {
                minDistance = dist;
                minIndex = i;
            }
        }

        // Tambahkan desa terdekat ke rute
        route.push_back(villages[minIndex]);
        villages.erase(villages.begin() + minIndex);
    }

    // Kembalikan rute sebagai solusi
    return route;
}

int main() {
    // Contoh penggunaan algoritma Greedy
    std::vector<Village> villages = {{1, 2, 10}, {3, 4, 20}, {5, 6, 15}, {7, 8, 25}};
    std::vector<Village> route = greedyRoute(villages);

    // Tampilkan rute hasil
    for (const Village& v : route) {
        std::cout << "Desa (" << v.x << ", " << v.y << ") - " << v.goods << " barang" << std::endl;
    }

    return 0;
}
