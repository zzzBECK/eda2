#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--){
        int islands, removed_bridges, bridges;
        cin >> islands >> removed_bridges;
        bridges = (islands * (islands - 1))/ 2;

        if (removed_bridges >= islands - 1) {
            cout << 1 << '\n';
        } else if (bridges - removed_bridges >= islands - 1) {
            cout << islands << '\n';
        } else {
            cout << bridges - removed_bridges + 1 << '\n';
        }
    }

    return 0;
}