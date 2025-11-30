#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BITree {
   private:
    vector<T> ts;
    size_t N;

    int LSB(int n) {
        return n & (-n);
    }

    T RSQ(int i) {
        T sum = 0;
        while (i >= 1) {
            sum += ts[i];
            i -= LSB(i);
        }
        return sum;
    }

   public:
    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    T RSQ(int i, int j) {
        return RSQ(j) - RSQ(i - 1);
    }

    void update(int i, T delta) {
        while (i <= N) {
            ts[i] += delta;
            i += LSB(i);
        }
    }
};