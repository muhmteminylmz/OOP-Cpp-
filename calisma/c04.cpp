#include <iostream>

using namespace std;

class A{

public:
    int x;
    int y;
    A operator +(A ob){
        A myTemp;
        myTemp.x= ob.x+x;
        return myTemp;
    }

    friend ostream& operator <<(ostream& os,A ob){
        os << "x : " << ob.x << " y : " << ob.y << endl;
        return os;
    }

     A operator ++(){
        A myTemp;
        myTemp.x= ++x;
        myTemp.y= ++y;
        return myTemp;
    }

    A operator ++(int notused){
        A myTemp;
        myTemp.x= x++;
        myTemp.y= y++;
        return myTemp;
    }
};


int main(){

    A ob1,ob2,ob3;
    ob1.x = 10;
    ob2.x = 15;

    ob3 = ob1+ob2;
    cout << ob3;

    ++ob3;
    ob3++;


}