#include <iostream>

using namespace std;

class samp {
  int _a, _b;
public:
    samp(int _n, int _m){_a = _n; _b = _m;}
    int get_a() {return _a;}
    int get_b() {return _b;}
};

int main() {
    samp ob[4] = {samp(1,2),samp(3,4),samp(5,6),samp(7,8)};

    int _i;
    samp *p;
    p=ob;
    for(_i=0;_i<4;_i++){
        cout << p -> get_a() << ' ';
        cout << p -> get_b() << '\n';
        cout << p << '\n';
        p++;//bu samp nesnesinin memory de kapladigi yer kadar arttir demek
}

    cout << "\n";

}