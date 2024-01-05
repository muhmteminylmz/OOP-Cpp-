#include <iostream>

using namespace std;

class myclass {
    int n, d;
public:
    //eger variable lar private olarak tanimliysa this kullanamdan icine biseyler koyabiliyoruz.(arastirilmali)
    myclass (int i,int j) {n=i, d=j;}
    friend int isFactor(myclass obj);

    void writeNandD(){
        cout << "n: " << n << " d: " << d  << endl;
    }
};


int isFactor(myclass ob){
    if(!(ob.n % ob.d)) return 1; //fonksiyon class icinde olmamasina ragmen private degerlere erisebildi.
    else return 0;
}


int main(){
    myclass ob1(10,2), ob2(13,3);
    if(isFactor(ob1)) cout << "10, 2'nin katidir \n";
    else cout << "10, 2'nin kati degildir \n";

    ob1.writeNandD();
    ob2.writeNandD();

    if(isFactor(ob2)) cout << "13, 3'nin katidir \n";
    else cout << "13, 3'nin kati degildir \n";

    return 0;
}