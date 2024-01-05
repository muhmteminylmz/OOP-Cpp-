#include <iostream>

// 1 pub 2 pri deg 1 pr f 2 pub deg 1 cons 1 desc

class Car{
private:
    int speed = 50;
    int price = 1000000;

public:

    Car(){
        std::cout << "Car Constructor" << std::endl;
    }
    Car(std::string marka, std::string tekerlek_sayisi);

    std::string marka;
    std::string tekerlek_sayisi;

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
    Car::Car(std::string marka, std::string tekerlek_sayisi) {
        this->marka = marka;
        this->tekerlek_sayisi = tekerlek_sayisi;
    }

    Car::~Car() {
        std::cout << "Car Destructor" << std::endl;
    }

class Mercedes : public Car{

private:
    int ialtSinifPrivateDegisken;
    void fPrintPrivateVariablesAltSinif();

public:
    int ialtSinifPublicDegisken;
    void fPrintPublicVariablesAltSinif();

    Mercedes();
    ~Mercedes();
};

Mercedes::Mercedes(){
    std::cout << "Mercedes Constructor" << std::endl;
}

Mercedes::~Mercedes(){
    std::cout << "Mercedes Destructor" << std::endl;
}

int main(){
    if(true){
        Car c1;
        //burda 2 bracket arasinda obje olusup bracket sonunda yok olur
    }

    Mercedes mer1;

    std::cout << "Hello World" << std::endl;

    Car c2;




    /*Car Mercedes("Mercedes","4");

    std::cout << "Araba Ozellikleri:" << std::endl;
    Mercedes.showInformation();

    Mercedes.hiz_arttir(50);
    Mercedes.deger_degistir(54300);
    Mercedes.set_speed(200);
    Mercedes.hiz_arttir(50);

    Mercedes.showInformation();*/
}