#include<iostream>

using namespace std;

class Car{
    public:

        Car(string model,string price){
            this->model = model;
            this->price = price;

            cout << "Araba Olusturuldu." << endl;  
        }

        ~Car(){//destructor isimiz bittikten sonra memory de yer kaplamamasi icin class degiskenlerini siler

            cout << "Araba Yok Edildi." << endl;
        }



        string model = "BMW";

        int hiz = 54;

        string price = "1500000";

        void hizArttir(int miktar){
            hiz = hiz + miktar;
        }

        string getPlaka(){
            return plaka;
        }

        void setPlaka(string newPlaka){
            plaka = newPlaka;
        }

        int getId(){
            return carId;
        }

        void setId(int newId){
            carId = newId;
        }

    private:
        string plaka = "54 KC 960";

        int carId = 185;

        void bilgileriYazdir(){
            cout << "Plaka: " << plaka << endl;
            cout << "Id: " << carId << endl;
        }


    
};

int main(){
    Car car("Mercedes","8556220");

    cout << "Id: " << car.getId() << endl;
    cout << "Plaka: " << car.getPlaka() << endl;

    car.setId(12);
    car.setPlaka("68 KP 653");

    cout << "Id: " << car.getId() << endl;
    cout << "Plaka: " << car.getPlaka() << endl;

    cout << "hiz: " << car.hiz << endl;
    car.hizArttir(54);   


    cout << "Model: " << car.model << endl;
    cout << "Fiyat: " << car.price << endl;

    
}