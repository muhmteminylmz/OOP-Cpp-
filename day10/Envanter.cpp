#include <iostream>
 using namespace std;


class Envanter{
public:
    string *envanter;
    int esya_sayisi;
    int *zimmet_kontrol;
    Envanter(int x) : esya_sayisi(x){
        zimmet_kontrol = new int[esya_sayisi];
        envanter = new string[x];
        for(int i = 0; i < x;i++){
            zimmet_kontrol[i] = -1;
            envanter[i] = "";
        }
    }

    ~Envanter(){
        delete[] envanter;
    }

    void ekle(){
        string obje_ad;
        for(int i = 0; i <esya_sayisi;i++){
            cout << i << ". " << "Obje ad: ";
            cin >> obje_ad;
            envanter[i] = obje_ad;
            cout << endl;
        }
        listele();
    }

    void cikar(string obje_ad){
        for(int i = 0; i <esya_sayisi;i++){
            if(envanter[i] == obje_ad){
                envanter[i] = "";
            }
        }
        listele();
    }

    void listele(){
        for(int i = 0; i <esya_sayisi;i++){
            if(envanter[i] != ""){
                cout << i << ". " << envanter[i] << endl;
            }
        }
    }


};

class Yerleske{
public:
    string ad;
    Envanter ob;

};

class Kisi : public Envanter{

public:
    //bool kisi_sayisi_kontrol;
    string *kisi;
    int kisi_sayisi;
    Kisi(int kisi_cou) : kisi_sayisi(kisi_cou),Envanter(esya_sayisi){
        kisi = new string[esya_sayisi];
        for(int i = 0; i < esya_sayisi;i++){
            kisi[i] = "";
        }
    }

    void zimmetle(){
        cout << "Lutfen esyalari sirasiyla zimmetleyiniz: " << endl;
        listele();
        cout << "Lutfen kisi numarasini giriniz: " << endl;
        int kisi_index=0;
        for(int i = 0; i < esya_sayisi;i++){
            cout << envanter[i] << " : " << endl;
            zimmet_kontrol[i] = kisi_index;
        }
    }

};

class Ogrenci : public Kisi{
    string *ogrenci;
public:
    int ogrenci_sayisi;
    Ogrenci(int ogr_cou) : ogrenci_sayisi(ogr_cou), Kisi(kisi_sayisi){
        ogrenci = new string[ogr_cou];
        for(int i = 0; i < ogr_cou;i++){
            ogrenci[i] = "";
        }
    }

    void ogrenci_ekle(string ogrenci_ad){
        for(int i = 0; i < ogrenci_sayisi;i++){
            ogrenci[i] = ogrenci_ad;
            kisi[i] = ogrenci_ad;
            cout << ogrenci_ad << "\t kisi numara: " << i <<endl;

        }
    }

    void ogrenci_cikar(string ogrenci_ad){
        for(int i = 0; i < ogrenci_sayisi;i++){
            if(ogrenci[i] == ogrenci_ad){
                ogrenci[i] = "";
            }
        }
    }

};

class Personel : public Kisi{
    string *personel;
public:
    int pers_cou;
    Personel(int per_cou) : pers_cou(per_cou), Kisi(kisi_sayisi){
        personel = new string[per_cou];
        for(int i = 0; i < per_cou;i++){
            personel[i] = "";
        }
    }

    void personel_ekle(string personel_ad){
        for(int i = 0; i < pers_cou;i++){
            personel[i] = personel_ad;
            kisi[kisi_sayisi-pers_cou-1] = personel_ad;
            cout << personel_ad << "\t kisi numara: " << kisi_sayisi-pers_cou-1 << endl;
        }
    }

    void personel_cikar(string personel_ad){
        for(int i = 0; i < pers_cou;i++){
            if(personel[i] == personel_ad){
                personel[i] = "";
            }
        }
    }

};

int main(){

    int env_cou,kisi_cou,ogr_count,pers_count;
    cout << "Lutfen envanterde olacak esaya esya sayisini giriniz: " << endl;
    cin >> env_cou;
    Envanter env_ob(env_cou);

    cout << "Lutfen envanterdeki esya adini giriniz: " << endl;
    env_ob.ekle();

    cin >> kisi_cou;
    Kisi kisi_ob(kisi_cou);


    Ogrenci ogr_ob(ogr_count);

    Personel pers_ob(pers_count);




}
/*
 * envanter kisilere zimmetlenicek
 * kisilerde onaylama fonksiyonu kabul tarihi olucak
 * envanterden ve zimmetten dusme olucak
 * try catch olucak
 * template envanter icin
 * virtual kullan kisi de ozellikle
 * elektronik elektronik olmayan envanter class
 * sozlesme sinifi envantere iliskin baslama bitis tarihi,sozlesmenin tekrarlanabilirligi
 */