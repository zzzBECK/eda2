#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, wanted;
    bool is_possible = false;
    cin >> n >> wanted;

    int next;

    for (int i = 1; i <= n - 1; i++) {
        int value;
        cin >> value;

        if (i == 1) {
            next = 1 + value;
            if (1 == wanted) {
                cout << "YES\n";
                return 0;
            }
        } else if (i == next) {
            if (next == wanted) {
                cout << "YES\n";
                return 0;
            }
            next = i + value;
        }
    }

    if (next == wanted) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}