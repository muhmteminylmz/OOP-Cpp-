#include <iostream>
#include <algorithm>

using namespace std;
#define max_dugum_ayisi 10

class Dugum{
public:
    int dugum_count,edge_matris[max_dugum_ayisi][max_dugum_ayisi],*dugum_derece,edge_agirlik_matrisi[max_dugum_ayisi][max_dugum_ayisi];
    Dugum(int dugum_sayisi) : dugum_count(dugum_sayisi){
        dugum_derece = new int[dugum_sayisi];
        for(int i = 0; i < 10; i++){
            dugum_derece[i] = 0;
            for(int j = 0; j < 10; j++){
                edge_matris[i][j] = 0;
                edge_agirlik_matrisi[i][j] = 0;
            }
        }
    }

    void dugum_doldur(int a, int b,int c,int d) {
        edge_matris[a][b] = c;
        edge_matris[b][a] = c;
        edge_agirlik_matrisi[a][b] =d;
        edge_agirlik_matrisi[b][a] =d;

    }

    void matris_doldur(){
        int x,y;
        cout << "Sirasiyla dugumlerin birbirine bagli olan kenar uzunlugunu ardindan kenar sayisini giriniz." << endl;
        for(int i = 0; i < dugum_count; i++){
            for(int j = 0; j < dugum_count; j++){
                cout << i << " " << j << ": ";
                cin >> x;
                cout << "\t";
                cin >> y;
                dugum_doldur(i,j,x,y);
                cout << endl;
            }
            dugum_derece[i] = y;
        }
    }

    int* tek_dereceli_dugumler(int array[]){
        for(int i = 0; i < dugum_count; i++){
            if(dugum_derece[i]%2 == 1){
                array[i] = dugum_derece[i];
            }
        }

    }




    bool is_neightbor(int a,int b){
        if(edge_agirlik_matrisi[a][b] != 0){return true;}else {return false;}
    }


    void iki_cift_arasindaki_mesaje(){


    }





};



int main(){

}