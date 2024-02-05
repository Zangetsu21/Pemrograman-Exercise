#include <bits/stdc++.h>
using namespace std;

class Person {
    protected:
        string nama; // nama
        char jk; // jenis kelamin
        int usia; // usia (tahun)
        string kota; // kota lahir
    public:
        void set(string n, char j, int u, string k){
            nama = n;
            jk = j;
            usia = u;
            kota = k;
        }
        string getNama();
        char getjk();
        int getUsia();
        string getKota();
};

template <class T>
double rataan(vector<T> p){
    if(p.size() == 0){
        return 0;
    }
    int count = 0;
    for(auto it : p){
        count += it.getUsia();
    }
    return 1.0*count/(double)p.size();
}

template <class T>
int banyak(vector<T> p){
    int count = 0;
    for(auto it : p){
        if(it.getUsia() < rataan(p))
            count++;
    }
    return count;
}

string Person::getNama(){
    return nama;
}

char Person::getjk(){
    return jk;
}

int Person::getUsia(){
    return usia;
}

string Person::getKota(){
    return kota;
}

class Male : public Person{
    public:
        void set(string n, char j, int u, string k){
            nama = n;
            jk = j;
            usia = u;
            kota = k;
        }
};

class Female : public Person{
    public:
        void set(string n, char j, int u, string k){
            nama = n;
            jk = j;
            usia = u;
            kota = k;
        }
};

int main(){
    vector<Male> L;
    vector<Female> P;
    vector<Male>::iterator itL;
    vector<Female>::iterator itP;
    string s;
    while(getline(cin, s)){
        string nama = s.substr(0,25);
        char jk = s[25];
        int umur = stoi(s.substr(26,2));
        string kota = s.substr(28,25);
        if(jk == 'L'){
            Male temp;
            temp.set(nama, jk, umur, kota);
            L.push_back(temp);
        }else{
            Female temp;
            temp.set(nama, jk, umur, kota);
            P.push_back(temp);
        }
    }
    
    cout << "L " << L.size() << " ";
    cout << fixed << setprecision(2) << rataan(L);
    cout << " " << banyak(L) << endl;
    cout << "P " << P.size() << " ";
    cout << fixed << setprecision(2) << rataan(P);
    cout << " " << banyak(P) << endl;

    return 0;
}