#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

class Angka {
    private:
        vector<int> v1;
        vector<int> v2;
        int numbers1, numbers2;
        double average1, average2;    
    public:
        Angka () {
            v1.clear();
            v2.clear();
            numbers1 = numbers2 = 0;
            average1 = average2 = 0;
        }

        void input () {
            int x;
            cin >> x;
            while(x != -9){ add_ori(x); cin >> x; }
            cin >> x;
            while(x != -9){ add_cur(x); cin >> x; }
        }
        
        void add_ori (int x){
            v1.push_back(x);
        }
        
        void add_cur (int x){
            v2.push_back(x);
        }
        
        void del () {
              for (int i = v2.size() - 1; i >= 0; i--) {
                v1.erase(v1.begin() + v2[i] - 1);
            }
        }
        
        void original () {
            numbers1 = v1.size();
            average1 = accumulate(v1.begin(), v1.end(), 0.0) / v1.size();
            
        }
        void current () {
            numbers2 = v1.size();
            average2 = accumulate(v1.begin(), v1.end(), 0.0) / v1.size();
        }
        
        void print () {
            cout << setprecision(2) << fixed; 
            cout << numbers1 << " " << numbers2 << endl;
            if(numbers1 == 0 && numbers2 == 0){
                cout << "-9.99 -9.99" << endl;
            } else if (numbers2 == 0) {
                cout << average1 << " " << "-9.99" << endl;
            } else {
                cout << average1 << " " << average2 << endl;
            }
        }       
};

int main ()
{   
    Angka data;
    data.input();
    data.original();
    data.del();
    data.current();
    data.print();
    return 0;
}