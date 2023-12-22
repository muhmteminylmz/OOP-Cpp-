/*
 DERS
 input vize final ogrenci adi sinifi
 adi ve sinifini sorsun
 $ verene kadar dersleri alsun
 ort hesaplasin 40 a 60
 bunlari bir dosyaya kaydetsin

 */
//buna benzer soru gelicek
//1 tane 50p 2 tane kucuk program veya tanimlama
#include <iostream>

using namespace std;

class Ogrenci{

    string student_grade;
    int *student_list;
    //kredi ve ders sayisi limit kontrol
public:
    string ogrenci_ad;
    int kredi, ders_sayisi;
    Ogrenci(int ogrenci_sayisi,string ogrenci_sinif) : student_grade(ogrenci_sinif){
        student_list = new int[ogrenci_sayisi];
        for(int i=0; i<ogrenci_sayisi; i++){
            student_list[i] = 0;
        }
    }
    ~Ogrenci(){delete[] student_list;};

    bool kredi_control(){
        //return kredi>
    }

};

class Ders{

    int *ders_list,ders_count,*ders_kredi,max_kredi=40;
public:
    Ders(int ders_sayisi) : ders_count(ders_sayisi) {
        ders_list = new int[ders_count];
        ders_kredi = new int[ders_count];
        for(int i=0; i<ders_count; i++){
            ders_list[i] = 0;
            ders_kredi[i] = 0;
        }

    }
    ~Ders(){delete[] ders_list;}
    void set_ders_kredi(int ders_kredisi){
        ders_kredi[ders_count] = ders_kredisi;
    }

    bool kredi_control(){
        int result;
        for(int i=0; i<ders_count; i++){
            result += ders_kredi[i];
        }
        if(result<=max_kredi) {return true;} else {return false;}
    }
};


class Sinav{
    int *sinav_list,sinav_count;
public:
    string sinav_isim;
    double etki_orani;
    Sinav(int sinav_sayisi) : sinav_count(sinav_sayisi){
        sinav_list = new int[sinav_count];
        for(int i=0; i<sinav_count; i++){
            sinav_list[i] = 0;
        }
    }

    void puanBelirle(int exam_number,double etki_orani,double notu){
        sinav_list[exam_number] = etki_orani*notu;
    }

    bool puanKontrol(){
        int toplam_sinav_notu;
        for(int i=0; i<sinav_count;i++){
            toplam_sinav_notu += sinav_list[i];
        }
        if(toplam_sinav_notu==100) {return true;} else {return false;}

    }


    ~Sinav(){delete[] sinav_list;}

};




int main() {

    string ogrenci_sinif;
    double etki_orani, notu;
    int sinav_sayisi, ders_sayisi, ogrenci_sayisi, ders_kredi;

    cout << "Lutfen Ogrenci sayisini giriniz:";
    cin >> ogrenci_sayisi;
    int i = 0;
    do {
        cout << "Lutfen Ogrenci sinifi giriniz:";
        cin >> ogrenci_sinif;

        Ogrenci ogrenci(ogrenci_sayisi, ogrenci_sinif);
        i++;
    } while (ogrenci_sayisi > i);

    i = 0;

    cout << "\nDers sayisini giriniz: ";
    cin >> ders_sayisi;
    do {


        Ders ders(ders_sayisi);

        cout << "Ders kredisini giriniz: ";
        cin >> ders_kredi;
        ders.set_ders_kredi(ders_kredi);
        i++;
    } while (ders_sayisi > i);

    i=0;

    cout << "\nLutfen sinav sayisini giriniz: ";
    cin >> sinav_sayisi;
    do {

        Sinav sinav(sinav_sayisi);

        cout << "Sinav etki oranini giriniz: ";
        cin >> etki_orani;
        cout << "Lutfen sinav notunu giriniz: ";
        cin >> notu;

        sinav.puanBelirle(i, etki_orani, notu);
    i++;
    } while (sinav_sayisi > i);
}