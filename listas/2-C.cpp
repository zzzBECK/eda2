#include <iostream>

using namespace std;

int calculate(int n, int m) {
    return (n * m) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool isPair = n % 2 == 0;

    if (isPair) {
        if (n == 2) {
            cout << 10 << '\n';
        } else {
            cout << n - 2 << '\n';
        }
    }

    if (!isPair) {
        if (n == 1) {
            cout << 3 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }

    return 0;
}