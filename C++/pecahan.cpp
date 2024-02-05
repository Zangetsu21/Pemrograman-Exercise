#include <bits/stdc++.h>
using namespace std;

class myClass{
    private:
        int a, b, c;
    public:
        myClass(int x=0, int y=0, int z=0){
            a = x;
            b = y;
            c = z;
        }
        int gcd(int x, int y);
        void simp(){
            if(b == 0){
                b = 0;
                c = 0;
            }else{
                a += b / c;
                b %= c;
                if(b == 0){
                    b = 0;
                    c = 0;
                }else{
                    int temp = gcd(c, b);
                    b /= temp;
                    c /= temp;
                }
            }
        }
        void set(int x, int y, int z);
        myClass operator+(myClass const &operand);
        myClass operator*(myClass const &operand);
        void operator++(int);
        void operator--(int);
        void getVal();
};

int myClass::gcd(int x, int y){
    int temp;
    while(y != 0){
        temp = y;
        y = x%y;
        x = temp;
    }
    return x;
}

void myClass::set(int x, int y, int z){
    a = x;
    b = y;
    c = z;
    simp();
}

myClass myClass::operator+(myClass const &operand){
    myClass res;
    res.a = a + operand.a;
    if(b == 0){
        res.b = operand.b;
        res.c = operand.c;
    }else if(operand.b == 0){
        res.b = b;
        res.c = c;
    }else{
        res.b = b*operand.c + c*operand.b;
        res.c = c*operand.c;
    }
    res.simp();
    return res;
}

myClass myClass::operator*(myClass const &operand){
    myClass res;
    int nume1, deno1, nume2, deno2;
    if(b == 0){
        nume1 = a;
        deno1 = 1;
    }else{
        nume1 = a*c+b;
        deno1 = c;
    }
    if(operand.b == 0){
        nume2 = operand.a;
        deno2 = 1;
    }else{
        nume2 = operand.a * operand.c + operand.b;
        deno2 = operand.c;
    }
    res.b = nume1 * nume2;
    res.a = 0;
    res.c = deno1 * deno2;
    res.simp();
    return res;
}

void myClass::operator++(int){
    a++;
}

void myClass::operator--(int){
    a--;
}

void myClass::getVal(){
    if(b == 0){
        cout << a << endl;
    }else if(a == 0){
        cout << b << '/' << c << endl;
    }else{
        cout << a << ' ' << b << '/' << c << endl;
    }
}

int main(){
    myClass Obj = myClass();
    string n;
    int num1, num2, num3;
    cin >> n;
    while(n != "end"){
        if(n == "set"){
            cin >> num1 >> num2 >> num3;
            Obj.set(num1, num2, num3);
        }else if(n == "add"){
            cin >> num1 >> num2 >> num3;
            myClass Temp = myClass(num1, num2, num3);
            Obj = Obj + Temp;
        }else if(n == "mul"){
            cin >> num1 >> num2 >> num3;
            myClass Temp = myClass(num1, num2, num3);
            Obj = Obj * Temp;
        }else if(n == "inc"){
            Obj++;
        }else if(n == "dec"){
            Obj--;
        }else if(n == "p"){
            Obj.getVal();
        }
        cin >> n;
    }

    return 0;
}