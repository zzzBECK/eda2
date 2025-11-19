#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj_list(n + 1);
    vector<int> output(q + 1);

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        adj_list[input].push_back(i);
    }

    for (int i = 1; i <= q; i++) {
        int input, best = 0;
        cin >> input;

        best = adj_list[input].front();
        adj_list[input].erase(adj_list[input].begin());
        adj_list[input].push_back(1);

        adj_list[1].erase(adj_list[1].begin());
        adj_list[1].insert(adj_list[1].begin(), best);

        output.push_back(best);
    }

    for (auto value : output) {
        cout << value << ' ';
    }

    return 0;
}