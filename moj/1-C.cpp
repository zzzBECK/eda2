#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> list(51);

    for (int i = 1; i <= n; i++) {
        int color;
        cin >> color;

        if (list[color] == 0) {
            list[color] = i;
        }
    }

    for (int i = 1; i <= q; i++) {
        int color, color_idx;
        cin >> color;

        color_idx = list[color];

        cout << color_idx << ' ';

        for (auto &element : list) {
            if (element < color_idx) {
                element++;
            }
        }

        list[color] = 1;
    }

    cout << '\n';

    return 0;
}