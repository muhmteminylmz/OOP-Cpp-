#include <iostream>

using namespace std;

/*
 4.) …Uygun yapıcılar, erişimciler ve işlevler bir sınıf Dikdörtgen sınıfı tanımlayın.
    //• Sınıfın veri üyeleri uzunluğu ve genişliği double türünde olmalıdır. Ek olarak sol alt köşesinin koordinatını belirten bir Nokta sınıfı içermelidir (2. soruda oluşturulan).
    //• Sol alt köşesi koordinat düzleminin başlangıç noktasında olan 1x1 birim dikdörtgen oluşturmak için varsayılan bir yapıcı (constructor) tanımlayın.
    • Belirtilen konumda belirtilen boyutta bir dikdörtgen oluşturmak iki çift ve bir Nokta kabul eden aşırı yüklenmiş bir kurucu tanımlayın.
    • Sol alt köşesi koordinat düzleminin başlangıç noktasında bulunan belirtilen boyuttaki dikdörtgen tanımlamak için iki çift kabul eden aşırı yüklenmiş bir yapıcı tanımlayın.
    //• Sınıf uygun erişimci işlevlerine sahip olmalıdır (get&set).
    //• Sınıfın dikdörtgen alanını hesaplamak için getArea() üye fonksiyonuna sahip olması gerekir/
    • Sınıfın bir boolean dönüşlü üye fonksiyonu olmalıdır ve işlevi dikdörtgenin ve giriş parametresindeki dikdörtgenin kesişip kesişmediklerini belirlemektir.
    //• Sınıfın, Varsayılanı '*' olan argümanda verilen karakter ile Dikdörtgenin şeklini çizmek için (konumu düşünmeden) varsayılan bağımsız değişkeni olan bir üye işlevi Draw(char) olmalıdır.

Sınıfınızı test etmek için bir ana program yazın (30).
 */

class Nokta{

public:

    double x=0.0,y=0.0;
    Nokta(){};
    Nokta(double a,double b) { x = a; y = b;};
    ~Nokta(){};
};

class Dikdortgen : public Nokta{

    double length,width;
    Nokta left_bottom;

public:

    Dikdortgen() : left_bottom(0,0), length(1.0), width(1.0) {}

    Dikdortgen(double var_length, double var_width,Nokta ob) : left_bottom(ob.x, ob.y){
        length = var_length;
        width = var_width;
    }

    Dikdortgen(double var_length, double var_width) : left_bottom(0,0){
        length = var_length;
        width = var_width;
    }

    double getArea(){
        return length * width;
    }


    /*bool isInside(Dikdortgen ob) {
        //abs= mutlak
        double x_distance = abs(ob.x - left_bottom.x);
        double y_distance = abs(ob.y - left_bottom.y);

        if((x_distance < (ob.length + length)) && (y_distance < (ob.width + width))){return true;} else {return  false;}
    }duzgun calismadigi icin devre disi
     */


     bool isInside(Dikdortgen ob) {

        bool b1 = left_bottom.x + length <= ob.left_bottom.x;
        bool b2 = left_bottom.x >= ob.left_bottom.x + ob.length;//ana dikdortgenin solunda
        bool b3 = left_bottom.y + width <= ob.left_bottom.y;
        bool b4 = left_bottom.y >= ob.left_bottom.y + ob.width;//ana dikdortgenin altinda

        if (b1 || b2 || b3 || b4) {return false;} else {return true;}
    }


    void draw(char ch='*'){
        for (int i=0; i< width; i++){
            for (int j=0; j< length; j++){
                cout << ch;
            }
            cout << "\n";//ici dolu diktortgen
        }
    }


    double get_length(){
        return length;
    }
    double get_width(){
        return width;
    }
    Nokta get_left_bottom(){
        return left_bottom;
    }
    void set_length(double var_length){
        length = var_length;
    }
    void set_width(double var_width){
        width = var_width;
    }
    void set_left_bottom(Nokta var_left){
        left_bottom = var_left;
    }

    void set_information(double var_width, double var_length,Nokta var_left_bottom){
        set_width(var_width);
        set_length(var_length);
        set_left_bottom(var_left_bottom);
    }

};

void write_information(Dikdortgen ob){
    cout << "width: " << ob.get_width() << " | length: " << ob.get_length() << " | left_bottom_x: "
         << ob.get_left_bottom().x << " | left_bottom_y: " << ob.get_left_bottom().y << endl;
}



int main(){

    Dikdortgen ob1(5.0,3.0),ob2,ob3(3.0,2.0,Nokta(4.0,3.0)),ob4(0.5,0.5,Nokta(20,25));

    cout << "Alan: " << ob1.getArea() << endl;
    cout << "Alan: " << ob2.getArea() << endl;
    cout << "Alan: " << ob3.getArea() << endl;

    cout << "Kesisim kontrol: " << ob1.isInside(ob2) << endl;
    cout << "Kesisim kontrol: " << ob1.isInside(ob4) << endl;
    write_information(ob1);
    write_information(ob2);

    ob1.draw('#');
    cout << endl;

    ob1.draw();
    cout << endl;

    ob2.draw();
    cout << endl;

    ob3.draw();
    cout << endl;

    write_information(ob3);
    ob3.set_information(4.0,5.0,Nokta(0,0));
    write_information(ob3);


}