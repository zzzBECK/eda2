#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj(26, vector<int>());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int letra = s[i] - 'a';
        adj[letra].push_back(i);
    }

    int q;
    cin >> q;

    while (q--) {
        int operation, REPLACE = 1, CALCULATE = 2;
        cin >> operation;

        if (operation == CALCULATE) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            int sum = 0;

            // Para cada letra, verificar se ela aparece no intervalo [l, r]
            for (int letra = 0; letra < 26; letra++) {
                // Busca binária: encontrar se existe alguma posição entre l e r
                auto it = lower_bound(adj[letra].begin(), adj[letra].end(), l);

                if (it != adj[letra].end() && *it <= r) {
                    sum++;
                }
            }

            cout << sum << '\n';
        }

        if (operation == REPLACE) {
            int pos;
            char new_char;
            cin >> pos >> new_char;
            pos--;

            char old_char = s[pos];

            if (old_char != new_char) {
                // Remover posição da letra antiga
                int old_letter = old_char - 'a';
                auto it = lower_bound(adj[old_letter].begin(), adj[old_letter].end(), pos);
                adj[old_letter].erase(it);

                // Adicionar posição na letra nova
                int new_letter = new_char - 'a';
                auto insert_pos = lower_bound(adj[new_letter].begin(), adj[new_letter].end(), pos);
                adj[new_letter].insert(insert_pos, pos);

                // Atualizar string
                s[pos] = new_char;
            }
        }
    }

    return 0;
}