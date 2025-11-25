#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 200010;

vector<vector<long long>> adj;
vector<long long> leafs;

void dfs(long long node, long long father) {
    bool isLeaf = adj[node].size() == 1 && adj[node][0] == father;

    if (isLeaf) {
        leafs[node] = 1;
    }

    for (auto value : adj[node]) {
        if (value != father) {
            dfs(value, node);
            leafs[node] += leafs[value];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        adj.clear();
        adj.resize(n + 1);
        leafs.clear();
        leafs.resize(n + 1);

        for (long long i = 1; i <= n - 1; i++) {
            long long u, v;
            cin >> u >> v;

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        dfs(1, -1);

        long long q;
        cin >> q;

        while (q--) {
            long long x, y;
            cin >> x >> y;

            cout << leafs[x] * leafs[y] << '\n';
        }
    }

    return 0;
}