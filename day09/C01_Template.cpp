#include <iostream>


template <class X>
void swapargs(X &a,X &b){
    X temp;
    temp =a;
    a = b;
    b= temp;
}// amac 1 fonksiyonla hem int hem float icin iseyararlilik saglama

int main() {
    int i = 10, j = 20;
    float x = 2.0, y = 3.1;

    std::cout << "Orijinal i,j: " << i << ", " << j << std::endl;
    std::cout << "Orijinal x,y: " << x << ", " << y  << std::endl;
    swapargs(i,j);
    swapargs(x,y);
    std::cout << "Swapped i,j: " << i << ", " << j << std::endl;
    std::cout << "Swapped x,y: " << x << ", " << y  << std::endl;
}