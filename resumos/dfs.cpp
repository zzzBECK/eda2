#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX{200010};

bitset<MAX> visited;
vector<int> adj[MAX];

void dfs(int u) {
    if (visited[u])
        return;

    // processa/visita u
    visited[u] = true;

    cout << "visited: " << u << '\n';

    for (auto v : adj[u])
        dfs(v);
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

    dfs(1);

    return 0;
}