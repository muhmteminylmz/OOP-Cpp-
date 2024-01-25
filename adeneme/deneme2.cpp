#include <iostream>

using namespace std;

class Sekil{
public:

    double dim1,dim2;
    void setArea(double d1,double d2){
        dim1 = d1;
        dim2 = d2;
    }
    void getDim(double &d1,double &d2){
        d1 = dim1;
        d2 = dim2;
    }
    virtual double getArea() =0;
};

class Dikdortgen : public Sekil{
    double d1,d2;
public:

    double getArea(){
        getDim(d1,d2);
        return d1*d2;
    }
};

class Ucgen : public Sekil{
    double d1,d2;
public:

    double getArea(){
        getDim(d1,d2);
        return d1*d2*0.5;
    }

};

int main(){

    Sekil *p;
    Dikdortgen d;
    Ucgen u;

    d.setArea(20,40);
    u.setArea(20,40);

    p = &d;
    cout << "Area: " << p->getArea() << endl;

    p= &u;
    cout << "Area: " << p->getArea();
}