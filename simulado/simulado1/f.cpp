#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Função para fazer ordenação topológica
// Retorna a ordem topológica ou vetor vazio se houver ciclo
vector<int> topologicalSort(int n, vector<vector<int>> &adj, vector<int> &inDegree) {
    vector<int> result;
    queue<int> q;
    vector<int> inDegreeCopy = inDegree;

    // Adiciona todos os nós com grau de entrada 0
    for (int i = 1; i <= n; i++) {
        if (inDegreeCopy[i] == 0) {
            q.push(i);
        }
    }

    // Processa os nós
    while (!q.empty()) {
        // Cria um vetor temporário para manter a ordem crescente
        vector<int> current;
        while (!q.empty()) {
            current.push_back(q.front());
            q.pop();
        }

        // Ordena para sempre escolher o menor número disponível
        sort(current.begin(), current.end());

        // Processa o menor número
        int node = current[0];
        result.push_back(node);

        // Coloca os outros de volta na fila
        for (int i = 1; i < current.size(); i++) {
            q.push(current[i]);
        }

        // Remove as arestas do nó processado
        for (int neighbor : adj[node]) {
            inDegreeCopy[neighbor]--;
            if (inDegreeCopy[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Se não processamos todos os nós, há um ciclo
    if (result.size() != n) {
        return vector<int>();
    }

    return result;
}

int main() {
    int K;
    cin >> K;

    // Grafos para restrições de linha e coluna
    vector<vector<int>> rowAdj(K + 1);
    vector<vector<int>> colAdj(K + 1);
    vector<int> rowInDegree(K + 1, 0);
    vector<int> colInDegree(K + 1, 0);

    // Lê restrições de latitude (linhas)
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int acima, abaixo;
        cin >> acima >> abaixo;
        rowAdj[acima].push_back(abaixo);
        rowInDegree[abaixo]++;
    }

    // Lê restrições de longitude (colunas)
    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        int esquerda, direita;
        cin >> esquerda >> direita;
        colAdj[esquerda].push_back(direita);
        colInDegree[direita]++;
    }

    // Faz ordenação topológica para linhas e colunas
    vector<int> rowOrder = topologicalSort(K, rowAdj, rowInDegree);
    vector<int> colOrder = topologicalSort(K, colAdj, colInDegree);

    // Verifica se há ciclo
    if (rowOrder.empty() || colOrder.empty()) {
        cout << "IMPOSSIVEL" << endl;
        return 0;
    }

    // Cria mapeamento de ilha para posição
    vector<int> islandRow(K + 1);
    vector<int> islandCol(K + 1);

    for (int i = 0; i < K; i++) {
        islandRow[rowOrder[i]] = i;
        islandCol[colOrder[i]] = i;
    }

    // Constrói a grade
    vector<vector<int>> grid(K, vector<int>(K, 0));

    for (int island = 1; island <= K; island++) {
        int row = islandRow[island];
        int col = islandCol[island];
        grid[row][col] = island;
    }

    // Imprime a grade
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (j > 0)
                cout << " ";
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}