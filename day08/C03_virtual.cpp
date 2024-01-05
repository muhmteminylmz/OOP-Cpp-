#include <iostream>
#include <cstdlib>

using namespace std;

class base{
public:
    int i;
    base(int x){i=x;}
    virtual void func(){
        cout << "Temel fonksiyon func(): "<< i << endl;
    }
};

class derived1 : public base{
public:
    derived1(int x) : base(x){}
    void func(){
        cout << "turemis 1 fonksiyon func(): "<< i*i << endl;
    }
};

class derived2 : public base{
public:
    derived2(int x) : base(x){}
    void func(){
        cout << "turemis 2 fonksiyon func(): "<< i+i << endl;
    }
};
//* bu asil polymorphism dir.Hem fazla fonksiyon yazmayiz ve nesneden nesneye fonksiyon kullanimi degisir
//* ornegin kara icin farkli ucgen icin farkli calisir

int main(){

    base *p;

    derived1 d1_ob(10);
    derived2 d2_ob(10);
    int i,j;
    //cok bicimlilik (polymorphism)
    for(i=0;i<10;i++){
        j=rand();
        if((j%2)) p=&d1_ob; //tekse d1 kullan
        else p=&d2_ob; //cift ise d2 kullan
        p->func();
    }


    return 0;

}