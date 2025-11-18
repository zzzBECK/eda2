#include <iostream>

using namespace std;

constexpr int MAXN = {200'010};

vector<int> adj[MAXN];

void leaves(int u, int p, vector<long long> &xs) {
    int sum = 0;

    for (auto v : adj[u]) {
        if (v != p)
            leaves(v, u, xs);

        sum += xs[v];
    }

    xs[u] = sum ? sum : 1;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int u = 1; u <= n; ++u) {
            adj[u].clear();
        }

        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;

            adj[u].emplace_back(v);
            adj[u].emplace_back(u);
        }

        int q;
        cin >> q;

        while (q--) {
            int x, y;
            cin >> x >> y;

            vector<long long> xs(n + 1, 0);
            leaves(1, -1, xs);

            auto ans = leaves[x] * leaves[y];

            cout << ans << '/n';
        }
    }

    return 0;
}