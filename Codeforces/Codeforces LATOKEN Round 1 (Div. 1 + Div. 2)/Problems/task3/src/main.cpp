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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e5 + 5;
long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}
bool visited[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> loc;
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
            cin >> a[i];
            --a[i];
            loc[a[i]] = i;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            --b[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int orig = i, cur = loc[b[i]];
                while (cur != orig && !visited[cur]) {
                    visited[cur] = true;
                    cur = loc[b[cur]];
                }
                ++cnt;
            }
        }
        cout << binpow(2, cnt, mod) << "\n";
    }
    return 0;
}
