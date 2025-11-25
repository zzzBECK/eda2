#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_elemntos, qtd_consultas;
    cin >> qtd_elemntos >> qtd_consultas;

    vector<vector<int>> adj(qtd_elemntos + 1);

    for (int i = 1; i <= qtd_elemntos; i++) {
        int input;
        cin >> input;
        if (adj[input].empty()) {
            adj[input].emplace_back(-1);
        }
        adj[input].emplace_back(i);
    }

    for (int i = 1; i <= qtd_consultas; i++) {
        int pos, value;
        cin >> pos >> value;

        if (pos < adj[value].size()) {
            cout << adj[value][pos] << '\n';
        } else {
            cout << 0 << '\n';  // ou -1, dependendo do que você quer retornar
        }
    }

    return 0;
}