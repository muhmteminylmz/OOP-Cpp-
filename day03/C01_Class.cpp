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
    car.model = "Mercedes";
    car.price = 50000;
    return car;
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

    fiyatGoster(car1);

    car2 = nesneDondur(car1);
    /*
     Destructor in tekrar calimsasinin sebebi
     */

    cout << "Model: " << car2.model << endl;
    cout << "Fiyat: " << car2.price << endl;


    return 0;

}