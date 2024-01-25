#include <iostream>

using namespace std;

class Ogrenci{
    string *ogrenci_list;
    int *numara;
public:
    int ogrenci_sayisi;
    Ogrenci(int ogrenci_sayi) : ogrenci_sayisi(ogrenci_sayi){
        ogrenci_list = new string[ogrenci_sayisi];
        numara = new int[ogrenci_sayisi];
        for(int i = 0; i < ogrenci_sayisi;i++){
            ogrenci_list[i] = nullptr;
            numara[i] = 0;
    }
    }

    int bos_slot_bul(){
        for(int i=0;i<ogrenci_sayisi;i++){
            if(ogrenci_list[i] == ""){
                return i;
            }
        }
        return -1;
    }

    void ekle(string isim,int number){
        int index = bos_slot_bul();
        ogrenci_list[index] = isim;
        numara[index] = number;
    };

    void sil(int number){
        for(int i=0;i<ogrenci_sayisi;i++){
            if(numara[i] == number){
                ogrenci_list[i] = "";
                numara[i] = 0;
                break;
            }
        }
    }

    void guncelle(int number,string yeni_isim,int yeni_numara){

        for(int i=0;i<ogrenci_sayisi;i++){
            if(numara[i]==number){ogrenci_list[i] = yeni_isim;numara[i] = yeni_numara; break;}
        }}

    void listele(){
        for(int i=0;i<ogrenci_sayisi;i++){
            cout << "Ogrenci ad: " << ogrenci_list[i] << "\t ogrenci numara:  " << numara[i] << endl;
        }
    }

};


class Ders{

protected:
    string *ders_list;
public:
    int ders_count;
    Ders(int ders_count){
        ders_list = new string[ders_count];
        for(int i=0;i<ders_count;i++){
            ders_list[i] = "";
        }
    }

    void ekle(string ders){
        for(int i=0;i<ders_count;i++){
            if(ders_list[i] == ""){
                ders_list[i] = ders;
                break;
            }
        }
    }

    void sil(string ders){
        for(int i=0;i<ders_count;i++){
            if(ders_list[i] == ders){
                ders_list[i] = "";
                break;
            }
        }
    }

    void guncelle(string eski_ders,string yeni_ders){
        for(int i=0;i<ders_count;i++){
            if(ders_list[i] == eski_ders){
                ders_list[i] = yeni_ders;
                break;
            }
        }
    }

    void listele(){
        for(int i=0;i<ders_count;i++){
            cout << ders_list[i] << endl;
        }
    }

};

class Sinav {
    string *sinav_list;
    int *etki_oran;
    int *sinav_result_list;
public:
    int sinav_count;
    Sinav(int sinav_sayisi,int ogrenci_count,int ders_kodu,int numarasi) : sinav_count(sinav_sayisi){
        sinav_list = new string[sinav_count];
        etki_oran = new int[sinav_count];

        for(int i=0;i<sinav_count;i++){
            sinav_list[i] = "";
            etki_oran[i] = 0;
        }
    }

    void ekle(){
        string sinav;
        cout << "Lutfen sinav isimlerini sirasiyla giriniz" << endl;
        for(int i=0;i<sinav_count;i++){
            if(sinav_list[i] == ""){
                cin >> sinav;
                sinav_list[i] = sinav;
                break;
            }
        }
        set_etki_oran();
    }

    void sil(){
        cout << "Lutfen silmek istediğiniz sinav isimini giriniz" << endl;
        string isim;
        for(int i=0;i<sinav_count;i++){
            cin >> isim;
            if(sinav_list[i] != isim){
                sinav_list[i] = "";
                etki_oran[i] = 0;
                break;
            }
        }
    }

    /*void guncelle(string eski_sinav,string yeni_sinav){
        for(int i=0;i<sinav_count;i++){
            if(sinav_list[i] == eski_sinav){
                sinav_list[i] = yeni_sinav;
                break;
            }
        }
    }*/

