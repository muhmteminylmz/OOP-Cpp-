#include <iostream>
#include <climits>

#define max_dugum_ayisi 10

using namespace std;

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < max_dugum_ayisi; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < max_dugum_ayisi; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[max_dugum_ayisi][max_dugum_ayisi], int src, int shortestPaths[]) {
    int dist[max_dugum_ayisi];
    bool sptSet[max_dugum_ayisi];

    for (int i = 0; i < max_dugum_ayisi; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        shortestPaths[i] = -1; // En kısa yol patikasını saklamak için -1 değeri atanır
    }

    dist[src] = 0;

    for (int count = 0; count < max_dugum_ayisi - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < max_dugum_ayisi; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                shortestPaths[v] = u; // En kısa yol patikasını güncelle
            }
        }
    }

    // En kısa yol patikasını yazdır
    cout << "Shortest Paths:" << endl;
    for (int i = 0; i < max_dugum_ayisi; i++) {
        int current = i;
        cout << "Path for vertex " << i << ": " << i;
        while (shortestPaths[current] != -1) {
            cout << " <- " << shortestPaths[current];
            current = shortestPaths[current];
        }
        cout << endl;
    }

    // En kısa yol uzunluklarını yazdır
    printSolution(dist);
}

int main() {
    int graph[max_dugum_ayisi][max_dugum_ayisi] = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int shortestPaths[max_dugum_ayisi];

    dijkstra(graph, 0, shortestPaths);

    return 0;
}
