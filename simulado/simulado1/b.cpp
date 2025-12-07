#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int oo {999999};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, qtd;

    cin >> size >> qtd;

    vector<vector<int>> adj(size + 1);

    while (qtd--){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= size; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    for (int u = 1; u <= size; u++) {
        for (int v = 1; v <= size; v++) {
            auto it = lower_bound(adj[u].begin(), adj[u].end(), v);
            if (it == adj[u].end() || *it != v) {
                if (u != v && u < v){
                    cout << u << " " << v << '\n';
                }
            }
        }
    }

    return 0;
}