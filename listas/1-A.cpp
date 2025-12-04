#include <iostream>

using namespace std;

long long calculate_sum(long long value) {
    if (value == 1) {
        return value;
    }

    return value + calculate_sum((long long) value / 2);
}

int main() {
    ios::sync_with_stdio(false);

    int quantity;
    cin >> quantity;

    for (int i = 1; i <= quantity; i++) {
        long long number;
        cin >> number;
        cout << calculate_sum(number) << "\n";
    }

    return 0;
}