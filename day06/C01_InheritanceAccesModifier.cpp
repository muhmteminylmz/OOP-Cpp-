#include <iostream>

using namespace std;

/*
mutlaka sorulur inheritance da private public farki
 */

class Base{
    int x;

public:
    void setx(int a){x = a;}
    void showx(){cout << x << endl;}

};


class Derived : public Base{
    int y;

public:
    void sety(int b,int varX){y=b; setx(varX);}
    void showy(){cout << y << endl; showx();}
};

int main(){

    Derived ob;

    ob.sety(20,1000);

    ob.showx();
    ob.showy();

}




/*
class C : public A, public B{
    int c;

public:

};*/