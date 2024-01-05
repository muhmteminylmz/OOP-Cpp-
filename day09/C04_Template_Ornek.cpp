#include <iostream>
/*
 * bir sinif 2 degisken type1 type2
 * bir cons olucak aldigi 2 degiskenide ekrana yazdiricak
 * show fonksiyonu ile birlikte
 */

template <typename type1, typename type2>
class Sinif {
    type1 degisken1;
    type2 degisken2;
public:
    Sinif(type1 param1, type2 param2) : degisken1(param1), degisken2(param2) {}

    void show() {
        std::cout << degisken1 << " " << degisken2 << std::endl;
    }
};

int main(){
    Sinif<int,char> ob(3,'H');
    Sinif<double, std::string> ob2(3.5, "Merhaba");

    ob.show();
    ob2.show();
    return 0;

}