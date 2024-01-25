#include <iostream>

using namespace std;


class Not{

public:
    int ogr_num;
    int ders_kod;
    int not_sonuc;
    Not(int ogrenci_numara,int ders_kodu,int not_sonucu) : ogr_num(ogrenci_numara),ders_kod(ders_kodu),not_sonuc(not_sonucu) {}
    Not(){}

};

class Ogrenci{
    string *ogrenci_list;
    int *numara;
public:
    int ogrenci_sayisi;
    Ogrenci(int ogrenci_sayi) : ogrenci_sayisi(ogrenci_sayi){
        ogrenci_list = new string[ogrenci_sayisi];
        numara = new int[ogrenci_sayisi];
        for(int i = 0; i < ogrenci_sayisi;i++){
            ogrenci_list[i] = "";
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

    int ogr_idx_bul(int number){
        for(int i=0;i<ogrenci_sayisi;i++)
            if(numara[i] == number)
                return i;
        return -1;
    }

    virtual void ekle(string isim,int number){
        int index = bos_slot_bul();
        ogrenci_list[index] = isim;
        numara[index] = number;
    };

    virtual void sil(int number){
        for(int i=0;i<ogrenci_sayisi;i++){
            if(numara[i] == number){
                ogrenci_list[i] = "";
                numara[i] = 0;
                break;
            }
        }
    }

    virtual void guncelle(int number,string yeni_isim,int yeni_numara){

        for(int i=0;i<ogrenci_sayisi;i++){
            if(numara[i]==number){ogrenci_list[i] = yeni_isim;numara[i] = yeni_numara; break;}
        }}

    virtual void listele(){
        for(int i=0;i<ogrenci_sayisi;i++){
            cout << "Ogrenci ad: " << ogrenci_list[i] << "\t ogrenci numara:  " << numara[i] << endl;
        }
    }

};


class Ders : public Ogrenci{

protected:
    string *ders_list;
public:
    int ders_count;
    Ders(int ders_count,int ogrenci_count) : Ogrenci(ogrenci_count){
        ders_list = new string[ders_count];
        for(int i=0;i<ders_count;i++){
            ders_list[i] = "";
        }
    }

    void ekle(const string& ders){
        for(int i=0;i<ders_count;i++){
            if(ders_list[i].empty()){
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



class Sinav : public Ders{
    string *sinav_list;
    int *etki_oran;

public:
    Not *notlar;
    int sinav_count;
    int *sinav_result_list;
    Sinav(int sinav_sayisi,int ders_count,int ogrenci_count) : Ders(ders_count,ogrenci_count),sinav_count(sinav_sayisi){
        sinav_list = new string[sinav_count];
        etki_oran = new int[sinav_count];
        notlar = new Not[ogrenci_count*sinav_count];
        sinav_result_list = new int[ogrenci_sayisi];
        for(int i=0;i<sinav_count;i++){
            sinav_list[i] = "";
            etki_oran[i] = 0;
            sinav_result_list[i] = 0;
        }
    }

    void ekle(){
        for(int i=0;i<sinav_count;i++){
            if(sinav_list[i].empty()){
                cout << "Lutfen " << i+1 << ". " << "sinav isimini giriniz: ";
                cin >> sinav_list[i];
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

        if(result==100) return true;
        else return false;
    }

    void set_etki_oran() {
        do {
            cout << "Lutfen sirasiyla etki oranlarini sirasiyla giriniz" << endl;
            for (int i = 0; i < sinav_count; i++) {
                cout << sinav_list[i] << ": ";
                cin >> etki_oran[i];
            }
        } while (!etki_oran_kontrol());
    }

    void listele(){
        for(int i=0;i<sinav_count;i++){
            cout << sinav_list[i] << "\t" << etki_oran[i] << endl;
        }
    }

    int not_Hesapla(int notlar[]){
        int result=0;
        for(int i=0;i<sinav_count;i++){
            result += sinav_result_list[i]*etki_oran[i];
        }
        return result;
    }

    void not_Gir(int ogr_num,int ders_idx,int not_sonuc[]){
        int ogr_idx = ogr_idx_bul(ogr_num);
        int genel_not = not_Hesapla(not_sonuc);
        Not ob(ogr_num,ders_idx,genel_not);
        notlar[ogr_idx] = ob;
    }

    void ogr_durum_listele(){
        for(int i=0;i<ogrenci_sayisi;i++){
            cout << "ogrenci_numara: "<< notlar[i].ogr_num << endl;
            //cout << "Ogrenci dersleri"
        }
    }


};




class Not_Sistemi{
    int ogrenci_sayisi,ders_sayisi,sinav_sayisi;
public:

    void Ana_Menu(){

        cout << "Ogrenci sayisi: ";
        cin >>  ogrenci_sayisi;
        cout << "Ders sayisi: ";
        cin >> ders_sayisi;
        cout << "Sinav sayisi: ";
        cin >> sinav_sayisi;

        Ogrenci *p1;
        Ders *p2;
        Sinav ob(sinav_sayisi,ders_sayisi,ogrenci_sayisi);

        p1 = &ob;
        p2 = &ob;

        p1 ->ekle("Ahmet",200);
        p1 ->ekle("Mehmet",210);

        p2->ekle("Mat");
        p2->ekle("Edebiyat");

        ob.ekle();

        p1 -> listele();
        p2 -> listele();
        ob.listele();


    }
};



int main(){

    Not_Sistemi ob;
    ob.Ana_Menu();
}