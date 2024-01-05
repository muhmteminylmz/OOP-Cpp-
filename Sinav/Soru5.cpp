#include <iostream>

using namespace std;

/*
 5.) Bir Anket sınıfı uygulamasını yazın.
   • N sayısının anketteki değerlendirilecekleri ifade eden bir anket oluşturan Anket(int n)
    • Her birinin oy sayısı 0 olarak başlatılan,
    • void addVote(int opt) ile ankette parametre ile verilen seçeneğe bir oy ekleyen veya seçenek geçersizse (0,…n−1 aralığında değilse) hiçbir şey yapmayan,
    • int getLeader(), şu anda en çok oyu alan seçeneğin indeksini döndüren,
    • Anket döndüren merge(anket), anket ve diğeri aynı sayıda seçeneğe sahip olduğu sürece, her seçeneğin oy toplamının iki anketteki toplamlarının toplamı olduğu yeni bir anket oluşturan fonksiyonları oluşturun.
    • Mevcut oy sayılarını bir Ankette [1, 2, 3, 4] gibi bir formatta çıkarmak için << operatörünü aşırı yükleyin.
    • += ve + operatörlerini aşırı yükleyin; böylece Anketler p1 ve p2 ve int i için p1 += i, p.addVote(i) ile aynı işleve sahip olur ve p1 + p2, p1.merge(p2) ile aynı işleve sahip olur,
    • Anketi dinamik olarak tahsis edilmiş bir dizi kullanacak şekilde yazın ve kopya oluşturucuyu, //taşıma oluşturucuyu, atama operatörünü, taşıma atama operatörünü// ve yıkıcıyı yazın (30)
 */

class Anket{

    int anket_option_count;
    int *anket_option_list;

public:


    Anket(int n){
        anket_option_count = n;
        anket_option_list = new int[anket_option_count];
        for(int i=0; i<anket_option_count; i++){
            anket_option_list[i] = 0;
        }
    };
    ~Anket(){delete[] anket_option_list;}

    Anket(const Anket& copy){

        anket_option_count = copy.anket_option_count;
        anket_option_list = new int[anket_option_count];
        for(int i=0; i<anket_option_count; i++){
            anket_option_list[i] = copy.anket_option_list[i];
        }
    }

    Anket& operator=(Anket obj){
        if (this != &obj)
        {
            delete[] anket_option_list;
            anket_option_count = obj.anket_option_count;
            anket_option_list = new int[anket_option_count];
            for(int i=0; i<anket_option_count; i++){
                anket_option_list[i] = obj.anket_option_list[i];
            }
        }
        return *this;

    }



    void addVote(int opt){
        if(anket_option_count >= opt && anket_option_count > 0){
            anket_option_list[opt - 1] += 1;
        }
    }

    int getLeader(){
        int max = 0;
        int maxIndex = 0;
        for(int i=0; i<anket_option_count; i++){
            if(anket_option_list[i] > max){
                max = anket_option_list[i];
                maxIndex = i;
            }
        }
        return maxIndex;

    }


    int getAnketOptionCount(){
        return anket_option_count;
    }


    Anket merge(Anket ob) {

       if(anket_option_count != ob.anket_option_count){
           cout << "Anketlerin degerlendirilecek secenek sayisi ayni degil!! \n";
           return Anket(0);
       }


        /*Anket(Anket&& other){//move sematikleri kopyalama yapmadan direkt yeni objeye deger atamasi icin kullanilir
            //ilgili adres ve boyutu aldık
            anket_option_count = other.anket_option_count;
            anket_option_list = other.anket_option_list;

            //kaynak isaretcisi icin adreslenen kaynagi biraktik
            //bu olmassa bellek fazla bosaltma yapar
            other.anket_option_count = 0;
            other.anket_option_list = nullptr;

        }

        Anket& operator=(Anket&& assign){

            if (this != &assign)
            {
                // Mevcut verileri boşalt
                delete[] anket_option_list;

                // Gelen veri işaretçisinden ilgili adresi ve boyutu aliyoruz
                anket_option_list = assign.anket_option_list;
                anket_option_count = assign.anket_option_count;

                //kaynak isaretcisi icin adreslenen kaynagi biraktik
                //bu olmassa bellek fazla bosaltma yapar (move consta olandan)
                assign.anket_option_list = nullptr;
                assign.anket_option_count = 0;
            }
            return *this;

        }*/

       Anket myTemp(anket_option_count);

       for(int i=0; i<anket_option_count; i++){
           myTemp.anket_option_list[i] = anket_option_list[i] + ob.anket_option_list[i];
       }
        return myTemp;

       /*int count =0;
        int k = ob.getAnketCount()-1;
        bool b1 = false;

        for(int i=0; i<ob.getAnketCount(); i++){

            for(int j=count; j< k;j++){
                if(anket_option_list[i] == ob.anket_option_list[j] && i!=j){
                    myTemp.anket_option_list[count] = ob.anket_option_list[i]*2;
                    b1 = true;
                    break;
                }

            }
            if(b1) {
                myTemp.anket_option_list[count] = ob.anket_option_list[i];
                b1 = false;
            }
            count++;
            k--;

        }*/

    }
    //direkt cout icin operator asiri yukledik boylece cout << kullaninca ne olacagini belirliyoruz
    friend ostream& operator<<(ostream& out, Anket& ob){ // ostream& icin internetten yardim aldim.
        out << "[";
        for(int i=0; i<ob.anket_option_count; i++){
            if(i==ob.anket_option_count-1){out << ob.anket_option_list[i]; break;}
            out << ob.anket_option_list[i] << " ,";
        }
        out << "]";
        return out;
    }


    Anket operator+(Anket ob){
        Anket myTemp(anket_option_count);
        for(int i=0; i<anket_option_count; i++){
            myTemp.anket_option_list[i] = anket_option_list[i] + ob.anket_option_list[i];
        }
        return myTemp;
    }

    Anket operator+=(int opt){
        anket_option_list[opt] += 1;
        return *this;
    }



};




int main() {
    Anket ob(5),ob2(5),ob3(6);

    ob.addVote(5);
    ob.addVote(5);
    ob.addVote(1);

    ob2.addVote(1);
    ob2.addVote(2);
    ob2.addVote(2);
    ob2.addVote(5);

    ob3.addVote(1);
    ob3.addVote(5);
    ob3.addVote(6);
    ob3.addVote(6);

    cout << "Anket secenek sayisi :" << ob.getAnketOptionCount() << endl;
    cout << "Anket secenek sayisi :" << ob2.getAnketOptionCount() << endl;
    cout << "Anket secenek sayisi :" << ob3.getAnketOptionCount() << endl;

    int i_leader_index1 = ob.getLeader();
    int i_leader_index2 = ob2.getLeader();
    int i_leader_index3 = ob3.getLeader();

    cout << "Anket1 maxin indexi : " << i_leader_index1 << endl;
    cout << "Anket2 maxin indexi : " << i_leader_index2 << endl;
    cout << "Anket3 maxin indexi : " << i_leader_index3 << endl;

    cout << ob << endl;
    cout << ob2 << endl;
    cout << ob3 << endl;

    Anket ob4 = ob.merge(ob2);

    cout << ob4 << endl;

    Anket ob5(5),ob6(6);

    ob4 += 3;//indexle islem yapilir
    cout << ob3 << endl;

    ob6.addVote(2); ob6.addVote(5);
    ob5 = ob3 + ob6;

    cout << ob5 << endl;



}


