#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int quantity, sum = 0;
    cin >> quantity;

    for (int i = 1; i <= quantity; i++) {
        int value;
        cin >> value;
        if (value != -1) {
            sum++;
        }
    }

    cout << sum << '\n';

    return 0;
}