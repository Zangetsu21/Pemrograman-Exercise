#include <iostream>
#include <vector>
using namespace std;

class Matrik
{
    private:
        vector<vector<int> > X;     // matrik 2 dimensi
        int row,col;                // ukuran baris dan kolom
    public:
        Matrik() { X.clear(); row=col=0; }
        void set();
        void print();
        Matrik& operator+=(Matrik p);
        Matrik& operator-=(Matrik p);
        void transpose();
        // tambahkan fungsi-fungsi lain jika diperlukan
};

void Matrik::set()
{
    cin >> row >> col;
    X.resize(row, vector<int>(col, 0));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin >> X[i][j];
}

void Matrik::print()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cout << X[i][j] << " ";
        cout << endl;
    }
}

Matrik& Matrik::operator+=(Matrik p)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            X[i][j] += p.X[i][j];
    return *this;
}

Matrik& Matrik::operator-=(Matrik p)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            X[i][j] -= p.X[i][j];
    return *this;
}

void Matrik::transpose()
{
    vector<vector<int> > Y(col, vector<int>(row, 0));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            Y[j][i] = X[i][j];
    X = Y;
    swap(row, col);
}

int main()
{
    Matrik A;
    string cmd;
    while(cin >> cmd)
    {
        if(cmd == "matrik")
            A.set();
        else if(cmd == "print")
            A.print();
        else if(cmd == "tambah")
        {
            Matrik B;
            B.set();
            A += B;
        }
        else if(cmd == "kurang")
        {
            Matrik B;
            B.set();
            A -= B;
        }
        else if(cmd == "transpose")
            A.transpose();
        else if(cmd == "stop")
            break;
    }
    return 0;
}
