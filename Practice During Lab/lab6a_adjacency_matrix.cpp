#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // number of vertices
    // cout << "Enter the number of vertices: ";
    cin >> n;

    // Create an n x n adjacency matrix and initialize to 0
    //  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    int adjMatrix[n+1][n+1] = {0};

    int edges;
    // cout << "Enter the number of edges: ";
    cin >> edges;

    // cout << "Enter the edges (start end):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        // For undirected graph, set both (u,v) and (v,u) to 1
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Remove this line if directed graph
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



/*

7 8
1 3
3 4
3 2
3 5
3 6
5 7
7 6
6 2

*/
