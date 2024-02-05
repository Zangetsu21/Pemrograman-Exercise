#include <bits/stdc++.h>
#include <map>
using namespace std;

class Barang
{
    public:
        string kode; // kode barang
        string nama; // nama barang
        int harga; // harga satuan barang (rupiah)
};

class DaftarKode
{
    private:
        map<string,Barang> dt; // daftar kode barang
        int size; // ukuran daftar kode barang yang ada
    public:
        DaftarKode() { dt.clear(); size=0; }
        void init(); // membaca daftar kode barang dari stdin
        string getNama(string kode); // mendapatkan nama barang dari kode
        int getHarga(string kode); // mendapatkan harga barang dari kode
};

void DaftarKode::init(){
    Barang Obj[1000];
    int n, price;
    string code, name;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> code >> name >> price;
        Obj[i].kode = code;
        Obj[i].nama = name;
        Obj[i].harga = price;
        dt[code] = Obj[i];
        size++;
    }
}

string DaftarKode::getNama(string kode){
    return dt[kode].nama;
}

int DaftarKode::getHarga(string kode){
    return dt[kode].harga;
}

class Penjualan
{
    private:
        DaftarKode daftar; // daftar kode barang yang ada
        map<string,int> st; // data penjualan
        int size; // ukuran data penjualan
    public:
        Penjualan() {
            daftar.init();
            size=0;
        }
        void add(string kode, int jumlah){
            if(daftar.getNama(kode) != ""){
                if(st[kode] == 0) size++;
                st[kode] += jumlah;
                //cout << kode << endl;
            }
        } // menambah data penjualan
        void print(){
            map<string, int>::iterator it;
            string seq[1000];
            double total = 0;
            int i = 0;
            for(it = st.begin(); it != st.end(); it++){
                total += 1.0*daftar.getHarga(it->first)*(it->second)/1000000;
                seq[i] = it->first;
                int x = i;
                while(x > 0 && st[seq[x-1]]*daftar.getHarga(seq[x-1]) < st[seq[x]]*daftar.getHarga(seq[x])){
                    string buff = seq[x];
                    seq[x] = seq[x-1];
                    seq[x-1] = buff;
                    x--;
                }
                i++;
            }
            for(int i = 0; i < size; i++){
                cout << seq[i] << " " << daftar.getNama(seq[i]) << " " << st[seq[i]] << " ";
                cout << fixed << setprecision(2) << 1.0*daftar.getHarga(seq[i])*st[seq[i]]/1000000 << endl;
            }
            cout << "Total Nilai : " << fixed << setprecision(2) << total << " juta rupiah" << endl;
        }
};

int main ()
{
    Penjualan kom20c;
    string code;
    int banyak_kode, sum;
    cin >> banyak_kode;
    for(int i = 0; i < banyak_kode; i++){
        cin >> code >> sum;
        kom20c.add(code, sum);
    }
    kom20c.print();
    return 0;
}