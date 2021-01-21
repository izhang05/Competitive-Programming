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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


void solve() {
    int n, q;
    cin >> n >> q;
    long long sol = 0;
    vector<long long> a(n), pre(n + 1), sum(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum[i + 1] = sum[i];
        pre[i + 1] = pre[i];
        if (i % 2 == 0) {
            sum[i + 1] += a[i];
            pre[i + 1] += (i + 1) * a[i];
        } else {
            sum[i + 1] -= a[i];
            pre[i + 1] -= (i + 1) * a[i];
        }
    }
    char t;
    int b, c;
    for (int i = 0; i < q; ++i) {
        cin >> t >> b >> c;
        if (t == 'Q') {
            long long cur = (pre[c] - pre[b - 1]) - (b - 1) * (sum[c] - sum[b - 1]);
            if (!(b % 2)) {
                cur *= -1;
            }
            sol += cur;
        } else if (t == 'U') {
            a[b - 1] = c;
            for (int j = 0; j < n; ++j) {
                sum[j + 1] = sum[j];
                pre[j + 1] = pre[j];
                if (j % 2 == 0) {
                    sum[j + 1] += a[j];
                    pre[j + 1] += (j + 1) * a[j];
                } else {
                    sum[j + 1] -= a[j];
                    pre[j + 1] -= (j + 1) * a[j];
                }
            }
        } else {
            assert(false);
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
