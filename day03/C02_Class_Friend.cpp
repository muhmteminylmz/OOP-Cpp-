#include <iostream>

using namespace std;

class myclass {
    int n, d;
public:
    myclass (int i,int j) {n=i, d=j;}
    friend int isFactor(myclass obj);
};


int isFactor(myclass ob){
    if(!(ob.n % ob.d)) return 1;
    else return 0;
}


int main(){
    myclass ob1(10,2), ob2(13,3);
    if(isFactor(ob1)) cout << "10, 2'nin katidir \n";
    else cout << "10, 2'nin kati degildir \n";

    if(isFactor(ob2)) cout << "13, 3'nin katidir \n";
    else cout << "13, 3'nin kati degildir \n";

    return 0;
}