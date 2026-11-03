#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cctype>
using namespace std;

const int V = 6;

class Graph {
private:
    vector<vector<int>> adj;

public:
    Graph() {
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(char a, char b, int w) {
        int u = a - 'A';
        int v = b - 'A';
        adj[u][v] = w;
        adj[v][u] = w;
    }

    void dijkstra(int src, vector<int>& dist, vector<int>& parent) {
        dist.assign(V, INT_MAX);
        parent.assign(V, -1);
        vector<bool> visited(V, false);
        dist[src] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1;
            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }
            if (u == -1 || dist[u] == INT_MAX) break;

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adj[u][v] != 0 && !visited[v]) {
                    int nd = dist[u] + adj[u][v];
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        parent[v] = u;
                    }
                }
            }
        }
    }

    void printRoute(int dest, const vector<int>& parent) {
        vector<int> path;
        for (int v = dest; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); i++) {
            cout << char('A' + path[i]);
            if (i + 1 < path.size()) cout << " -> ";
        }
    }

    void showFrom(int src) {
        vector<int> dist, parent;
        dijkstra(src, dist, parent);

        cout << "Rute terpendek dari " << char('A' + src) << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (i == src) continue;
            cout << char('A' + src) << " ke " << char('A' + i) << " : ";
            if (dist[i] == INT_MAX) {
                cout << "Tidak terjangkau" << endl;
            } else {
                printRoute(i, parent);
                cout << " (total " << dist[i] << " km)" << endl;
            }
        }
    }

    void recommend(int src, int dest) {
        vector<int> dist, parent;
        dijkstra(src, dist, parent);

        cout << "Rekomendasi rute: ";
        if (dist[dest] == INT_MAX) {
            cout << "Tidak terjangkau" << endl;
        } else {
            printRoute(dest, parent);
            cout << " (total " << dist[dest] << " km)" << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge('A', 'B', 4);
    g.addEdge('A', 'C', 2);
    g.addEdge('B', 'C', 1);
    g.addEdge('B', 'D', 5);
    g.addEdge('B', 'E', 3);
    g.addEdge('C', 'D', 8);
    g.addEdge('C', 'E', 6);
    g.addEdge('D', 'E', 2);
    g.addEdge('D', 'F', 4);
    g.addEdge('E', 'F', 3);

    g.showFrom(0);

    char a, b;
    cout << endl << "Lokasi asal (A-F): ";
    cin >> a;
    cout << "Lokasi tujuan (A-F): ";
    cin >> b;

    int s = toupper(a) - 'A';
    int d = toupper(b) - 'A';

    if (s < 0 || s >= V || d < 0 || d >= V) {
        cout << "Lokasi tidak valid" << endl;
        return 0;
    }

    g.recommend(s, d);
    return 0;
}