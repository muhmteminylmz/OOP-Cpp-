#include <iostream>

using namespace std;

class Car{

private:
    int speed = 50;
    int price = 1000000;

public:

    Car();
    //Car(std::string marka, std::string tekerlek_sayisi);

    std::string marka = "Honda";
    std::string tekerlek_sayisi = "4";

    void hiz_arttir(int miktar){
        speed+=miktar;
    }

    void showInformation(){
        std::cout << "Marka: " << marka << std::endl;
        std::cout << "Tekerlek Sayisi: " << tekerlek_sayisi << std::endl;
        std::cout << "Deger: " << price << std::endl;
        std::cout << "Hiz: " << speed << std::endl;
    }

    void deger_degistir(int new_price){
        price = new_price;
    }

    void set_speed(int new_speed){
        speed = new_speed;
    }

    ~Car();

};

Car::Car(){
    cout << "Car Constructor" << endl;
}

Car::~Car() {
    std::cout << "Car Destructor" << std::endl;
}

class Mercedes : public Car{

private:
    int iprivateMercedes;
    void fprivate_mercedes(){
        std::cout << "Mercedes Public --> Mercedes Private Method" << std::endl;
    }

public:
    int iPublicMercedes;
    void fPublic_mercedes(){
        fprivate_mercedes();
    }

    Mercedes();
    ~Mercedes();
};

Mercedes::Mercedes(){
    std::cout << "Mercedes Constructor" << std::endl;
}

Mercedes::~Mercedes(){
    std::cout << "Mercedes Destructor" << std::endl;
}

class Tesla : public Car{
private:
    int iPrivateTesla;
    void fPrivate_Tesla(){
        std::cout << "Tesla Public --> Tesla Private Method" << std::endl;
    };

public:
    int iPublicTesla;
    void fPublic_Tesla(){
        fPrivate_Tesla();
    }


    Tesla();
    ~Tesla();
};

Tesla::Tesla() {
    cout << "Tesla Constructor" << std::endl;
}

Tesla::~Tesla() {
    cout << "Tesla Destructor" << std::endl;
}

class Togg : public Car{
private:
    int iPrivateTogg;
    void fPrivateTogg(){
        std::cout << "Togg Public --> Togg Private Method" << std::endl;
    }

public:
    int iPublicTogg;
    void fPublicTogg(){
        fPrivateTogg();
    }

    Togg();
    ~Togg();

};

Togg::Togg() {
    cout << "Togg Constructor" << std::endl;
}

Togg::~Togg() {
    cout << "Togg Destructor" << std::endl;
}
int main(){

    Car car1;
    Mercedes mer1;
    Tesla tes1;
    Togg togg1;

    mer1.fPublic_mercedes();
    mer1.iPublicMercedes = 12;

    tes1.fPublic_Tesla();
    tes1.iPublicTesla = 15;

    togg1.fPublicTogg();
    togg1.iPublicTogg = 16;

    cout << "\n";
    mer1.showInformation();
    cout << "\n";
    tes1.showInformation();
    cout << "\n";
    togg1.showInformation();



}