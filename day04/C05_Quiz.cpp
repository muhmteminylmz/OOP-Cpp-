#include <iostream>

using namespace std;

class Esya{
    private:
        int id;
        string name;

public:
    int price;
    Esya(){
        cout << "Esya constructor calisti" << endl;
    }
    Esya(int newPrice){
        cout << "parametreli Esya constructor calisti" << endl;
        price = newPrice;
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
};

class ElektronikEsya : public Esya {

private:
    int a;
    int b;


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


};


class AhsapEsya : public Esya {
private:
    int c;
    int d;


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



};


int main(){

    Esya esya1;
    Esya esya1(200);

    ElektronikEsya elektronikEsya1;
    ElektronikEsya elektronikEsya1(300);

    AhsapEsya ahsapEsya1;
    AhsapEsya ahsapEsya1(400);

    return 0;

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