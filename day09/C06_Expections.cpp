#include <iostream>

using namespace std;

void Xhandler(int test){
    try{
        if(test) throw test;
        else throw "Value is zero";
    }catch (int i){
        std::cout << "Bir tane yakaladim! Ex. #:" << i << "\n";
    }catch(const char *str){
        std::cout << "Bir tane string yakaladim: ";
        std::cout << str << "\n";
    }
}

int main(){

    std::cout << "start" << "\n";

    Xhandler(1);
    Xhandler(2);
    Xhandler(0);
    Xhandler(3);

    std::cout << "end" << "\n";

    return 0;
}