#include<iostream>

using namespace std;

class Car{
/*

2 public deg
2 private deg
2 fonk 1 pr 1 pub

getter setter methodlar

*/
    public:
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
    Car car;

    cout << car.getId() << endl;
    cout << car.getPlaka() << endl;

    car.setId(12);
    car.setPlaka("67 KP 653");

    cout << car.getId() << endl;
    cout << car.getPlaka() << endl;

    cout << "hiz: " << car.hiz << endl;
    car.hizArttir(54);   


    cout << "Model: " << car.model << endl;
    cout << "Fiyat: " << car.price << endl;
}