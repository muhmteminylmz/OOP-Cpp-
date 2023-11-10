#include <iostream>

using namespace std;

class Car{

    int araba_kapisi=4;


    string model;
    int price;
public:
    Car(string model,int price){
        this->model = model;
        this->price = price;

    }
    Car(){

    }

    int horsePower;

    void _write_Information(){
        cout << "Model: " << " " << model << endl;
        cout << "Fiyat: " << price << endl;
        cout << "Araba Kapisi: " << araba_kapisi << endl;
        cout << "Horse Power: " << horsePower << endl;
    }


    ~Car(){
        cout << "Araba Parcalaniyor" << endl;
    }
};

int main(){

    Car car1("BMW",60000);
    car1.horsePower = 300;

    car1._write_Information();

    cout << "2.Araba -------------------------" << endl;

        Car car2;
        car2.horsePower = 500;
        car2._write_Information();

}

