#include <iostream>

using namespace std;

class B1{
public:
    B1(){cout << "Cons B1 \n";}
    ~B1(){cout << "Des B1 \n";}


};

class B2{
public:
    B2 (){cout << "Cons B2 \n";}
    ~B2 (){cout << "Des B2 \n";}



};

class D1 : public B1,public B2{
public:
    D1(){cout << "Cons D1 \n";}
    ~D1(){cout << "Des D1 \n";}

};

int main(){

    D1 ob;


    return 0;
}