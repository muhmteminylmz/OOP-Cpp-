#include <iostream>

using namespace std;

/*
 3.) Palindrom, ileriye ve geriye doğru aynı olarak yazilan bir dize veya sayıdır. Örneğin, “radar” dizisi bir palindrom dizisidir.
 Benzer şekilde, 16461 sayısı sayısal bir palindromdur. Palindromu test etmek için aşırı yüklenmiş boolen işlev yazın.
Yalnızca bir tamsayı argümanı olduğunda ve eğer argüman sayısal bir palindrom ise fonksiyon true değerini döndürür.
Yalnızca bir C-string (karakter dizisi) argüman olduğunda karakter disizi olarak bir palindrom ise fonksiyon true değerini döndürür.
İki C-string argümanı olduğunda, birbirine birleştirilen iki dize bir palindrom ise işlev true değerini döndürür (test etmek için aslında iki dizeyi birleştirmeniz gerekmediğini unutmayın). Fonksiyonlarınızı test etmek için bir ana program yazın.(20)

 */
bool palindrom_control(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool palindrom_control(int number){
    string s = to_string(number);
    //daha rahat array olusturabilmek icin
    return palindrom_control(s);
}

bool palindrom_control(string s1,string s2) {
    string unionStr = s1+s2;

    int length = unionStr.length();
    for (int i = 0; i < length; i++) {

        if (unionStr[i] != unionStr[unionStr.length() - 1 - i]) {
            return false;
        }
//birlestirmeden yapmayi denedim ancak cok fazla if kullanmam gerektigi icin bu kodu daha optimize ve daha acik buldugum icin bunu kullandim
    }
    return true;

}
int main(){

    string s = "radar";
    int number = 16461;
    bool resultStr = palindrom_control(s);
    bool resultNum = palindrom_control(number);

    cout << "String icin Polindrom: " << resultStr << endl;
    cout << "Sayi icin Polindrom: " << resultNum << endl;

    string s2 = "radra";
    int number2 = 16641;
    bool resultStr2 = palindrom_control(s2);
    bool resultNum2 = palindrom_control(number2);

    cout << "String icin Polindrom: " << resultStr2 << endl;
    cout << "Sayi icin Polindrom: " << resultNum2 << endl;

    string s3 = "araba yolda";
    string s4 = "aabbaa";
    string s5 = "aab b aa";

    bool resultStr3 = palindrom_control(s3);
    bool resultStr4 = palindrom_control(s4);
    bool resultStr5 = palindrom_control(s5);

    cout << "String icin Polindrom: " << resultStr3 << endl;
    cout << "String icin Polindrom: " << resultStr4 << endl;
    cout << "String icin Polindrom: " << resultStr5 << endl;

    bool resultStr6 = palindrom_control(s,s);
    bool resultStr7 = palindrom_control(s3,s5);

    cout << "String icin Polindrom: " << resultStr6 << endl;
    cout << "String icin Polindrom: " << resultStr7 << endl;

    return 0;


}