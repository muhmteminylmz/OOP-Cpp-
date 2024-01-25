#include <iostream>
#include <fstream>

using namespace std;



int main(){

    ofstream fout("calisma\\05.txt");
    char str(80);
    char chr = 'a';
    for(int i = 0; i <26;i++){
        fout << chr;
        chr++;
    }
    fout.close();

    ifstream fin("calisma\\05.txt");

    while(fin.get(str)){
        cout << str << endl;
    }
}