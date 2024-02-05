#include <bits/stdc++.h>
using namespace std;

int main() {
    char t = 'z';
    char *b = &t;
    t = 'z';
    cout << "alamat t adalah : " << &t << endl;
    cout << "alamat t adalah : " << b << endl;
    printf("alamat t adalah : %p\n", &t);
    printf("alamat t adalah : %p\n", b);
    cout << "alamat b adalah : " << &b << endl;
    printf("alamat b adalah : %p\n", &b);
    cout << "nilai dari t adalah :" << t << endl;
    cout << "nilai dari b adalah :" << *b << endl;

    float num = 1.405;
    float *pointerNum = &num;
    *pointerNum = -22.5;
    cout << "address num adalah : " << pointerNum << endl;
    cout << "nilai dari pointerNum adalah: " << *pointerNum << endl;
    cout << "nilai dari num adalah : " << num << endl;
    
    return EXIT_SUCCESS;
}