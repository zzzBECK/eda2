#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, final_station, most_far = 0;
    cin >> n >> final_station;

    vector<int> first_list(n + 1), second_list(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> first_list[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> second_list[i];
    }

    bool is_possible = false;

    if (first_list[1] == 0) {
        is_possible = false;
    } else if (first_list[1] == 1 && first_list[final_station] == 1) {
        is_possible = true;
    } else if (second_list[final_station] == 0) {
        is_possible = false;
    } else {
        for (int i = final_station + 1; i <= n; i++) {
            if (first_list[i] == 1 && second_list[i] == 1) {
                is_possible = true;
                break;
            }
        }
    }

    cout << (is_possible ? "YES\n" : "NO\n");

    return 0;
}