#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define max_dugum_ayisi 6
#define INF INT_MAX

class Dugum{
public:
    vector<vector<int>> edge_matris;
    vector<vector<int>> edge_agirlik_matrisi;
    vector<int> tek_dereceliler;
    int dugum_count,*dist;
    //int *dugum_derece;
    vector<int> dugum_derece;
    Dugum(int dugum_sayisi) : dugum_count(dugum_sayisi){
        //dugum_derece = new int[dugum_count];
        dist = new int[max_dugum_ayisi];
        edge_matris = vector<vector<int>>(dugum_count,vector<int>(dugum_count,0));
        //edge_agirlik_matrisi = vector<vector<int>>(dugum_count,vector<int>(dugum_count,0));
        tek_dereceliler = vector<int>(dugum_count);
        for(int i=0; i < dugum_count; i++){
            dugum_derece[i] = 0;
            dist[i] = 0;
            for(int j = 0; j < dugum_count; j++){
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
        cout << "Sirasiyla dugumun diger dugumle baglantili kenar sayisini ardindan uzunlugunu giriniz:" << endl;
        for(int i = 0; i < dugum_count; i++){
            for(int j = 0; j < dugum_count; j++){
                cout << i << " V " << j << ": "<< endl;
                cin >> x;
                cout << "\t";
                if(x == 0)
                    y=0;
                else{ cin >> y;}
                dugum_doldur(i,j,x,y);
                cout << endl;
                dugum_derece[i] += y;
            }
        }
    }

    void tek_dereceli_dugumler(){
        for(int i = 0; i < dugum_count; i++){
            if(dugum_derece[i]%2 == 1){
                tek_dereceliler.push_back(i);
            }
        }
    }




    /*bool is_neightbor(int a,int b){
        if(edge_agirlik_matrisi[a][b] != 0){return true;}else {return false;}
    }*/

/////////////////////////////////////////////////////////////////////////
    int minDistance(int dist[], bool sptSet[])
    {

        // Initialize min value
        int min = INT_MAX, min_index;

        for (int v = 0; v < max_dugum_ayisi; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }

// A utility function to print the constructed distance
// array
    void printSolution(int dist[])
    {
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < max_dugum_ayisi; i++)
            cout << i << " \t\t\t\t" << dist[i] << endl;
    }

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
    void dijkstra(vector<vector<int>> graph, int src,vector<int> kisa_yol_patikasi)
    {

        // The output array. dist[i] will hold the
        // shortest
        // distance from src to i

        bool sptSet[max_dugum_ayisi]; // sptSet[i] will be true if vertex i is
        // included in shortest
        // path tree or shortest distance from src to i is
        // finalized

        // Initialize all distances as INFINITE and stpSet[] as
        // false
        for (int i = 0; i < max_dugum_ayisi; i++)
            dist[i] = INT_MAX, sptSet[i] = false,kisa_yol_patikasi[i]=-1;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < max_dugum_ayisi - 1; count++) {
            // Pick the minimum distance vertex from the set of
            // vertices not yet processed. u is always equal to
            // src in the first iteration.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the
            // picked vertex.
            for (int v = 0; v < max_dugum_ayisi; v++)

                // Update dist[v] only if is not in sptSet,
                // there is an edge from u to v, and total
                // weight of path from src to v through u is
                // smaller than current value of dist[v]
                if (!sptSet[v] && graph[u][v]
                    && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                    kisa_yol_patikasi[v]=u;
        }
        }
    }

    /*void kisa_yol_patikasi(){
        int kisa_yol_patikasi[max_dugum_ayisi][max_dugum_ayisi];
        int temp[INF];
        for(int i = 0; i < max_dugum_ayisi; i++){
            dijkstra(edge_agirlik_matrisi,i,temp);
            for(int j = 0; j < max_dugum_ayisi; j++){
                kisa_yol_patikasi[i][j] = temp[j];
            }
        }
    }*/

////////////////////////////////////
    void teklileri_ciftlestir() {
        /*int ciftlestirme[tek_dereceliler.size() - 1][tek_dereceliler.size() / 2][2];
        for (int i = 0; i < tek_dereceliler.size() - 1; i++) {
            for (int j = 0; j < tek_dereceliler.size(); j += 2) {
                ciftlestirme[i][j][0] = tek_dereceliler[j];
                ciftlestirme[i][j][1] = tek_dereceliler[j + 1];
            }
        }*/

        int ciftlestmis_uzaklik[tek_dereceliler.size() - 1][tek_dereceliler.size() / 2];
        vector<int> temp;
        for (int i = 0; i < max_dugum_ayisi; i++) {
            dijkstra(edge_agirlik_matrisi, i, temp);
            for (int j = 0; j < max_dugum_ayisi; j++) {
                ciftlestmis_uzaklik[i][j] = dist[j];
            }
            //kenar ekle
            if (i < temp.size() - 1)
                edge_matris[temp[i]][temp[i + 1]] += 1;
            dugum_derece[i] += 1;
            dugum_derece[i + 1] += 1;
        }
    }
        int sum_of_dugum_agirligi(){
            int result=0;
            for (int i = 0; i < dugum_count;i++){
                for(int j = 0; j < dugum_count;j++){
                    result += (edge_matris[i][j] * edge_agirlik_matrisi[i][j]);
                }
            }
            return result;  }


    bool is_euler(){
        if(tek_dereceliler.size() >= 3)return false;
        else return true;
    }



};



int main() {
    // Örnek bir graf oluştur
    Dugum graf(6); // Örneğin 5 düğüm içeren bir graf oluşturuluyor.

    // Matrisi doldur
    graf.edge_matris={{0,1,1,0,0,0},{1,0,1,1,0,0},{1,1,0,0,1,0},{0,1,0,0,1,1},{0,0,1,1,0,1},{0,0,0,1,1,0}};
    graf.edge_agirlik_matrisi={{0,1,2,0,0,0},{1,0,5,3,0,0},{2,5,0,0,4,0},{0,3,0,0,6,1},{0,0,4,6,0,1},{0,0,0,1,1,0}};
    graf.dugum_derece = {2, 3, 3, 3, 3, 2};

    if(graf.is_euler()) {
        cout << "Cinli Postaci Turu Agirligi: " << graf.sum_of_dugum_agirligi() << endl;
    }
    else {
        //graf.tek_dereceli_dugumler();
        //graf.teklileri_ciftlestir();
        cout << "Cinli Postaci Turu Agirligi: " << graf.sum_of_dugum_agirligi() << endl;
    }

    return 0;
}