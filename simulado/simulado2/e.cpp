#include <iostream>
#include <vector>

using namespace std;

const long long oo = 1e10;

class SegmentTree {
   private:
    vector<long long> tree;
    int n;

    void build(vector<long long> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return oo;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        long long p1 = query(2 * node, start, mid, l, r);
        long long p2 = query(2 * node + 1, mid + 1, end, l, r);
        return min(p1, p2);
    }

   public:
    SegmentTree(vector<long long> &arr) {
        n = arr.size() - 1;
        tree.resize(4 * n);
        build(arr, 1, 1, n);
    }

    long long query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, t;
    cin >> n >> q >> t;

    vector<long long> list(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    SegmentTree st(list);

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        long long min_val = st.query(l, r);

        if (min_val >= t) {
            cout << "Estou pronto, estou pronto, estou pronto!\n";
        } else {
            cout << "Ah, mexilhoes!\n";
        }
    }

    return 0;
}