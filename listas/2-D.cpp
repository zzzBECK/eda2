#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        bool corner1 = (x1 == 1 && y1 == 1) || (x1 == 1 && y1 == m) || (x1 == n && y1 == 1) ||
                       (x1 == n && y1 == m);
                       
        bool corner2 = (x2 == 1 && y2 == 1) || (x2 == 1 && y2 == m) || (x2 == n && y2 == 1) ||
                       (x2 == n && y2 == m);

        bool edge1 = (x1 == 1 || x1 == n || y1 == 1 || y1 == m);
        bool edge2 = (x2 == 1 || x2 == n || y2 == 1 || y2 == m);

        if (corner1 || corner2) {
            cout << 2 << '\n';
        } else if (edge1 || edge2) {
            cout << 3 << '\n';
        } else {
            cout << 4 << '\n';
        }
    }

    return 0;
}