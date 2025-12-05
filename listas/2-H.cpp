#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<bool>> &visited, int n, int m) {
    if (i < 1 || i > n || j < 1 || j > m) {
        return 0;
    }

    if (visited[i][j] || matrix[i][j] == 0) {
        return 0;
    }

    visited[i][j] = true;

    int volume = matrix[i][j];

    volume += dfs(i - 1, j, matrix, visited, n, m);  // cima
    volume += dfs(i + 1, j, matrix, visited, n, m);  // baixo
    volume += dfs(i, j - 1, matrix, visited, n, m);  // esquerda
    volume += dfs(i, j + 1, matrix, visited, n, m);  // direita

    return volume;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests_qtd;
    cin >> tests_qtd;

    while (tests_qtd--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
            }
        }

        int best = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i][j] != 0) {
                    int sum = dfs(i, j, matrix, visited, n, m);
                    if (sum > best) {
                        best = sum;
                    }
                }
            }
        }

        cout << best << '\n';
    }

    return 0;
}