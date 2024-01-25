#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,char *argv[]) {

    if(argc != 2){
        cout << "WRITE filename\n";
        return 1;
    }

    ofstream fout(argv[1]);
    char str[80];
    cout <<"yazilanlar kayit ediliyor durmak icin $ yaziniz\n";
    do{
        cout << ":";
        cin >> str;
        fout << str << endl;
    } while (*str!='$');

//    fout.close();

    fout << "Avrasya Trabzon\n";//dosyaya yazdiriyoruz
    fout << 100 << endl;
    fout.close();

    ifstream fin("test");//dosyadan biseyler alip degiskenlere atiyoruz
    char str2(80);
    int i;

    while (fin.get(str2)) {
    cout << str2;

}
    fin.close();




    return 0;
}