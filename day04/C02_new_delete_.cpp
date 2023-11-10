#include <iostream>

using namespace std;

class Array {
    int *p;
    int size;

public :
    Array(int sz){
        p= new int [sz];
        if (!p) exit (1);
        size=sz;
        cout<<"using normal constructor\n";
    }
    ~Array (){delete [] p;}
    //    array (const array &a);

    void put (int i, int j){
        if(i>0 &&i<size) p[i]=j;
    }

    int get(int i){
        return p[i];
    }

    Array(const Array &a){
        int i;
        size=a.size;
        p=new int[a.size];
        if (!p) exit (1);
        for (i=0;i<a.size;i++) p[i]=a.p[i];
        cout<<"using copy constructor\n";
    }
};




int main()
{
    int xx = 99;
    Array num(10);
    int i;

    for (i=0;i<xx;i++) num.put(i,i);

    for (i=xx;i>=0;i--) cout << num.get(i);
    cout << '\n';

    Array x =num;
    for (i=0;i<xx;i++) cout << x.get(i);


    return 0;
}