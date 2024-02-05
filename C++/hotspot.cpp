#include <bits/stdc++.h>
using namespace std;

class Hotspot
{
    private:
        set<pair<int,int>> coordinate;
    public:
        void add(int a, int b)
        {
            pair<int,int> xy;
            xy.first = a;
            xy.second = b;
            coordinate.insert(xy);
        }
        void sortNPrint()
        {
            set<pair<int,int>>::reverse_iterator it;
            for(it = coordinate.rbegin(); it != coordinate.rend(); it++)
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
            return coordinate.size();
        }

};

int main()
{
    int n, x, y;
    Hotspot titik;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        titik.add(x, y);
    }    
    cout << titik.getsize() << endl;
    titik.sortNPrint();
    return 0;
}