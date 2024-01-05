#include <iostream>

using namespace std;

class base{
public:
    int i;
};

class derived1 :virtual public base {
public:
    int j;
};
class derived2 :virtual public base{
public:
    int k;
};
//virtual i kafasi karismasin diye kullaniyoruz cunku i yi hangi class dan alacagini bilemez (2 class danda inheritance ettik)
//sinavda gelmez

class derived3 : public derived1,public derived2{
public:
    int pro(){ return i*j*k;}
};

int main(){
    derived3 ob;

    ob.i =10;
    ob.j =3;
    ob.k = 5;

    cout << ob.pro();
}