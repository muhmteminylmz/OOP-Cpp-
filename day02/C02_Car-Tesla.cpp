#include <iostream>

using namespace std;

class araba {
private:
    int iPrivateVariableA;
    int iPrivateVariableB;
    void fSetPrivateVariables(int A, int B);
    void fPrintPrivateVariables();

public:
    int iPublicVariableA;
    int iPublicVariableB;
    void fSetPublicVariables(int A, int B);
    void fPrintPublicVariables();
    araba();
    ~araba();
};

araba::araba ()
{
    cout << "Araba Constructor\n";
}

araba::~araba()
{
    cout << "Araba Destructor\n";
}


class Tesla : public araba {
private:
    int ialtSinifPrivateDegisken;
    void fPrintPrivateVariablesAltSinif();

public:
    int ialtSinifPublicDegisken;
    void fPrintPublicVariablesAltSinif();
    Tesla();
    ~Tesla();
};

Tesla::Tesla()
{
    cout << "Tesla Constructor\n";
}

Tesla::~Tesla()
{
    cout << "Tesla Destructor\n";
}

int main()
{
/*    int a=5;
    if (a==5)
    {
        araba myX;
        //burda 2 bracket arasinda obje olusup bracket sonunda yok olur
    }

    araba myAraba;
 */
    Tesla myTesla;
    cout<<"Hello World\n";

    //   araba myAraba2;

    return 0;
}
