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

#define int long long

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
bool visited[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        long long n, p;
        cin >> n >> p;
        vector<int> a(n);
        set<pair<int, int>> vals;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            vals.insert({a[i], i});
            visited[i] = false;
        }
        long long sol = 0, comps = n;
        while (!vals.empty()) {
            pair<int, int> cur = *vals.begin();
            if (cur.first >= p) {
                break;
            }
            vals.erase(vals.begin());
            if (visited[cur.second]) {
                continue;
            }
            visited[cur.second] = true;
            for (int i = cur.second - 1; i >= 0; --i) {
                if (a[i] < a[cur.second] || a[i] % a[cur.second] != 0) {
                    break;
                }
                sol += cur.first;
                --comps;
                if (visited[i]) {
                    break;
                }
                visited[i] = true;
            }
            for (int i = cur.second + 1; i < n; ++i) {
                if (a[i] < a[cur.second] || a[i] % a[cur.second] != 0) {
                    break;
                }
                sol += cur.first;
                --comps;
                if (visited[i]) {
                    break;
                }
                visited[i] = true;
            }
        }
        cout << sol + (comps - 1) * p << "\n";
    }
    return 0;
}
