#include <iostream>
using namespace std;

void do_calc(int n1, int& n2);
int main() {
    int num1 = 1;
    int num2 = 2;
    do_calc(num2,num1);
    cout << num2 << " " << num1 << endl; }

void do_calc(int n1, int& n2) {
    n1 = n1 + 5;
    n2 = n2 * 5;
    cout << n2 << " " <<n1<<endl;
}