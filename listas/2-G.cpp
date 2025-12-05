#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests_qtd;
    cin >> tests_qtd;

    while (tests_qtd--) {
        int n;
        cin >> n;
        vector<long long> list(n + 1);
        vector<long long> sum_list(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> list[i];
        }

        for (int i = n; i >= 1; i--) {
            int next;
            next = i + list[i];

            if (next > n) {
                sum_list[i] = list[i];
            } else {
                sum_list[i] = list[i] + sum_list[next];
            }
        }

        long long best = *max_element(sum_list.begin() + 1, sum_list.begin() + n + 1);
        cout << best << '\n';
    }

    return 0;
}