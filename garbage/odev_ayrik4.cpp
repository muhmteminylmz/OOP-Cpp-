#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define max_dugum_ayisi 6

class Dugum {
public:
    vector<vector<int>> edge_matris;
    vector<vector<int>> edge_agirlik_matrisi;
    vector<int> tek_dereceliler_index;
    vector<int> dugum_derece;
    vector<int> dist;
    int dugum_count;

    Dugum(int dugum_sayisi) : dugum_count(dugum_sayisi) {
        edge_matris = vector<vector<int>>(dugum_count, vector<int>(dugum_count, 0));
        dugum_derece = vector<int>(dugum_count);
        dist = vector<int>(dugum_count);
        edge_agirlik_matrisi = vector<vector<int>>(dugum_count, vector<int>(dugum_count, 0));
    }

    void dugum_doldur(int a, int b, int c, int d) {
        edge_matris[a][b] = c;
        edge_matris[b][a] = c;
        edge_agirlik_matrisi[a][b] = d;
        edge_agirlik_matrisi[b][a] = d;
    }

    void matris_doldur() {
        int x, y;
        cout << "Sirasiyla dugumun diger dugumle baglantili kenar sayisini ardindan uzunlugunu giriniz:" << endl;
        for (int i = 0; i < dugum_count; i++) {
            for (int j = 0; j < dugum_count; j++) {
                cout << i << " V " << j << ": " << endl;
                cin >> x;
                cout << "\t";
                if (x == 0)
                    y = 0;
                else {
                    cin >> y;
                }
                dugum_doldur(i, j, x, y);
                cout << endl;
                dugum_derece[i] += y;
            }
        }
    }

    void tek_dereceli_dugumler() {
        for (int i = 0; i < dugum_count; i++) {
            if (dugum_derece[i] % 2 == 1) {tek_dereceliler_index.push_back(i);}
        }
    }


    int minDistance(bool sptSet[]) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < dugum_count; v++)
            if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v], min_index = v;
            }
        return min_index;
    }

    void printSolution(vector<int> dist) {
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < dugum_count; i++)
            cout << i << " \t\t\t\t" << dist[i] << endl;
    }



    void dijkstra(vector<vector<int>> graph, int src, vector<int>& kisa_yol_patikasi) {
        bool sptSet[max_dugum_ayisi];

        for (int i = 0; i < dugum_count; i++)
            dist[i] = INT_MAX, sptSet[i] = false, kisa_yol_patikasi[i] = -1;

        dist[src] = 0;

        for (int count = 0; count < dugum_count - 1; count++) {
            int u = minDistance(sptSet);

            sptSet[u] = true;

            for (int v = 0; v < dugum_count; v++)
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                   // cout << "v: " << v << endl;
                    //cout << "dist[v]: " << dist[v] << endl;
                    //cout <<"graph: " << u << " " << v << " " << graph[u][v] <<endl;
                    kisa_yol_patikasi[v] = u;
                }
            cout << endl;
        }
        cout << endl;
        printSolution(dist);
        cout << endl;

    }

    void teklileri_ciftlestir() {
        int ciftlestmis_uzaklik[max_dugum_ayisi][max_dugum_ayisi];
        vector<int> temp(max_dugum_ayisi);
        for (int i = 0; i < tek_dereceliler_index.size(); i++) {
            dijkstra(edge_agirlik_matrisi, tek_dereceliler_index[i], temp);
            cout << endl;
            for (int j = 0; j < dugum_count; j++) {
                cout << "temp: " << temp[j] << "\t";
                ciftlestmis_uzaklik[i][j] = dist[j];
            }
            cout << endl;

            if (i < tek_dereceliler_index.size() - 1) {
                edge_matris[temp[i]][temp[i + 1]] += 1;
                dugum_derece[temp[i]] += 1;
                dugum_derece[temp[i + 1]] += 1;
           }
        }
    }

    int sum_of_dugum_agirligi() {
        int result = 0;
        for (int i = 0; i < dugum_count; i++) {
            for (int j = 0; j < dugum_count; j++) {
                result += (edge_matris[i][j] * edge_agirlik_matrisi[i][j]);
            }
        }
        return result/2;//2 kere sayiyor ayni kenarlari
    }

    bool is_euler(){
        if(tek_dereceliler_index.size() >= 3)return false;
        else return true;
    }


    void show_double_vector(vector<vector<int>> vector){
        for(int i=0;i<dugum_count;i++){
            for(int j=0; j< dugum_count;j++){
                cout <<vector[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void show_double_vector(int array[max_dugum_ayisi][max_dugum_ayisi]){
        for(int i=0;i<dugum_count;i++){
            for(int j=0; j< dugum_count;j++){
                cout <<array[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};



int main() {

    Dugum graf(6);

    graf.edge_matris={{0,1,1,0,0,0},{1,0,1,1,0,0},{1,1,0,0,1,0},{0,1,0,0,1,1},{0,0,1,1,0,1},{0,0,0,1,1,0}};
    graf.edge_agirlik_matrisi={{0,1,2,0,0,0},{1,0,5,3,0,0},{2,5,0,0,4,0},{0,3,0,0,6,1},{0,0,4,6,0,1},{0,0,0,1,1,0}};
    graf.dugum_derece = {2, 3, 3, 3, 3, 2};
    graf.tek_dereceli_dugumler();

    if(graf.is_euler()) {
        cout << "Cinli Postaci Turu Agirligi: " << graf.sum_of_dugum_agirligi() << endl;
        cout << "a";
    }
    else {
        //graf.matris_doldur();
        graf.show_double_vector(graf.edge_matris);
        graf.show_double_vector(graf.edge_agirlik_matrisi);
        graf.teklileri_ciftlestir();
        cout << endl;
        cout << "Cinli Postaci Turu Agirligi: " << graf.sum_of_dugum_agirligi() << endl;
    }

    return 0;
}



/*

 */