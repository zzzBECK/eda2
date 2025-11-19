#include <iostream>
#include <vector>

using namespace std;

int height_from(int root, const vector<vector<int>> &children) {
    if (children[root].empty()) {
        return 1;
    }

    int best = 0;
    for (int v : children[root]) {
        int hChild = height_from(v, children);
        if (hChild > best) {
            best = hChild;
        }
    }

    return 1 + best;
}

int main() {
    ios::sync_with_stdio(false);

    int quantity;
    cin >> quantity;

    vector<vector<int>> children(quantity + 1);
    vector<int> parent(quantity + 1);

    for (int i = 1; i <= quantity; i++) {
        int value;
        cin >> value;

        if (value != -1) {
            children[value].push_back(i);
        } else {
            parent.push_back(i);
        }
    }

    int best = -99999;

    for (auto root : parent) {
        auto height = height_from(root, children);
        if (height > best) {
            best = height;
        }
    }

    cout << best << '\n';

    return 0;
}