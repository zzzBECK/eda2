#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, qtd;
    cin >> n >> qtd;

    vector<vector<int>> adj(n + 1);
    vector<int> suspects;

    for (int i = 1; i <= qtd; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) {
            suspects.push_back(i);
        } else {
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int find = -1;

    for (int suspect : suspects) {
        find = suspect;
        for (int i = 1; i <= n; i++) {
            if (i == suspect)
                continue;

            auto it = lower_bound(adj[i].begin(), adj[i].end(), suspect);
            if (it == adj[i].end() || *it != suspect) {
                find = -1;
                break;
            }
        }
        if (find != -1) {
            break;
        }
    }

    cout << find << '\n';

    return 0;
}