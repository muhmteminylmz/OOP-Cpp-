#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

#define INF INT_MAX

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V);
    void addEdge(int u, int v, int w);
    void findShortestClosedPath();
    void eulerianCircuit(int start);
    void printGraph();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V, vector<int>(V, INF));
}

void Graph::addEdge(int u, int v, int w) {
    adj[u][v] = adj[v][u] = w;
}

void Graph::findShortestClosedPath() {
    int sumOfEdgeWeights = 0;

    // Step 1: Check if the graph is Eulerian
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adj[i][j] != INF)
                sumOfEdgeWeights += adj[i][j];

    // Step 2: If Eulerian, print sum of all edge weights
    if (sumOfEdgeWeights % 2 == 0) {
        cout << "Sum of all edge weights: " << sumOfEdgeWeights << endl;
        return;
    }

    // Step 3: Find vertices with odd degree
    vector<int> oddDegreeVertices;
    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++)
            if (adj[i][j] != INF)
                degree++;
        if (degree % 2 != 0)
            oddDegreeVertices.push_back(i);
    }

    // Step 4: Find the shortest path connecting odd degree vertices for each pairing
    int minWeight = INF;
    vector<int> minPath;

    do {
        int weight = 0;
        for (int i = 0; i < oddDegreeVertices.size() - 1; i++)
            weight += adj[oddDegreeVertices[i]][oddDegreeVertices[i + 1]];

        if (weight < minWeight) {
            minWeight = weight;
            minPath = oddDegreeVertices;
        }

    } while (next_permutation(oddDegreeVertices.begin(), oddDegreeVertices.end()));

    // Step 5: Modify the graph by adding edges found in step 4
    for (int i = 0; i < minPath.size() - 1; i++)
        addEdge(minPath[i], minPath[i + 1], adj[minPath[i]][minPath[i + 1]]);

    // Step 6: Weight of Chinese Postman Tour
    int chinesePostmanWeight = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adj[i][j] != INF)
                chinesePostmanWeight += adj[i][j];

    // Step 7: Print Chinese Postman Tour
    cout << "Weight of Chinese Postman Tour: " << chinesePostmanWeight << endl;

    // Step 8: Print Euler Circuit of the modified graph
    eulerianCircuit(0);
}

void Graph::eulerianCircuit(int start) {
    for (int v = 0; v < V; v++) {
        if (adj[start][v] != INF) {
            cout << start << " -> " << v << " ";
            adj[start][v] = adj[v][start] = INF; // Remove the edge to avoid revisiting
            eulerianCircuit(v);
        }
    }
}

void Graph::printGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] != INF) {
                cout << i << " -> " << j << " : " << adj[i][j] << endl;
            }
        }
    }
}

int main() {
    int V = 6; // Number of vertices
    Graph g(V);

    // Add edges and weights to the graph
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 6);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    cout << "Original Graph:" << endl;
    g.printGraph();

    cout << "\nFinding Shortest Closed Path:" << endl;
    g.findShortestClosedPath();

    return 0;
}
