#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd, YES = 0;

    cin >> qtd;
    vector<int> list;

    for (int i = 1; i <= qtd; i++) {
        int input;
        cin >> input;
        list.push_back(input);
    }

    for (int A = 1; A <= qtd; A++) {
        auto B = list[A];
        auto C = list[B];

        if (list[C] == A) {
            YES = 1;
            break;
        }
    }

    cout << (YES ? "YES" : "NO") << '\n';

    return 0;
}