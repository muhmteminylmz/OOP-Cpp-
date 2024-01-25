#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Ders {
public:
    std::string ad;
    int kod;

    Ders(std::string ad, int kod) : ad(ad), kod(kod) {}
};

class Ogrenci {
public:
    std::string ad;
    std::string soyad;
    int numara;

    Ogrenci(std::string ad, std::string soyad, int numara) : ad(ad), soyad(soyad), numara(numara) {}
};

class Not {
public:
    int ogrenciNumara;
    int dersKod;
    float notDegeri;

    Not(int ogrenciNumara, int dersKod, float notDegeri) : ogrenciNumara(ogrenciNumara), dersKod(dersKod), notDegeri(notDegeri) {}
};

class NotTakipSistemi {
private:
    std::vector<Ogrenci> ogrenciler;
    std::vector<Ders> dersler;
    std::vector<Not> notlar;

public:
    void ogrenciEkle(std::string ad, std::string soyad, int numara) {
        ogrenciler.push_back(Ogrenci(ad, soyad, numara));
    }

    void dersEkle(std::string ad, int kod) {
        dersler.push_back(Ders(ad, kod));
    }

    void notGirisi(int ogrenciNumara, int dersKod, float notDegeri) {
        notlar.push_back(Not(ogrenciNumara, dersKod, notDegeri));
    }

    void notHesapla() {
        // Not hesaplama mantığı buraya eklenebilir.
    }

    void notRaporuGoster() {
        // Not raporu gösterme mantığı buraya eklenebilir.
    }

    void dosyayaKaydet(std::string dosyaAdi) {
        std::ofstream dosya(dosyaAdi);

        if (dosya.is_open()) {
            for (const auto& ogrenci : ogrenciler) {
                dosya << "Ogrenci," << ogrenci.ad << "," << ogrenci.soyad << "," << ogrenci.numara << "\n";
            }

            for (const auto& ders : dersler) {
                dosya << "Ders," << ders.ad << "," << ders.kod << "\n";
            }

            for (const auto& nott : notlar) {
                dosya << "Not," << nott.ogrenciNumara << "," << nott.dersKod << "," << nott.notDegeri << "\n";
            }

            dosya.close();
            std::cout << "Veriler dosyaya kaydedildi.\n";
        } else {
            std::cerr << "Dosya acilamadi: " << dosyaAdi << "\n";
        }
    }

    void dosyadanYukle(std::string dosyaAdi) {
        std::ifstream dosya(dosyaAdi);
        std::string satir;

        if (dosya.is_open()) {
            while (getline(dosya, satir)) {
                std::string tip = satir.substr(0, satir.find(','));
                if (tip == "Ogrenci") {
                    size_t virgul1 = satir.find(',');
                    size_t virgul2 = satir.find(',', virgul1 + 1);
                    size_t virgul3 = satir.find(',', virgul2 + 1);

                    std::string ad = satir.substr(virgul1 + 1, virgul2 - virgul1 - 1);
                    std::string soyad = satir.substr(virgul2 + 1, virgul3 - virgul2 - 1);
                    int numara = std::stoi(satir.substr(virgul3 + 1));

                    ogrenciler.push_back(Ogrenci(ad, soyad, numara));
                } else if (tip == "Ders") {
                    size_t virgul1 = satir.find(',');
                    size_t virgul2 = satir.find(',', virgul1 + 1);

                    std::string ad = satir.substr(virgul1 + 1, virgul2 - virgul1 - 1);
                    int kod = std::stoi(satir.substr(virgul2 + 1));

                    dersler.push_back(Ders(ad, kod));
                } else if (tip == "Not") {
                    size_t virgul1 = satir.find(',');
                    size_t virgul2 = satir.find(',', virgul1 + 1);
                    size_t virgul3 = satir.find(',', virgul2 + 1);

                    int ogrenciNumara = std::stoi(satir.substr(virgul1 + 1, virgul2 - virgul1 - 1));
                    int dersKod = std::stoi(satir.substr(virgul2 + 1, virgul3 - virgul2 - 1));
                    float notDegeri = std::stof(satir.substr(virgul3 + 1));

                    notlar.push_back(Not(ogrenciNumara, dersKod, notDegeri));
                }
            }

            dosya.close();
            std::cout << "Veriler dosyadan yuklendi.\n";
        } else {
            std::cerr << "Dosya acilamadi: " << dosyaAdi << "\n";
        }
    }
};

int main() {
    NotTakipSistemi notTakipSistemi;

    notTakipSistemi.ogrenciEkle("Ali", "Can", 123);
    notTakipSistemi.ogrenciEkle("Ayse", "Yilmaz", 456);

    notTakipSistemi.dersEkle("Matematik", 101);
    notTakipSistemi.dersEkle("Fizik", 202);

    notTakipSistemi.notGirisi(123, 101, 85.5);
    notTakipSistemi.notGirisi(456, 101, 78.0);
    notTakipSistemi.notGirisi(123, 202, 90.0);

    notTakipSistemi.notHesapla();
    notTakipSistemi.notRaporuGoster();

    notTakipSistemi.dosyayaKaydet("veriler.txt");
    notTakipSistemi.dosyadanYukle("veriler.txt");

    return 0;
}
