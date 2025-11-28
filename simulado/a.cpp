#include <iostream>

using namespace std;

const int oo {999999};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, qtd;

    cin >> size >> qtd;

    int answer = (size * (size - 1) / 2) - qtd;

    cout << answer << '\n';

    return 0;
}