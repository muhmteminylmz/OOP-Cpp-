#include <iostream>

int main(){

    std::cout << "start\n";
    try{
        std::cout << "Inside try block\n";
        throw 10;
        std::cout << "This will not execute";
    }catch(int i){
        std::cout << "Bir hata yakaladim! Numarasi: ";
        std::cout << i << "\n";
    }

    std::cout << "end";

}