#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, count = 0, row, column;

    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char value;
            cin >> value;
            if (value == '.') {
                count++;
            }
        }
    }

    cout << (count >= 1 ? "Sim" : "Nao") << '\n';

    return 0;
}