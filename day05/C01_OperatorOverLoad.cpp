#include <iostream>

using namespace std;

class Koordinat{
    int x,y;

public:
    Koordinat(){x=0; y=0;}
    Koordinat(int i,int j) {x=i; y=j;}

    void get_xy(int &i,int &j){i=x; j=y;}
    Koordinat operator+ (Koordinat ob2); // operator + (biz + operator une overload yapicaz)
    //Burda + bu class icin kullanildiginda ne yapacagini soyleyecegiz

    Koordinat operator- (Koordinat ob2);

    Koordinat operator= (Koordinat ob2);

    Koordinat operator+ (int ob1);

    Koordinat operator++ ();

    Koordinat operator++ (int b);

    /*friend Koordinat operator+ (Koordinat ob2, int z);/*{

        Koordinat myTemp;
        myTemp.x = ob2.x + z;
        myTemp.y = ob2.y + z;

        return myTemp;
    };*/
    friend Koordinat operator+ (int z, Koordinat ob2);/*{

        Koordinat myTemp;
        myTemp.x = ob2.x + z;
        myTemp.y = ob2.y + z;

        return myTemp;
    };*/

    //friend Koordinat operator++ (int a,Koordinat ob2);

};

Koordinat Koordinat :: operator+ (Koordinat ob2){

    Koordinat myTemp;
    myTemp.x=x + ob2.x;
    myTemp.y=y + ob2.y;

    return myTemp;
}

Koordinat Koordinat :: operator- (Koordinat ob2){

    Koordinat myTemp;
    myTemp.x=x - ob2.x;
    myTemp.y=y - ob2.y;

    return myTemp;
}

Koordinat Koordinat :: operator = (Koordinat ob2){

    //Koordinat myTemp;
    x = ob2.x;
    y = ob2.y;

    return *this;
    //return myTemp;
}

Koordinat Koordinat :: operator+ (int a){

    Koordinat myTemp;
    myTemp.x= x + a;
    myTemp.y= y + a;

    return myTemp;
}

Koordinat Koordinat :: operator++ (){

    Koordinat myTemp;
    myTemp.x = x++;
    myTemp.y = y++;

    return myTemp;
}

Koordinat Koordinat :: operator++ (int notused){

    Koordinat myTemp;
    myTemp.x = ++x;
    myTemp.y = ++y;

    return myTemp;
}

/*Koordinat operator+ (Koordinat ob2,int a){

    Koordinat myTemp;
    myTemp.x = ob2.x + a;
    myTemp.y = ob2.y + a;

    return myTemp;
}*/

Koordinat operator+ (int a,Koordinat ob2){

    Koordinat myTemp;
    myTemp.x = ob2.x + a;
    myTemp.y = ob2.y + a;

    return myTemp;
}





int main(){

    Koordinat o1(10,10), o2(5,3),o3;
    int x,y;

    o3 = o1 + o2;
    o3.get_xy(x,y);
    cout<<x<<","<<y<<endl;

    o3 = o1 - o2;
    o3.get_xy(x,y);
    cout<<x<<","<<y<<endl;

    o3 = o1;
    o3.get_xy(x,y);
    cout<<x<<","<<y<<endl;

    o3 = o2 = o1;
    o3.get_xy(x,y);
    cout<<x<<","<<y<<endl;

    o3 = o1 + 5;
    o3.get_xy(x,y);
    cout<<x<<","<<y<<endl;

    ++o1;
    o1.get_xy(x,y);
    cout<<x<<","<<y<<endl;

    o1++;
    o1.get_xy(x,y);
    cout<<x<<","<<y<<endl;

    o3 =  5+o1+5;
    o3.get_xy(x,y);
    cout<<x<<","<<y<<endl;
//6. bolum sonuna kadar sinav
}
/*
garson- siparis girildi
ascı- siparis alindi
musteri- para odendi
kurye- siparis teslim edildi
 */