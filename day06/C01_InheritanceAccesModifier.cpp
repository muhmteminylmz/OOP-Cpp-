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


class Derived : protected Base{
    int y;

public:
    void sety(int b,int varX){y=b; setx(varX);}
    void showy(){cout << y << endl; showx();}
};
/*
 Derived da private kullandigimizdan artik bazi public fonksiyonlar bile private a donusur bunu unutmamaliyiz
 ornegin Derived2 de setx() fonksiyonunu kullanamayiz
 */
class Derived2 : protected Derived{
    int z;

public:
    void setz(int c,int VarX,int VarY){z=c; setx(VarX);sety(VarY,VarX);}
    void showz(){cout << z << endl; showy();}
};



int main(){

    Derived ob;

    ob.sety(20,1000);

    ob.showy();

}
