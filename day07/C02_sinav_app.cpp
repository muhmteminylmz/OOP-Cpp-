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
#include <fstream>

using namespace std;

class Ogrenci{
protected:

    int student_count,*student_grade,*kredi,max_kredi=45,max_ders=10;
    string *student_list,*student_ders_list;
    //kredi ve ders sayisi limit kontrol
public:

    Ogrenci(int ogrenci_sayisi) : student_count(ogrenci_sayisi){
        student_list = new string[student_count];
        student_grade = new int[student_count];
        student_ders_list = new string[student_count];
        kredi = new int[student_count];
        for(int i=0; i<student_count; i++){
            student_list[i] = "";
            student_ders_list[i] = "";
            student_grade[i] = 0;
            kredi[i] = 0;
        }
    }


    ~Ogrenci(){delete[] student_list; delete[] student_grade;delete[] kredi;delete[] student_ders_list;};

    void addStudent(int ogr_sinifi,string ogr_ad,int count){
        student_list[count] = ogr_ad;
        student_grade[count] = ogr_sinifi;
    }

    Ogrenci(const Ogrenci &ogr){
        student_count = ogr.student_count;
        student_list = new string[student_count];
        student_grade = new int[student_count];
        student_ders_list = new string[student_count];
        kredi = new int[student_count];
        for(int i=0; i<student_count; i++){
            student_list[i] = ogr.student_list[i];
            student_grade[i] = ogr.student_grade[i];
            student_ders_list[i] = ogr.student_ders_list[i];
            kredi[i] = ogr.kredi[i];
        }
    }

};

class Sinav{
protected:
    int sinav_count=0,*sinav_result;
    string *sinav_list;

public:

    Sinav(int sinav_sayisi) : sinav_count(sinav_sayisi){
        sinav_list = new string[sinav_count];
        sinav_result = new int[sinav_count];
        for(int i=0; i<sinav_count; i++){
            sinav_list[i] = nullptr;
        }
    }

    int puanBelirle(int exam_number,double etki_orani,double notu){
        sinav_result[exam_number] = etki_orani*notu;
        if(puanKontrol()){return sinav_result[exam_number];} else{return 0;}
    }

    int toplam_puan_belirle(){
        int toplam_result = 0;
        for(int i=0; i<sinav_count;i++){
            toplam_result += sinav_result[i];
        }
        return toplam_result;
    }

    bool puanKontrol(){
        int toplam_sinav_notu =0;
        for(int i=0; i<sinav_count;i++){
            toplam_sinav_notu += sinav_result[i];
        }
        if(toplam_sinav_notu==100) {return true;} else {return false;}

    }


    ~Sinav(){delete[] sinav_list;delete[] sinav_result;}

};

class Ders : public Ogrenci,public Sinav{

    string *ders_list;
    int ders_count,*ders_kredi;
public:

    Ders(int ders_sayisi) : Sinav(sinav_count),Ogrenci(student_count),ders_count(ders_sayisi) {
        ders_list = new string[ders_count];
        ders_kredi = new int[ders_count];
        for(int i=0; i<ders_count; i++){
            ders_list[i] = nullptr;
            ders_kredi[i] = 0;
        }
    }

    Ders(const Sinav &sinav, const Ogrenci &ogr, const Ders &ders) : Sinav(sinav), Ogrenci(ogr) {
        ders_count = ders.ders_count;
        ders_list = new string[ders_count];
        ders_kredi = new int[ders_count];
        for(int i=0; i<ders_count; i++){
            ders_list[i] = ders.ders_list[i];
            ders_kredi[i] = ders.ders_kredi[i];
        }
    }

    ~Ders(){delete[] ders_list;delete[] ders_kredi;}

    bool kredi_derscount_control(){
        int result;
        for(int i=0; i<student_ders_list->length(); i++){
            result += ders_kredi[i];
        }
        if(result<=max_kredi || student_ders_list->length()<=max_ders) {return true;} else {return false;}
    }

    void add_ders(string ders_ad,int kredi,int count){
        ders_list[count] = ders_ad;
        ders_kredi[count] = kredi;
    }

    void ders_ata(int ogrenci_index){
        int ders_index=0;
        while(ders_index != -1) {
            if(!kredi_derscount_control()){cout << "Maksimum 45 kredi ve 15 ders hakkiniz bulunmaktadir" << endl; break;}
            cin >> ders_index;
            if(ders_index == -1){break;}
            student_ders_list[ogrenci_index] = ders_list[ders_index];
            }
        }

    double ort_hesapla(){
        double avarage;
        for(int i=0;i<student_count;i++){
            for(int j;j<sinav_count;j++){
                avarage += toplam_puan_belirle();
            }
        }
        return avarage/student_count;
    }

};



int main(int argc, char *argv[]) {

    string ogr_ad,ders_ad;
    double etki_orani, notu;
    int sinav_sayisi, ders_sayisi, ogrenci_sayisi, ders_kredi,ogrenci_sinif;

    cout << "Lutfen Ogrenci sayisini giriniz:";
    cin >> ogrenci_sayisi;
    int i = 0;

        Ogrenci ogrenci(ogrenci_sayisi);

        do {
        cout << "Lutfen Ogrenci sinifini giriniz" << endl;
        cin >> ogrenci_sinif;
        cout << "Lutfen Ogrenci adini giriniz" << endl;
        cin >> ogr_ad;

        ogrenci.addStudent(ogrenci_sinif,ogr_ad,i);


        i++;
    } while (ogrenci_sayisi > i);

    i = 0;

    cout << "\nDers sayisini giriniz: ";
    cin >> ders_sayisi;

        Ders ders(ders_sayisi);
    do {
        cout << "Ders kredisini giriniz: ";
        cin >> ders_kredi;
        cout << "Ders adini giriniz: ";
        cin >> ders_ad;
        ders.add_ders(ders_ad,ders_kredi,i);
        i++;
    } while (ders_sayisi > i);

    i=0;

    cout << "\nLutfen sinav sayisini giriniz: ";
    cin >> sinav_sayisi;

        Sinav sinav(sinav_sayisi);
    i=0;
    cout << "Ogrenciye ders eklemeyi sonlandirmak icin -1 giriniz\nEklemek istediginiz dersleri index yardimiyla ekleyebilirsiniz" << endl;
    do{
        ders.ders_ata(i);
        for(int j=0; j<sinav_sayisi; j++) {
            cout << "Sinav etki oranini giriniz: ";
            cin >> etki_orani;
            cout << "Lutfen sinav notunu giriniz: ";
            cin >> notu;
            sinav.puanBelirle(j,etki_orani,notu);
        }

        i++;
    } while (i<=ogrenci_sayisi);

/*
    if(argc != 2){
        cout << "WRITE filename\n";
        return 1;
    }

    ofstream fout(argv[1]);

    for(int i=0; i<ogrenci_sayisi ; i++){
        //fout << ogrenci.student_list[i] << "\t" << ogrenci.student_grade << "\t" << ders.;
    }

    fout.close();
*/
}