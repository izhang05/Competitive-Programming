#include <bits/stdc++.h>

using namespace std;

const int m = 1e5 + 1, n = 1e4;

int sieve[m];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    for (int i = 2; i < m; ++i) {
        if (!sieve[i]) {
            for (int j = i + i; j < m; j += i) {
                sieve[j] = i;
            }
        }
    }
    indexed_set<pair<int, int>> nums;
    for (int i = 1; i < m; ++i) {
        set<int> p;
        int cur = i;
        while (sieve[cur]) {
            p.insert(sieve[cur]);
            cur /= sieve[cur];
        }
        p.insert(cur);
        int prod = 1;
        for (auto &j: p) {
            prod *= j;
        }
        nums.insert({prod, i});
    }
    cout << nums.find_by_order(n - 1)->second << "\n";
    return 0;
}
