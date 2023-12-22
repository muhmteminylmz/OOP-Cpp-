#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream fout("test");

    fout <<"Avrasya\n";
    fout << 100 << ' ' << hex << 100 << endl;
    fout.close();

    ifstream fin("test");
    char str[80];
    int i;
    fin >> str;

    cout << str << ' ' << i << endl;

    fin.close();




    return 0;
}