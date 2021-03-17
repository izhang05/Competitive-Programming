#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

map<int, int> factorize(int x) {
    map<int, int> res;
    while (x % 2 == 0) {
        ++res[2];
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++res[i];
            x /= i;
        }
    }
    if (x != 1) {
        ++res[x];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int sol = 1;
        set<int> seen;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            map<int, int> cur_factor = factorize(a);
            int cur = 1;
            for (auto j : cur_factor) {
                if (j.second % 2 == 1) {
                    cur *= j.first;
                }
            }
            if (seen.find(cur) != seen.end()) {
                ++sol;
                seen.clear();
            }
            seen.insert(cur);
        }

        cout << sol << "\n";
    }
    return 0;
}
