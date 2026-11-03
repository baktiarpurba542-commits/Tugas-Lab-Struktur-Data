#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

int main() {
    const int V = 6;
    vector<vector<int>> adj(V, vector<int>(V, 0));

    int n;
    cout << "Jumlah edge: ";
    cin >> n;

    cout << "Masukkan edge (contoh: A B)" << endl;
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        int u = toupper(a) - 'A';
        int v = toupper(b) - 'A';

        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        } else {
            cout << "Vertex tidak valid (A-F)" << endl;
            i--;
        }
    }

    char s;
    cout << "Vertex awal: ";
    cin >> s;
    int start = toupper(s) - 'A';

    if (start < 0 || start >= V) {
        cout << "Vertex awal tidak valid" << endl;
        return 0;
    }

    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "Urutan BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << char('A' + u) << " ";

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;

    return 0;
}