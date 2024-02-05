#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pegawai
{
protected:
    string id;
    int usia, tipe;
    int income;

public:
    void set(string pid, int u, int t)
    {
        id = pid;
        usia = u;
        tipe = t;
    }
    string getID() { return id; }
    void print() { cout << id << " " << tipe << " " << income << endl; }
};

class Tetap : public Pegawai
{
public:
    Tetap()
    {
        income = 0;
    }
    void setLembur(int var)
    {
        income += var;
    }
};

class Harian : public Pegawai
{
public:
    Harian()
    {
        income = 0;
    }
    void setHarian(int var)
    {
        income += var;
    }
};

int main()
{
    vector<Tetap> pt;
    vector<Harian> ph;
    int pokok;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string id = "";
        int usia, tipe = 0;
        Tetap ttp;
        Harian hrn;
        cin >> id >> usia >> tipe;
        if (tipe == 1)
        {
            cin >> pokok;
            ttp.setLembur(pokok);
            ttp.set(id, usia, tipe);
            pt.push_back(ttp);
        }
        else
        {
            hrn.set(id, usia, tipe);
            ph.push_back(hrn);
        }
    }
    while (true)
    {
        string id = "";
        string getID = "";
        int income = 0;
        int status = 0;
        cin >> id;
        if (id == "END")
            break;

        for (int ct = 0; ct < pt.size(); ct++)
        {
            getID = pt[ct].getID();
            if (getID == id)
            {
                cin >> income;
                pt[ct].setLembur(income);
                status = 1;
            }
        }

        if (status == 0)
        {
            for (int ch = 0; ch < ph.size(); ch++)
            {
                getID = ph[ch].getID();
                if (getID == id)
                {
                    cin >> income;
                    ph[ch].setHarian(income);
                    status = 1;
                }
            }
        }

        if (status == 0)
            continue;
    }

    for (int i = 0; i < pt.size(); i++)
    {
        pt[i].print();
    }
    for (int j = 0; j < ph.size(); j++)
    {
        ph[j].print();
    }

    return 0;
}