    bool etki_oran_kontrol(){
        int result=0;
        for(int i=0;i<sinav_count;i++){
            result += etki_oran[i];
        }

        if(result<=100) return true;
        else return false;
    }

    void set_etki_oran() {
        do{
            cout << "Lutfen sirasiyla etki oranlarini sirasiyla giriniz" << endl;
            int etki_orani;
        for (int i = 0; i < sinav_count; i++) {
            cout << sinav_list[i] << ": ";
            cin >> etki_orani;
            etki_oran[i] = etki_orani;
        }
    }while(etki_oran_kontrol());
    }

    void listele(){
        for(int i=0;i<sinav_count;i++){
            cout << sinav_list[i] << "\t" << etki_oran[i] << endl;
        }
    }



};



class Not_Takip_Sistemi{
    Ogrenci ogrenciler;
    Ders dersler;
    Sinav sinavlar;

public:
    string isim,ders_ad,eski_ders_ad;
    int numara,eski_number;

    void Ana_Menu() {

        int choice = 0;
        do {
            cin >> choice;
            cout << "1. Ogrenci Ekleme" << endl;
            cout << "2. Ogrenci Silme" << endl;
            cout << "3. Ogrenci Guncelleme" << endl;
            cout << "4. Ders Ekleme" << endl;
            cout << "5. Ders Silme" << endl;
            cout << "6. Ders Guncelleme" << endl;
            cout << "7. Sinav Ekleme" << endl;
            cout << "8. Sinav Silme" << endl;
            cout << "9. Sinav Guncelleme" << endl;
            cout << "10. Ogrenci Listeleme" << endl;
            cout << "11. Ders Listeleme" << endl;
            cout << "12. Sinav Listeleme" << endl;
            cout << "13. Ogrenciye Ders ve Sinav ata" << endl;
            cout << "10000. Cikis" << endl;
            switch (choice) {
                case 1:
                    cout << "Lutfen ogrenci bilgilerini giriniz" << endl;
                    cin >> isim;
                    cin >> numara;
                    ogrenciler.ekle(isim,numara);
                    break;
                case 2:
                    cout << "Lutfen silmek istediginiz ogrenci numarasini giriniz" << endl;
                    cin >> numara;
                    ogrenciler.sil(numara);
                    break;
                case 3:
                    cout << "Degistirmek istediginiz ogrenci numarasi: ";
                    cin >> eski_number;
                    cout << "\nYeni isim: ";
                    cin >> isim;
                    cout << "\nYeni numara: ";
                    cin >> numara;
                    ogrenciler.guncelle(eski_number,isim,numara);
                    break;
                case 4:
                    cout << "\nLutfen ders adini giriniz: ";
                    cin >> ders_ad;
                    dersler.ekle(ders_ad);
                    break;
                case 5:
                    cout << "\nLutfen silmek istediginiz ders adini giriniz: ";
                    cin >> ders_ad;
                    dersler.sil(ders_ad);
                    break;
                case 6:
                    cout << "\nLutfen eski ders adini giriniz: ";
                    cin >> eski_ders_ad;
                    cout << "\nLutfen yeni ders adini giriniz: ";
                    cin >> ders_ad;
                    dersler.guncelle(eski_ders_ad,ders_ad);
                    break;
                case 7:
                    sinavlar.ekle();
                    break;
                case 8:
                    sinavlar.sil();
                    break;
                case 9:
                    //sinavlar.guncelle();
                    break;
                case 10:
                    ogrenciler.listele();
                    break;
                case 11:
                    dersler.listele();
                    break;
                case 12:
                    sinavlar.listele();
                    break;
                case 13:

                    break;
                default:
                    cout << "Yanlis deger girdiniz" << endl;


            }
        } while (choice != 13);



    }
};


int main(){

    //Not_Takip_Sistemi ob;
}