#include <iostream>
#include <cmath>


using namespace std;

/*
 2.)  Bir noktanın koordinat sistemide  X ve Y koordinatlarını tutacak bir Nokta sınıfı tanımlayın.
Sınıfın yapıcı ve yıkıcılarını tanımlayın. Parametre olarak verilen başka bir Nokta sınıfı ile arasındaki mesafeyi hesaplayan pDistance(Nokta) işlevini yazın.
Nokta dizisi (bir yolu ifade eder) ve boyutunu giriş olarak alan pathLength(Nokta[], int) yapısında bir işlev yazın ve pDistance işlevini kullanarak yol uzunluğunu belirleyin.
 Bir ana program yazın kurgunuzu test edin. (20)
 */

class Nokta{

    int x,y;

public:

    Nokta(int a,int b) { x = a; y = b;};
    ~Nokta(){};


    int pDistance(Nokta ob) {

        return sqrt( ((ob.x - x) * (ob.x - x)) + ((ob.y - y) * (ob.y - y)) );

    }

};

int pathLength(Nokta ob[],int a) {

    int result =0;
    for (int i=0; i < a-1; i++){
        result += ob[i].pDistance(ob[i+1]);
    }
    return result;
}

int main(){

    Nokta ob1(10,20),ob2(10,25),ob3(20,30);

    Nokta ob[] = {ob1,ob2,ob3};
    int diziUzunluk = sizeof(ob) / sizeof(ob[0]);
    int result = pathLength(ob,diziUzunluk);
    cout << "Sonuc: " << result;

}//erdogan.bozkurt@avrasya.edu.tr
