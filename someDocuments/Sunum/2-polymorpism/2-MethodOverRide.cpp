#include <iostream>

using namespace std;

//bir parent class daki methodu child class da farkli bir sekilde kullanmaya method override denir. 

class Animal{

    public:
        virtual void run(){
            cout << "Hayvanlar Kosar" << endl;
        }
    
};

class Cat : public Animal{

    public:
        void run() override{
            cout << "Kediler Kosar" << endl;
        }
};

class Dog : public Animal{

    public:
        
        void run() override{
            cout << "Kopekler Kosar" << endl;
        }
};

int main(){

    Cat cat;
    cat.run();

    cout << "------------------" << endl;

    Dog dog;
    dog.run();

    cout << "------------------" << endl;

    Animal animal;
    animal.run();

}