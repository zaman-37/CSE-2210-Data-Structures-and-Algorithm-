#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;
vector<vector<int>> adj;
int lev[MX], vis[MX], vis2[MX], depth[MX];  // Added `depth` array

void bfs(int v) {
    queue<int> q;
    q.push(v);
    lev[v] = 0;
    vis[v] = 1;  // Use `vis` for marking nodes as visited

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (auto u : adj[a]) {
            if (!vis[u]) {
                q.push(u);
                lev[u] = lev[a] + 1;
                vis[u] = 1;
            }
        }
    }
}

void dfs(int v, int d = 0) {  // Pass depth as a parameter
    vis2[v] = 1;
    depth[v] = d;  // Store depth of the current node
    for (auto ch : adj[v]) {
        if (!vis2[ch]) {
            dfs(ch, d + 1);  // Increment depth for child nodes
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 5, vector<int>());
    for (int i = 0; i < n + 5; i++) {
        lev[i] = 0;
        vis[i] = vis2[i] = depth[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << "Level of " << i << " (BFS): " << lev[i] << endl;
        cout << "Depth of " << i << " (DFS): " << depth[i] << endl;
    }

    return 0;
}


/*

5 4
1 2
1 3
3 4
2 5

*/