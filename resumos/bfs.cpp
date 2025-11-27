#include <bitset>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX{200010}, oo{99999999};

bitset<MAX> visited;
vector<int> adj[MAX];

void bfs(int u) {
    queue<int> q;

    q.push(u);
    visited[u] = true;

    while (not q.empty()){
        int next = q.front(); q.pop();

        cout << "visited: " << next << '\n';

        for (int aresta : adj[next]) {
            if (not visited[aresta]){

                q.push(aresta);
                visited[aresta] = true;
            }
        }
    }
    
}

vector<int> bfs_dist(int s, int N) {
    vector<int> dist(N + 1, oo);  // distâncias inicializadas como infinito
    queue<int> q;

    dist[s] = 0;  // distância da origem para ela mesma é 0
    q.push(s);    // começa pela origem

    while (not q.empty()) {
        auto u = q.front();
        q.pop();

        // processa vértice u
        for (auto v : adj[u]) {
            if (dist[v] == oo) {        // ainda não visitado
                dist[v] = dist[u] + 1;  // distância é +1 do pai
                q.push(v);
            }
        }
    }

    return dist;  // retorna vetor com todas as distâncias
}

int main() {
    ios::sync_with_stdio(false);

    adj[1] = {2, 3};
    adj[2] = {1, 4, 5};
    adj[3] = {1, 6};
    adj[4] = {2};
    adj[5] = {2, 6, 8, 9};
    adj[6] = {3, 5, 7, 10};
    adj[7] = {6};
    adj[8] = {5, 11};
    adj[9] = {5, 10};
    adj[10] = {6, 9};
    adj[11] = {8, 12, 13};
    adj[12] = {11};
    adj[13] = {11};

    bfs(1);

    for (auto value : bfs_dist(1, 13)){
        if (value != oo){
            cout << value << " ";
        }
    }
    cout << '\n';

    return 0;
}