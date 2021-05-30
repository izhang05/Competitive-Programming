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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<char> sol(n, '0');
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                sol[i] = '1';

                if (last == -1) {
                    for (int j = i - 1; j >= i - m && j >= 0; --j) {
                        sol[j] = '1';
                    }
                } else {
                    for (int j = last + 1; j < last + m + 1 && j < i; ++j) {
                        sol[j] = '1';
                    }
                    for (int j = i - 1; j >= i - m && j > last; --j) {
                        sol[j] = '1';
                    }
                    if (last % 2 == i % 2) {
                        sol[(i + last) / 2] = '0';
                    }
                }
                last = i;
            }
        }
        if (last != -1) {
            for (int i = last + 1; i < last + m + 1 && i < n; ++i) {
                sol[i] = '1';
            }
        }
        for (auto &i : sol) {
            cout << i;
        }
        cout << "\n";

    }
    return 0;
}
