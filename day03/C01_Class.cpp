#include <iostream>

using namespace std;

class Car{

public:
    Car(){
        cout << "Constructor in progress" << endl;
    }

    string model;
    int price= 0;

    ~Car(){
        cout << "Destructor in progress" << endl;
    }

};

void fiyatGoster(Car car){
    cout << "Fiyat: " << car.price << endl;
}

Car nesneDondur(Car car){
    //nesne parametre olarak girildiginde ve fonk bittiginde destructor calisir
    car.model = "Mercedes";
    car.price = 50000;
    return car;
    //nesne return edince destructor calisir
}
/*

 */

int main(){

    Car car1;
    Car car2;

    car1.model = "BMW";
    car1.price = 20000;

    cout << "Model: " << car2.model << endl;
    cout << "Fiyat: " << car2.price << endl;

    cout << "-------------------------------\n";


    fiyatGoster(car1);

    cout << "-------------------------------\n";

    car2 = nesneDondur(car1);
    //nesne return edince destructor calisir
    /*
     Destructor in tekrar calimsasinin sebebi
     */

    cout << "Model: " << car2.model << endl;
    cout << "Fiyat: " << car2.price << endl;


    return 0;

}