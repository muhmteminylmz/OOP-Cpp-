#include <iostream>

using namespace std;

class Esya{
private:
    int id;
    string name;
    //int *p;

public:
    int price;
    Esya(){
        cout << "Esya constructor calisti" << endl;
    }
    Esya(int newPrice){
        price = newPrice;
        cout << "parametreli Esya constructor calisti" << endl;
    }

    string getName(){
        return name;
    }
    void setName(string newName){
        name = newName;
    }

    int getId(){
        return id;
    }

    void setId(int id){
        this -> id = id;
    }

    Esya(const Esya &copyEsya){
        cout << "Esya copy constructor calisti" << endl;
    }

    ~Esya(){
        cout << "Esya destructor calisti --" << endl;
    }
};

class ElektronikEsya : public Esya {

private:
    int a;
    int b;
    //int *p;

public:
    ElektronikEsya(){
        cout << "ElektronikEsya constructor calisti" << endl;

    }
    ElektronikEsya(int c){
        cout << "parametreli ElektronikEsya constructor calisti" << endl;
    }

    void setA(int newA){
        a = newA;
    }

    void setB(int newB){
        b = newB;
    }

    int getA(){
        return a;
    }

    int getB(){
        return b;
    }

    ElektronikEsya(const ElektronikEsya &copyElektronikEsya){
        cout << "ElektronikEsya copy constructor calisti" << endl;
    }

    ~ElektronikEsya(){
        cout << "ElektronikEsya destructor calisti --" << endl;
    }

};


class AhsapEsya : public Esya {
private:
    int c;
    int d;
    //int *p;

public:
    AhsapEsya(){
    cout << "AhsapEsya constructor calisti" << endl;
}
    AhsapEsya(int newPrice){
        cout << "parametreli AhsapEsya constructor calisti" << endl;
        price = newPrice;
    }

    void setPrice(int newPrice){
        price = newPrice;
    }

    void setC(int newC){
        c = newC;
    }

    void setD(int newD){
        d = newD;
    }

    int getC(){
        return c;
    }

    int getD(){
        return d;
    }

    AhsapEsya(const AhsapEsya &copyAhsapEsya){
        cout << "AhsapEsya copy constructor calisti" << endl;
    }

    ~AhsapEsya(){
        cout << "AhsapEsya destructor calisti--" << endl;
    }
};


int main(){

    Esya esya1;
    Esya esya2(200);


    ElektronikEsya elektronikEsya1;
    //ElektronikEsya elektronikEsya2(300);
    ElektronikEsya x = elektronikEsya1; //burda normal cons yerine copy cons calisti

    AhsapEsya ahsapEsya1;
    AhsapEsya ahsapEsya2(400);

    return 0;

    /*
    Esya constructor calisti
    parametreli Esya constructor calisti
    Esya constructor calisti
    ElektronikEsya constructor calisti
    Esya constructor calisti
    ElektronikEsya copy constructor calisti
    Esya constructor calisti
    AhsapEsya constructor calisti
    Esya constructor calisti
    parametreli AhsapEsya constructor calisti
    AhsapEsya destructor calisti--
    Esya destructor calisti --
    AhsapEsya destructor calisti--
    Esya destructor calisti --
    ElektronikEsya destructor calisti --
    Esya destructor calisti --
    ElektronikEsya destructor calisti --
    Esya destructor calisti --
    Esya destructor calisti --
    Esya destructor calisti --
     */

}
/*
 * getter setter constructor hepsinde var
 * 1 er tanede parametreli constructor
 esya sub class
 2private degisken
 2 yeni class
 1) elektronik esya
 2private degisken
 2) ahsap esya
 2private degisken

main icinde bunlari tanimlayip
class lari birbirine atama yapilacak
turemis olan classlardada 1 er tane copy constructor olacak
 */