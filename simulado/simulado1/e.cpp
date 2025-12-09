#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int bfs(int m, int n, int start_i, int start_j, vector<vector<char>> &adj) {
    vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));
    queue<tuple<int, int, int>> q;  // {i, j, distancia}

    q.push({start_i, start_j, 0});
    visited[start_i][start_j] = true;

    // Direções: cima, baixo, esquerda, direita
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [i, j, dist] = q.front();
        q.pop();

        // Verifica se é uma saída válida (borda e não é a posição inicial)
        if ((i == 1 || i == m || j == 1 || j == n) && !(i == start_i && j == start_j)) {
            return dist;
        }

        // Explora os 4 vizinhos
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            // Verifica limites
            if (ni < 1 || ni > m || nj < 1 || nj > n)
                continue;

            // Verifica se já foi visitado
            if (visited[ni][nj])
                continue;

            // Verifica se é parede
            if (adj[ni][nj] == '+')
                continue;

            visited[ni][nj] = true;
            q.push({ni, nj, dist + 1});
        }
    }

    return -1;  // Não encontrou saída
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<char>> adj(m + 1, vector<char>(n + 1));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    cout << bfs(m, n, x + 1, y + 1, adj) << '\n';

    return 0;
}