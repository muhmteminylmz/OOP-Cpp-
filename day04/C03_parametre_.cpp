#include <iostream>

using namespace std;

float f(float i){
    return i/2.0;
}

double f(double i){
    return i/5.0;
}

int main(){

    float x=10.00;
    double y=10.00;

    cout << f(x) << endl;
    cout << f(y) << endl;

    //cout << f(10);
    //double veya float oldugunu anlamadigi icin fonksiyon calismaz



    return 0;

}