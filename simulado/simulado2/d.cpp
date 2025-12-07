#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int oo = 1e9;

int bfs(int i, int j, int n, int m, vector<vector<char>> &matrix, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, oo));

    q.push({i, j});
    visited[i][j] = true;
    dist[i][j] = 0;

    while (not q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Se chegou no destino, retorna a distância
        if (x == n && y == m) {
            return dist[x][y];
        }

        // Explora os 4 vizinhos
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Verifica se está dentro dos limites
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                // Verifica se é um corredor livre e ainda não foi visitado
                if (matrix[nx][ny] == '.' && !visited[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return oo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;

    cin >> n >> m >> t;

    vector<vector<char>> matrix(n + 1, vector<char>(m + 1));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }

    int dist = bfs(1, 1, n, m, matrix, visited);

    if (dist == oo) {
        cout << "IMPOSSIVEL\n";
    } else if (dist <= t) {
        cout << "POSSIVEL\n";
    } else {
        cout << "NEM A PAU JUVENAL\n";
    }

    return 0;
}