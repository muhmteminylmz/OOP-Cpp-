#include <iostream>

using namespace std;

class Person{
    
    private:
        int maas=100;

    public:
        string Ad = "Ahmet Ertugrul"; //bu degiskeni public olarak atadik

    // Setter = Bu method sayesinde normalde erisemedigimiz parametreyi degistirebiliyoruz
    void setMaas(int salary) {
      maas = salary;
    }
    // Getter = Bu methodla normalde erisemedigimiz parametreyi gorebiliyoruz
    int getMaas() {
      return maas;
    }   

};

int main(){
    Person person;

    cout << person.Ad << endl;
 
    //cout << person.maas << endl;

    cout << person.getMaas() << endl;
 
    person.setMaas(1000);
 
    cout << person.getMaas();
}