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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

int dp[maxn];


int main() {
    setIO();

    int n, k, p;
    cin >> n >> k >> p;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    dp[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i + 1].first - a[i].first <= k) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = i;
        }
    }
    map<int, int> ind;
    for (int i = 0; i < n; ++i) {
        ind[a[i].second] = i;
    }
    int b, c;
    for (int i = 0; i < p; ++i) {
        cin >> b >> c;
        --b, --c;
        b = ind[b], c = ind[c];
        if (b > c) {
            swap(b, c);
        }
        cout << (dp[b] >= c ? "Yes" : "No") << "\n";
    }
    return 0;
}
