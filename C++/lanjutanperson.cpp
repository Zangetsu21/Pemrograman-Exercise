#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
using namespace std;

class Person {
    private:
        string nama;
        int usia, tinggi;
        double berat, IMT;
    public:
        Person() {
            nama = "";
            usia = 0;
            tinggi = 0;
            berat = 0.0;
        }
        void setPerson (string p, int p1, int p2, double p3){
            nama = p;
            usia = p1;
            tinggi = p2;
            berat = p3;
        }
        string getNama (){ return nama; }
        int getUsia () { return usia; }
        int getTinggi(){ return tinggi; }
        double getBerat (){ return berat; }
        double getIMT () { return IMT = berat*10000/(tinggi*tinggi); }
        string getStatusGizi () {
            if (IMT < 17.0) { return "sangat kurus"; }
            else if (IMT < 18.5) { return "kurus"; }
            else if (IMT < 25.0) { return "normal"; }
            else if (IMT < 28.0) { return "gemuk"; }
            else if (IMT >= 28.0) { return "sangat gemuk"; } 
    }
};

int main() {
    string nama;
    int usia, tinggi, n;
    double berat, index;

    cin >> n;

    int dataTinggi = 0;

    Person orang[n];
    for (int i = 0; i < n; i++) {
        cin >> nama >> usia >> tinggi >> berat;
        dataTinggi += tinggi;
     orang[i].setPerson(nama, usia, tinggi, berat);
    }

    double rata = (double)dataTinggi / n;

    int frek = 0;

    for (int i = 0; i < n; i++) {
        if (orang[i].getTinggi() > rata) frek++;
    }

    int ia=0, ib=0, ic=0, id=0, ie=0;
    
    for (int i = 0; i < n; i++) {
        index = orang[i].getIMT();
        if(index < 17.0) ia++;
        else if(index < 18.5) ib++;
        else if(index < 25.0) ic++;
        else if(index < 28.0) id++;
        else if(index >= 28.0) ie++;
        cout << orang[i].getNama() << " " << orang[i].getUsia() << " " << orang[i].getTinggi() << " " 
        << fixed << setprecision(2) << orang[i].getBerat() << " " << fixed << setprecision(2) << orang[i].getIMT() 
        << " " << orang[i].getStatusGizi() << endl;
    }

    cout << fixed << setprecision(2) << rata << endl;
    cout << frek << endl;
    cout << ia << " " << ib << " " << ic << " " << id << " " << ie << endl;
    
    return 0;
}