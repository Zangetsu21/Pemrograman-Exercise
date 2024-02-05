#include <iostream>
using namespace std;

void merge (int *bil1, int *bil2, int *bil3, int m, int n) {
    int j = 0, k = 0;
    for (int i=0; i<(n+m); i++) {
        if (j < n && k < m) {
            if (bil1[j] < bil2[k]) {
                bil3[i] = bil1[j];
                j++;
            } else {
                bil3[i] = bil2[k];
                k++;
            }
        } else if (j < n) {
            bil3[i] = bil1[j];
            j++;
        } else if (k < m) {
            bil3[i] = bil2[k];
            k++;
        }
    }
}

void print (int *bil3, int n, int m) {
    for (int i=0; i<(m+n); i++) {
        cout << bil3[i] << " ";
    }
    cout << endl;
}

int main () {
    int n, m;
    cin >> n
        >> m;
    int *bil1, *bil2, *bil3;
    bil1 = (int*)malloc(n*sizeof(int));
    bil2 = (int*)malloc(m*sizeof(int));
    bil3 = (int*)malloc((m+n)*sizeof(int));
    for (int i = 0; i<n; i++) {
        cin >> bil1[i];
    }
    for (int j = 0; j<m; j++) {
        cin >> bil2[j];
    }
    merge(bil1, bil2, bil3, m, n);
    print(bil3, n, m);
    return 0;
}