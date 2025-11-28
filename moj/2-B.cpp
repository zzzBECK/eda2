#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--){
        int size, sum = 0;
        cin >> size;

        vector<int> first_row;

        first_row.clear();
        first_row.push_back(0);

        string s1;
        cin >> s1;

        string s2;
        cin >> s2;

        for (int i = 1; i <= size; i++){
            first_row.push_back(s1[i-1] - '0');
        }

        for (int i = 1; i <= size; i++) {
            int value = s2[i-1] - '0';

            if (first_row[i] == 0) {
                if (value == 1){
                    sum++;
                }
            }

            if (first_row[i] == 1){
                if (value == 1){
                    if (first_row[i - 1] == 1){
                        sum++;
                        first_row[i - 1] = 0;
                    }
                    else if (i + 1 <= size && first_row[i + 1] == 1) {
                        sum++;
                        first_row[i + 1] = 0;
                    }
                }
            }
        }

        cout << sum << '\n';
    }

    return 0;
}