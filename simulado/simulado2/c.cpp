#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int NONE = 0, PRETA = 1, VERMELHA = 2;

bool bfs(int s, vector<vector<int>> &adj, vector<int> &color) {
    queue<int> q;
    q.push(s);

    while (not q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (color[v] == NONE) {
                color[v] = 3 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> color(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int s, t;
    string c;

    cin >> s >> c >> t;

    color[s] = c == "PRETA" ? PRETA : VERMELHA;

    bfs(s, adj, color);

    cout << (color[t] == PRETA ? "PRETA" : "VERMELHA");

    return 0;
}