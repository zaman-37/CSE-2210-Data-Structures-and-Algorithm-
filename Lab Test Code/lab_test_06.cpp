/*
Q: bfs implementation. and using bfs calculate level of all the node.
    
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
const int MX = 1e5;
int vis[MX], lev[MX];

void bfs (int v) { // bfs function...
    queue<int> q;
    q.push(v);
    vis[v] = 1;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (auto ch: adj[a]) {
            if (!vis[ch]) {
                q.push(ch);
                vis[ch] = 1;
                lev[ch] = lev[a] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.assign(n+5, vector<int>());
    for (int i=0; i<=n; i++) {
        vis[i] = lev[i] = 0;
    }

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1); // call bfs 

    for (int i=1; i<=n; i++) {
        cout << "Level of " << i  << " is " << lev[i] << endl;
    }
    

    return 0;
}

