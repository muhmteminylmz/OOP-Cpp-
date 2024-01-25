#include <iostream>

using namespace std;

class B1{

public:

    virtual void f(){
        cout << "B1" << endl;
    }
};

class D1 : public B1{

public:
    void f(){
        cout << "D1" << endl;
    }
};

class D2 : public D1{

public:
    void f(){
        cout << "D2" << endl;
    }
};


int main(){

    B1 b1,*p;
    D1 d1;
    D2 d2;

    p = &b1;
    p ->f();

    p = &d1;
    p ->f();

    p = &d2;
    p ->f();
}