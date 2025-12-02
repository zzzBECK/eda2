#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int oo{999999};

vector<vector<int>> adj;
bitset<oo> visited;

void dfs(int node){
    if (visited[node]){
        return;
    }

    visited[node] = true;
    
    for (int child : adj[node]){
        if (child != node){
            dfs(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, qtd;
    
    cin >> size >> qtd;

    adj.resize(size + 1);

    for (int i = 1; i <= qtd; i++){
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int count = 0;

    for (int i = 1; i <= size; i++) {
        if (!visited[i]){
            count++;
            dfs(i);
        }
    }

    cout << count << '\n';

    return 0;
}