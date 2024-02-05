#include <bits/stdc++.h>
using namespace std;

class Peta{
    private:
        set<pair<int,int>> koor;
    public:
        void add(int a, int b)
        {
            pair<int,int> xy;
            xy.first = a;
            xy.second = b;
            koor.insert(xy);
        }
        void sortNPrint()
        {
            set<pair<int,int>>::reverse_iterator it;
            for(it = koor.rbegin(); it != koor.rend(); it++)
            {
                if(it->second > 0)
                {
                    cout << "(" << it->first << "," << it->second << ")";
                }
            }
            cout << endl;
        }
        int getsize()
        {
            return koor.size();
        }

};

int main()
{
    int n, x, y;
    Peta Objek;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        Objek.add(x, y);
    }    
    cout << Objek.getsize() << endl;
    Objek.sortNPrint();
    return 0;
}