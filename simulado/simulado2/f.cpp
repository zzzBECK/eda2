#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, int> prefix_count;

    prefix_count[0] = 1;

    long long prefix_sum = 0;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];

        long long target = prefix_sum - 11;

        if (prefix_count.find(target) != prefix_count.end()) {
            count += prefix_count[target];
        }

        prefix_count[prefix_sum]++;
    }

    cout << count << "\n";

    return 0;
}
