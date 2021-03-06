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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n % k != 0) {
            cout << -1 << "\n";
            continue;
        }
        map<char, int, greater<>> a;
        int needed = 0, last = -1;
        for (int i = 0; i < n; ++i) {
            int remain = n - i;
            ++a[s[i]];
            if (a[s[i]] == 1) {
                needed += k - 1;
            } else {
                --needed;
            }
            a[s[i]] %= k;
            if (needed > remain) {
                --a[s[i]];
                break;
            }
            last = i;
        }
        string sol;
        for (int i = 0; i < last; ++i) {
            sol.push_back(a[i]);
        }
        bool pos = true;
        for (int i = last + 1; i < n; ++i) {
            if (s[i] > a.begin()->first) {
                pos = false;
                break;
            }
        }
        if (pos) {
            sol.push_back(s[last]);
        } else {
            --a[s[last]];
        }
    }
    return 0;
}
