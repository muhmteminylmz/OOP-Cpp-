#include <iostream>

using namespace std;

class B1{
    int a;
public:
    B1(int x){a=x;}
    int get_a(){return a;}


};

class D1 : public B1{
    int b;
public:
    D1 (int x,int y) : B1(y) {b=x;};
    int get_b(){return b;}

};

class D2 : public D1 {
    int c;
public:
    D2(int x, int y, int z) : D1(y, z) { c = x; };
    int get_c() { return c; }

    void show(){
        cout << get_a() << ' ' << get_b() << endl;
        cout << c << endl;
    }

};

int main(){
    D2 ob(1,2,3);
    ob.show();

    return 0;
}