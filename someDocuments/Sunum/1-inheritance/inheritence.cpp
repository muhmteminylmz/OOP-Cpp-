#include <iostream>

using namespace std;

//Parent(Mirasi Veren) Class
class Animal{

    public:
        void eat(){
            cout << "Hayvanlar yer" << endl;
        }

        void sleep(){
            cout << "Hayvanlar uyur" << endl;
        }
    
};

//Child(Mirasi alan) Class
class Cat : public Animal{

    public:
        void meow(){
            cout << "Kediler miyavlar" << endl;
        }
};

//Child(Mirasi alan) Class
class Dog : public Animal{

    public:
        void bark(){
            cout << "Kopekler kavlar" << endl;
        }
};

int main(){

    Cat cat;
    cat.eat();
    cat.sleep();
    cat.meow();
    //cat.bark();

    cout << "------------------" << endl;

    Dog dog;
    dog.eat();
    dog.sleep();
    dog.bark();
    //dog.meow();

}




/*
    Animal animal;
    animal.eat();
    animal.sleep();
    //animal.meow();
    //animal.bark();
*/