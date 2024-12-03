// bfs and dfs implementation

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;
vector<vector<int>> adj;
int lev[MX], vis[MX], vis2[MX];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    lev[v] = 0;
    vis[v] = 1;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (auto u: adj[a]) {
            if (!vis[u]) {
                q.push(u); 
                lev[u] = lev[a] + 1;
                vis[u] = 1;
            }
        }
    }
}

void dfs (int v) {
    vis[v] = 1;
    for (auto ch: adj[v]) {
        if (!vis[ch]) {
            dfs(ch);
        }
    }
}

int main() {
    
    int n, m;
    cin >> n >> m;
    adj.assign(n+5, vector<int>());
    for (int i=0; i<n+5; i++) {
        lev[i] = 0;
        vis[i] = vis2[i] = 0;
    }

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    dfs(1);

    for (int i=1; i<=n; i++) {
        cout << "Level of " << i << " is:" << lev[i] << endl;
    }

    return 0;
} 
