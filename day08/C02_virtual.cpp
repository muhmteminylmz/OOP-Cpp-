#include <iostream>

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
    base b_ob(1);
    derived1 d1_ob(2);
    derived2 d2_ob(3);

    p= &b_ob;
    p->func();

    p= &d1_ob;
    p->func();

    p= &d2_ob;
    p->func();

    return 0;

}