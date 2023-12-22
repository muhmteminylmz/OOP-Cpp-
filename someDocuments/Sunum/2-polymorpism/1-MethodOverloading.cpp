#include <iostream>

using namespace std;

// method overloading ayni isimli farkli parametreli methodlara denir

int add(int a, int b)
{
    return a + b;
}

int add(int a, float b)
{
    return a + b;
}

int add(float a, float b)
{
    return a + b;
}

int main()
{

    cout << add(2, 5) << endl; // 1.method

    cout << add(2, 5.7f) << endl; // 2.method

    cout << add(2.4f, 5.8f) << endl; // 3.method
}