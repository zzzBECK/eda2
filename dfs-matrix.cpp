#include <iostream>
#include <vector>

using namespace std;

int dfs(int i, int j, int h, int w, vector<vector<char>> &matrix, vector<vector<bool>> &visited) {
    if (i < 1 || i > h || j < 1 || j > w) {
        return 0;
    }

    if (visited[i][j] || matrix[i][j] != '.') {
        return 0;
    }

    visited[i][j] = true;

    int sum = 1;

    // cima
    sum += dfs(i - 1, j, h, w, matrix, visited);
    // baixo
    sum += dfs(i + 1, j, h, w, matrix, visited);
    // direita
    sum += dfs(i, j + 1, h, w, matrix, visited);
    // esquerda
    sum += dfs(i, j - 1, h, w, matrix, visited);

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, count = 0, row, column;

    cin >> h >> w;

    vector<vector<char>> matrix(h + 1, vector<char>(w + 1));
    vector<vector<bool>> visited(h + 1, vector<bool>(w + 1, false));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == '.') {
                count++;
                row = i;
                column = j;
            }
        }
    }

    int sum = dfs(row, column, h, w, matrix, visited);

    cout << (sum == count ? "Sim" : "Não") << '\n';

    return 0;
}