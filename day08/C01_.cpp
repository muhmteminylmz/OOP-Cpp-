#include <iostream>

using namespace std;

class base{
    int x;
public:
    void setx(int i){x=i;}
    int getx(){return x;}
};

class derived : public base{
    int y;
public:
    void sety(int i){y=i;}
    int gety(){return y;}
};

int main(){

    base *p;
    //pointer her nesnenin basina gider (boyutunu pointerla aldigimizdan bilemeyiz*)
    base b_ob;
    derived d_ob;

    p= &b_ob;
    p->setx(10);
    cout << "Base object x: " << p->getx() << endl;

    p = &d_ob;//artik turemis e gectik
    p->setx(99);

    d_ob.sety(88);//burda pointerdan erisemememizin sebebi pointer base class
    cout << "Derived object x: " << p->getx() << endl;//ayni
    cout << "Derived object y: " << d_ob.gety() << endl;
    cout << "Derived object y: " << d_ob.getx() << endl;//ayni

}