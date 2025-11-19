#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> colors(n + 1);
    vector<int> output(q + 1);

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        colors[i] = input;
    }

    for (auto value : colors) {
        cout << value << " ";
    }

    cout << '\n';

    for (int i = 1; i <= q; i++) {
        int input;
        cin >> input;

        auto best = find(colors.begin() + 1, colors.end(), input);
        auto best_idx = distance(colors.begin(), best);

        int value = colors[best_idx];

        colors.erase(colors.begin() + best_idx);
        colors.insert(colors.begin() + 1, value);

        output[i] = best_idx;
    }

    for (auto value : output) {
        if (value != 0)
            cout << value << " ";
    }

    cout << '\n';

    return 0;
}